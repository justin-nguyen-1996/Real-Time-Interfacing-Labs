#include <stdint.h>
#include <string.h>
#include "extract.h"

/* Summary: parses the data to retrieve the temperature measurement
 * Input:   temperatureString is where we'll put the parsed temperature measurement
 * Output:  Recvbuff is the buffer that we'll be parsing to get our payload
 */
void extractTemperature(char* temperatureString, char* Recvbuff) {
  const char temp[] = "temp";
  const char quoteConst[] = "\"";
  const char equalsConst[] = " = ";
  const char colonConst[] = ":";
  const char commaConst[] = ",";
  
  char labelToExtractWithQuotes[32] = "";
  strcat(labelToExtractWithQuotes, quoteConst);
  strcat(labelToExtractWithQuotes, temp);
  strcat(labelToExtractWithQuotes, quoteConst);
  
  // find where temp, the colon, and the comma are located in the data
  char* start = strstr(Recvbuff, labelToExtractWithQuotes);
  char* colon = strstr(start, colonConst);
  char* comma = strstr(start, commaConst);
  
  // minus two to back up over colon and quote  
  uint32_t labelLength = ((uint32_t) colon - (uint32_t) start) / sizeof(char) - 2;

  // minus one to back up over comma
  uint32_t valueLength = ((uint32_t) comma - (uint32_t) colon) / sizeof(char) - 1;
  
  // format the temperature string and append the temperature value
  strcat(temperatureString, quoteConst);
  strcat(temperatureString, temp);
  strcat(temperatureString, equalsConst);
  strncat(temperatureString, colon+1, valueLength);
  strcat(temperatureString, quoteConst);
}



	

