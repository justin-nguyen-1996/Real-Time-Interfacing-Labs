//Settings.h
//Dung Nguyen
//Wally Guzman

// Launchpad or TM4C123
#define LAUNCHPAD 		1

// Client or Server ESP8266 Initialization
#define SERVER 				1
 
// Baudrate for UART connection to ESP8266
#define BAUDRATE 			115200

// ADC Sample Rate in Hz
#define SAMPLERATE		8000

// Return values
#define NORESPONSE		(-1)
#define BADVALUE			(-1)
#define SUCCESS				1
#define FAILURE				0

enum Menu_Status {RX=0, TX, CONNECTED};
	
// Access Point Parameters
//#define SSID  		 		"AI-THINKER_E465C7"
//#define PASSKEY    		""
#define SSID  		 	"AI-THINKER_DD00AE"
#define PASSKEY    	""
