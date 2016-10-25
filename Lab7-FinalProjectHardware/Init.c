#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Init.h"

void PortA_Init(void){ 
  // see commonInit() in ST7735.c
}

void PortB_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x02;        // activate port B
  while((SYSCTL_PRGPIO_R&0x02)==0){};   // allow time for clock to stabilize
}

void PortC_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x04;        // activate port C
  while((SYSCTL_PRGPIO_R&0x04)==0){};   // allow time for clock to stabilize
}

void PortD_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x08;        // activate port D
  while((SYSCTL_PRGPIO_R&0x08)==0){};   // allow time for clock to stabilize
}

void PortE_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x10;        // activate port E
  while((SYSCTL_PRGPIO_R&0x10)==0){};   // allow time for clock to stabilize
}

void PortF_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x20;        // activate port F
  while((SYSCTL_PRGPIO_R&0x20)==0){};   // allow time for clock to stabilize
}

void Thumbstick_Init(void) {
  SYSCTL_RCGCADC_R |= 0x0001;     // 7) activate ADC0 
  GPIO_PORTD_DIR_R &= ~0x0F;      // 2) make PD 3,2,1,0 input
  GPIO_PORTD_AFSEL_R |= 0x0F;     // 3) enable alternate function on P
  GPIO_PORTD_DEN_R &= ~0x0F;      // 4) disable digital I/O on P
  GPIO_PORTD_AMSEL_R |= 0x0F;     // 5) enable analog functionality on P

  ADC0_PC_R &= ~0xF;              // 7) clear max sample rate field
  ADC0_PC_R |= 0x1;               //    configure for 125K samples/sec
  ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger
  ADC0_SSMUX3_R &= ~0x000F;       // 11) clear SS3 field
  ADC0_SSMUX3_R += 9;             //     set channel
  ADC0_SSCTL3_R = 0x0006;         // 12) no TS0 D0, yes IE0 END0
  ADC0_IM_R &= ~0x0008;           // 13) disable SS3 interrupts
  ADC0_ACTSS_R |= 0x0008;         // 14) enable sample sequencer 3
}

void Accel_Init(void) {
  
}

void Buttons_Init(void) {
  GPIO_PORTD_DIR_R &= ~0xF0;      // 2) make PD 7,6,5,4 input
  GPIO_PORTD_AFSEL_R &= ~0xF0;    // 3) disable alternate function on PD 7,6,5,4
  GPIO_PORTD_DEN_R |= 0xF0;       // 4) enable digital I/O on PD 7,6,5,4
  GPIO_PORTD_AMSEL_R &= ~0xF0;    // 5) disable analog functionality on PD 7,6,5,4
  
  GPIO_PORTE_DIR_R &= ~0x38;      // 2) make PE 5,4,3 input
  GPIO_PORTE_AFSEL_R &= ~0x38;    // 3) disable alternate function on PE 5,4,3
  GPIO_PORTE_DEN_R |= 0x38;       // 4) enable digital I/O on PE 5,4,3
  GPIO_PORTE_AMSEL_R &= ~0x38;    // 5) disable analog functionality on PE 5,4,3
}

void DAC_Init2(void) { // TODO: change back to DAC_Init
  SYSCTL_RCGCSSI_R |= 0x04;         // activate SSI2
  GPIO_PORTB_AMSEL_R &= ~0xFF;      // disable analog functionality on PB7-0
  GPIO_PORTB_DIR_R |= 0x04;         // make PB2 an output pin
  GPIO_PORTB_AFSEL_R |= 0xB0;       // alternate function on PB 7,5,4
  GPIO_PORTB_DEN_R |= 0xB0;         // enable digital I/O on PB 7,5,4
  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0x0F00FFFF) + 0x20220000; // 4) PB 7,5,4 = DAC,SSIO
  
  SSI2_CR1_R = 0x00000000;        // disable SSI, master mode
  SSI2_CPSR_R = 0x04;             // 20 MHz SSIClk 
  SSI2_CR0_R |= 0x04F;            // DSS = 16-bit data, SPO = 1, SPH = 0
  SSI2_CR1_R |= 0x00000002;       // enable SSI
}

// Initialize UART0
// Baud rate is 115200 bits/sec
// TODO: remove the RxFifo_Init and TxFifo_Init function prototypes
  void RxFifo_Init();                        // initialize empty FIFOs
  void TxFifo_Init();
void UART_Init2(void){ // TODO: change back to UART_Init
  GPIO_PORTB_AMSEL_R &= ~0xFF;      // disable analog functionality on PB7-0
  GPIO_PORTB_AFSEL_R |= 0x03;           // enable alt funct on PB 1,0
  GPIO_PORTB_DEN_R |= 0x07;             // enable digital I/O on PB 2,1,0
  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00) + 0x00000011; // PB 1,0 = ESP,UART
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFF00FF)|0x00004000; // bits 13-15, priority 2
  NVIC_EN0_R = 1 << 5;                  // enable interrupt 5 in NVIC

  SYSCTL_RCGCUART_R |= 0x01;            // activate UART0
  RxFifo_Init();                        // initialize empty FIFOs
  TxFifo_Init();
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART0_IBRD_R = 43;                    // IBRD = int(80,000,000 / (16 * 115,200)) = int(43.403)
  UART0_FBRD_R = 26;                    // FBRD = round(0.4028 * 64 ) = 26
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART0_IFLS_R &= ~0x3F;                // clear TX and RX interrupt FIFO level fields
                                        // configure interrupt for TX FIFO <= 1/8 full
                                        // configure interrupt for RX FIFO >= 1/8 full
  UART0_IFLS_R += (UART_IFLS_TX1_8|UART_IFLS_RX1_8);
                                        // enable TX and RX FIFO interrupts and RX time-out interrupt
  UART0_IM_R |= (UART_IM_RXIM|UART_IM_TXIM|UART_IM_RTIM);
  UART0_CTL_R |= 0x301;                 // enable UART
}
