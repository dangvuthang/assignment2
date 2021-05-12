#include <../../Item.h>
#include <../../Menu.h>
#include <../../Shop.h>
#include <../../SpecialItem.h>
#include <../../User.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
        } else if (optionForItem == "2") {
          int type = Menu::DisplayTypeOfItem();
          shop.UpdateItem(type);
        } else if (optionForItem == "3") {
          int type = Menu::DisplayTypeOfItem();
          shop.DeleteItem(type);
        }
      } while (optionForItem != "4");
    } else if (option == "2") {
      string optionForUser;
      do {
        Menu::DisplayCRUDForUser();
        cout << "Enter option: ";
        cin >> optionForUser;
        if (optionForUser == "1") {
          shop.AddUser();
        } else if (optionForUser == "2") {
          shop.UpdateUser();
        }
      } while (optionForUser != "3");
    } else if (option == "4") {
      int type = Menu::DisplayTypeOfItem();
      shop.RentItem(type);
    } else if (option == "5") {
      shop.ReturnItem();
    } else if (option == "6") {
      shop.ShowAllItems();
    } else if (option == "7") {
      shop.ShowAllOutOfStockItems();
    } else if (option == "8") {
      shop.ShowAllUsers();
    } else if (option == "9") {
      shop.ShowAllUsers(1);
      shop.ShowAllUsers(2);
      shop.ShowAllUsers(3);
    }

  } while (option != "Exit");
  return 0;
}