#ifndef __extracth
#define __extracth

/* Summary: parses the data to retrieve the temperature measurement
 * Input:   temperatureString is where we'll put the parsed temperature measurement
 * Output:  Recvbuff is the buffer that we'll be parsing to get our payload
 */
void extractTemperature(char* temperatureString, char* Recvbuff);

#endif
