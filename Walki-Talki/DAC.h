//DAC.h
//Driver for TLV5616
//Dung Nguyen
//Wally Guzman

//------------DAC_Init------------
// Initialize SSI1 on PD0-3 for TLV5616
// Input: none
// Output: none
void DAC_Init(void);

//------------DAC_Out------------
// Output value to TLV5616
// Input: 12-bit value
// Output: none
void DAC_Out(int value);
