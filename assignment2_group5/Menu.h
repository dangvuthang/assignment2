#pragma once
#include "Item.h"

class Menu {
public:
	static void DisplayMainMenu();
	static void DisplayCRUDForItem();
	static void DisplayCRUDForUser();
	static void DisplaySearchMenu();
	static eRentalType DisplayTypeOfItem();
	static int DisplayTypeOfSearch();
};
