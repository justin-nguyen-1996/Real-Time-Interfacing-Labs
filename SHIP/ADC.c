// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Last Modified: TODAY
// Student names: Trevor & Neil
// Last modification date: TODAY

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ExternVariables.h" 

Vector CrappyHardwareGlitch;

// ADC initialization function 
// Input: none
// Output: none

void ADC_Init(void){ 

	SYSCTL_RCGC2_R |=0x32 ;
	while((SYSCTL_RCGC2_R&0x10)==0){};
	GPIO_PORTE_DIR_R &= ~(0x1F);
	GPIO_PORTE_AFSEL_R |= 0xF;
	GPIO_PORTE_DEN_R &= ~(0xF);
	GPIO_PORTE_DEN_R |= 0x10;			//also enable pin 4 for button
	GPIO_PORTE_AMSEL_R |= 0xF;
	
	GPIO_PORTF_DIR_R |=0x2;	//Heartbeat
	GPIO_PORTF_DEN_R |=0x2;
		
	SYSCTL_RCGCADC_R |= 0x1;								//ADC CLOCK
	while((SYSCTL_RCGCADC_R&0x1)==0){};			
	ADC0_PC_R = 0x1;										//ADC0 CLOCK SPEED
	while((ADC0_PC_R&0x1)==0){};
	ADC0_ACTSS_R &= ~(0x4);									//DISABLE 2
	ADC0_SSPRI_R = 0x0123;									//SEQUENCER PRIORITY
	ADC0_EMUX_R &= ~(0x0F00);								//ACTIVATE BY SOFTWARE
		
	ADC0_SSMUX2_R = 0x3210;				//AIN 0, PE3	
	ADC0_SSCTL2_R = 0x6000;	//SET INR2 WHEN ALL 4 READ
		
	ADC0_IM_R &= ~(0xF);	//DISABLE INTERRUPTS
	ADC0_ACTSS_R |= 0x4;	//ENABLE ADC0
	
}

//------------ADC_In(N)------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion, ADC0, SEQUENCER (N)
uint32_t ADC_In(int *x0,int *y0,int *x1,int *y1){  
	int result;
	ADC0_PSSI_R= 0x4;
	while((ADC0_RIS_R & 0x4)==0){};
		
	*x0 = (ADC0_SSFIFO2_R & 0xFFF);
	*y0 = (ADC0_SSFIFO2_R & 0xFFF);
	*x1 = (ADC0_SSFIFO2_R & 0xFFF);
	*y1 = (ADC0_SSFIFO2_R & 0xFFF);
	
	ADC0_ISC_R = 0x4;
	return result;
}

//---------------------------------------
//Takes 3 ADC_In's and averages them
void AverageADCIn(void){
		ADC_In(&ADCAveraging[0].x,&ADCAveraging[0].y,&ADCAveraging[1].x,&ADCAveraging[1].y); //passing by reference
		ADC_In(&ADCAveraging[2].x,&ADCAveraging[2].y,&ADCAveraging[3].x,&ADCAveraging[3].y);
		ADC_In(&ADCAveraging[4].x,&ADCAveraging[4].y,&ADCAveraging[5].x,&ADCAveraging[5].y);
		PositionStick[0].x = (ADCAveraging[0].x + ADCAveraging[2].x + ADCAveraging[4].x)/3;
		PositionStick[0].y = (ADCAveraging[0].y + ADCAveraging[2].y + ADCAveraging[4].y)/3;
		PositionStick[1].x = (ADCAveraging[1].x + ADCAveraging[3].x + ADCAveraging[5].x)/3;
		PositionStick[1].y = (ADCAveraging[1].y + ADCAveraging[3].y + ADCAveraging[5].y)/3;
}
	// Converts Raw Thumstick[1] input to PositionReal for bitmap output and to VelocityGrid
void ConvertRawADC(void){
		if(PositionStick[1].x >1700){
			if(PositionStick[1].x >2400){
				PositionReal[1].x = 3;}
			else{PositionReal[1].x = 2;
			}
		}
		else{PositionReal[1].x = 1;
		}
		
		if(PositionStick[1].y >1500){
			if(PositionStick[1].y >2200){
				PositionReal[1].y = 5;
			}
			else{PositionReal[1].y = 4;
			}
		}
		else{PositionReal[1].y = 1;
		}
		
		Grid.Velocity.x = (PositionStick[1].x-1900)/6; //max velocity 2 pixels/tick
		Grid.Velocity.y = (PositionStick[1].y-1900)/6;
		
		if(PositionStick[0].x<100){PositionStick[0].x = CrappyHardwareGlitch.x;}
		else{CrappyHardwareGlitch.x = PositionStick[0].x;}
		if(PositionStick[0].y<100){PositionStick[0].y = CrappyHardwareGlitch.y;}
		else{CrappyHardwareGlitch.y = PositionStick[0].y;}
			
		if(PositionStick[0].x>1700){						//Determine if we are shooting
			if(PositionStick[0].x<2400){
				if(PositionStick[0].y>1500){
					if(PositionStick[0].y<2200){Shooting = FALSE;}
					else{Shooting = TRUE;}
				}
				else{Shooting = TRUE;}
			}
			else{Shooting = TRUE;}
		}
		else{Shooting = TRUE;}
		if(Shooting == TRUE){
			PositionReal[0].x = PositionStick[0].x - 1900;
			PositionReal[0].y = PositionStick[0].y - 1900;
			
			NormalSquare = (PositionReal[0].x*PositionReal[0].x + PositionReal[0].y*PositionReal[0].y);
			NormalShootingVelocity.x = (PositionReal[0].x*100)/SquareRootTable[NormalSquare/10000];
			NormalShootingVelocity.y = (PositionReal[0].y*100)/SquareRootTable[NormalSquare/10000];
		}
			
		
}