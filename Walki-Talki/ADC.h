//ADC.h
//Dung Nguyen
//Wally Guzman

//------------ADC_Init------------
// Initialize ADC on PB4 for MAX4466
// Input: none
// Output: none
void ADC_Init(int period);

//------------ADC_GetValue------------
// Get current ADC value from buffer
// Input: none
// Output: 12-bit ADC result
int ADC_GetValue(void);

//------------ADC_PeekValue------------
// Get current ADC value without modifying buffer
// Input: none
// Output: 12-bit ADC result
int ADC_PeekValue(void);

//------------ADC_ResetGet------------
// Reset GetIndex to newest ADC value
// Input: none
// Output: none
void ADC_ResetGet(void);
