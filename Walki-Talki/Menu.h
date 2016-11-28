//Menu.h
//Dung Nguyen
//Wally Guzman

typedef struct menuItem_t { // Represents a menu item
	char *name;
	struct menu_t *nextMenu;
} menuItem_t;

typedef struct menu_t {	// Represents information about a menu item
	int numItems;
	struct menuItem_t *items;
	void(*task)(uint32_t x); 			// onClick Function
} menu_t;

//------------Menu_Init------------
// Initialize menus with menu items and screen
// Changes cursor position
// Input: none
// Output: none
void Menu_Init(void);

//------------Menu_Set------------
// Set current menu and resets cursor position
// Input: none
// Output: none
void Menu_Set(struct menu_t *menu);

//------------Menu_Draw------------
// Display current menu
// Changes cursor position
// Input: none
// Output: none
void Menu_Draw(void);

//------------Menu_Up------------
// Navigate menu on up press
// Changes cursor position
// Input: none
// Output: none
void Menu_Up(void);

//------------Menu_Down------------
// Navigate menu on down press
// Changes cursor position
// Input: none
// Output: none
void Menu_Down(void);

//------------Menu_Back------------
// Navigate menu on back press
// Changes currentMenu
// Input: none
// Output: none
void Menu_Back(void);

//------------Menu_Select------------
// Navigate menu on select press and execute menu function
// Changes currentMenu
// Input: none
// Output: none
void Menu_Select(void);

//------------Menu_SendState------------
// Return voice/tone transmission
// Input: none
// Output: 1 if voice, 0 if tone
int Menu_SendState(void);

//------------Menu_UpdateDACValue------------
// Used for drawing DAC output to display
// Input: none
// Output: none
void Menu_UpdateDACValue(int newDACValue);

//------------Menu_Update------------
// Navigate menu based on switch input
// Input: none
// Output: none
void Menu_Update(void);
