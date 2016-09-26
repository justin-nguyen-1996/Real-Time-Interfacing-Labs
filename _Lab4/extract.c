#include <stdint.h>
#include <string.h>
#include "extract.h"

#define VALUE_FIXED_LENGTH 5

void extractTemperature(char* tempCharBuffer, char* Recvbuff) {
  const char temp[] = "temp";
  const char quoteConst[] = "\"";
  const char equalsConst[] = " = ";
  const char colonConst[] = ":";
  const char commaConst[] = ",";
  
  char labelToExtractWithQuotes[32] = "";
  strcat (labelToExtractWithQuotes, quoteConst);
  strcat (labelToExtractWithQuotes, temp);
  strcat (labelToExtractWithQuotes, quoteConst);
  
  char* start = strstr( Recvbuff, labelToExtractWithQuotes );
  char* colon = strstr( start, colonConst );
  char* comma = strstr( start, commaConst );
  
  uint32_t labelLength = ((uint32_t) colon - (uint32_t) start) / sizeof(char) - 2; // minus two to back up over colon and quote
  uint32_t valueLength = ((uint32_t) comma - (uint32_t) colon) / sizeof(char) - 1; // minus one to back up over comma
  
  strcat( tempCharBuffer, quoteConst );
  strcat( tempCharBuffer, temp);
  strcat( tempCharBuffer, equalsConst );
  strncat( tempCharBuffer, colon+1, valueLength);
  strcat (tempCharBuffer, quoteConst);
  
  //if (valueLength > 5) { strncat( tempCharBuffer, colon+1, 5); }
  //else { strncat( tempCharBuffer, colon+1, valueLength); } //skip the colon
}


	

