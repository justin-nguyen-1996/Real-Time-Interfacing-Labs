#include <stdint.h>
#include <string.h>
#include "extract.h"

#define VALUE_FIXED_LENGTH 5

const char * quote = "\"";
const char * equals = " = ";
void extractValue( char * buff, char * labelToExtract, char * value ) 
{
	char * labelToExtractWithQuotes = "";
	labelToExtractWithQuotes = strcat (labelToExtractWithQuotes, quote);
	labelToExtractWithQuotes = strcat (labelToExtractWithQuotes, labelToExtract);
	labelToExtractWithQuotes = strcat (labelToExtractWithQuotes, quote);

	char * start = strstr( buff, labelToExtractWithQuotes );
	char * colon = strchr( start, (int) ":" );
	char * comma = strchr( start, (int) "," );
	uint32_t labelLength = (colon - start) / sizeof(char) - 2; // minus two to back up over colon and quote
	uint32_t valueLength = (comma - colon) / sizeof(char) - 2; // minus two to back up over comma and colon

	strcat( value, quote );
	strcat( value, labelToExtract);
	strcat( value, equals );
	strncat( value, colon+1, VALUE_FIXED_LENGTH); //skip the colon
	strcat (value, quote);
}

	

