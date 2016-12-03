/* Contains pin definitions for bit-specific addressing and easier initialization
 * Author: Justin Nguyen and Trevor Murdock
 * Created: 10/25/2016
 */

#ifndef INIT_H
#define INIT_H

#define PIN0  0x01
#define PIN1  0x02
#define PIN2  0x04
#define PIN3  0x08
#define PIN4  0x10
#define PIN5  0x20
#define PIN6  0x40
#define PIN7  0x80

#define LEFTSWITCH  (*((volatile uint32_t *)0x40025040))
#define RIGHTSWITCH (*((volatile uint32_t *)0x40025004))

#define PA0   (*((volatile uint32_t *)0x40004004))
#define PA1   (*((volatile uint32_t *)0x40004008))
#define PA2   (*((volatile uint32_t *)0x40004010))
#define PA3   (*((volatile uint32_t *)0x40004020))
#define PA4   (*((volatile uint32_t *)0x40004040))
#define PA5   (*((volatile uint32_t *)0x40004080))
#define PA6   (*((volatile uint32_t *)0x40004100))
#define PA7   (*((volatile uint32_t *)0x40004200))
  
#define PB0   (*((volatile uint32_t *)0x40005004))
#define PB1   (*((volatile uint32_t *)0x40005008))
#define PB2   (*((volatile uint32_t *)0x40005010))
#define PB3   (*((volatile uint32_t *)0x40005020))
#define PB4   (*((volatile uint32_t *)0x40005040))
#define PB5   (*((volatile uint32_t *)0x40005080))
#define PB6   (*((volatile uint32_t *)0x40005100))
#define PB7   (*((volatile uint32_t *)0x40005200))
  
//#define PC0   (*((volatile uint32_t *)0x40006004))
//#define PC1   (*((volatile uint32_t *)0x40006008))
//#define PC2   (*((volatile uint32_t *)0x40006010))
//#define PC3   (*((volatile uint32_t *)0x40006020))
#define PC4   (*((volatile uint32_t *)0x40006040))
#define PC5   (*((volatile uint32_t *)0x40006080))
#define PC6   (*((volatile uint32_t *)0x40006100))
#define PC7   (*((volatile uint32_t *)0x40006200))
  
#define PD0   (*((volatile uint32_t *)0x40007004))
#define PD1   (*((volatile uint32_t *)0x40007008))
#define PD2   (*((volatile uint32_t *)0x40007010))
#define PD3   (*((volatile uint32_t *)0x40007020))
#define PD4   (*((volatile uint32_t *)0x40007040))
#define PD5   (*((volatile uint32_t *)0x40007080))
#define PD6   (*((volatile uint32_t *)0x40007100))
#define PD7   (*((volatile uint32_t *)0x40007200))
  
#define PE0   (*((volatile uint32_t *)0x40024004))
#define PE1   (*((volatile uint32_t *)0x40024008))
#define PE2   (*((volatile uint32_t *)0x40024010))
#define PE3   (*((volatile uint32_t *)0x40024020))
#define PE4   (*((volatile uint32_t *)0x40024040))
#define PE5   (*((volatile uint32_t *)0x40024080))

#define PF0   (*((volatile uint32_t *)0x40025004))
#define PF1   (*((volatile uint32_t *)0x40025008))
#define PF2   (*((volatile uint32_t *)0x40025010))
#define PF3   (*((volatile uint32_t *)0x40025020))
#define PF4   (*((volatile uint32_t *)0x40025040))
  
void PortA_Init(void);
void PortB_Init(void);
void PortC_Init(void);
void PortD_Init(void);
void PortE_Init(void);
void PortF_Init(void);
  
#endif
