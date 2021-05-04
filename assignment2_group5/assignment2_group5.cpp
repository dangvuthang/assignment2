#include <iostream>

#include <string>

#include <vector>

#include <sstream>

#include <../../Menu.h>

#include <../../Item.h>

#include <../../SpecialItem.h>

#include <../../User.h>

#include <../../Shop.h>

using namespace std;

int main() {
	string option;
	Shop shop;
	do {
		Menu::DisplayMainMenu();
		cout << "Enter option: ";
		cin >> option;
		if (option == "1") {
			string optionForItem;
			do {
				Menu::DisplayCRUDForItem();
				cout << "Enter option: ";
				cin >> optionForItem;
				if (optionForItem == "1") {
					int type = Menu::DisplayTypeOfItem();
					shop.AddItem(type);
				}
				else if (optionForItem == "2") {
					int type = Menu::DisplayTypeOfItem();
					shop.UpdateItem(type);
				}
				else if (optionForItem == "3") {
					int type = Menu::DisplayTypeOfItem();
					shop.DeleteItem(type);
				}
			} while (optionForItem != "4");
		}
		else if (option == "2") {
			string optionForUser;
			do {
				Menu::DisplayCRUDForUser();
				cout << "Enter option: ";
				cin >> optionForUser;
				if (optionForUser == "1") {
					shop.AddUser();
				}
				else if (optionForUser == "2") {
					shop.UpdateUser();
				}
			} while (optionForUser != "3");
		}
		else if (option == "6") {
			shop.ShowAllItems();
		}
		else if (option == "8") {
			shop.ShowAllUsers();
		}
		else if (option == "9") {
			shop.ShowAllUsers(1);
			shop.ShowAllUsers(2);
			shop.ShowAllUsers(3);
		}

	} while (option != "Exit");
	return 0;

}