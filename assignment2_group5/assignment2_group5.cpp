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
            int type = Menu::DisplayTypeOfUser();
            shop.UpdateUser(type);
        }
        else if (optionForUser == "3") {
            int type = Menu::DisplayTypeOfUser();
            shop.DeleteUser(type);
        }
      } while (optionForUser != "4");
    
    } else if (option == "3") {
        shop.PromoteUser();
    }
    else if (option == "4") {
      int userType = Menu::DisplayTypeOfUser();
      
      shop.RentItem(userType);
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
    } else if (option == "10") {
      string optionForSearch;
      do {
        Menu::DisplaySearchMenu();
        cout << "Enter option: ";
        cin >> optionForSearch;
        if (optionForSearch == "1" || optionForSearch == "2") {
          int typeOfSearch = Menu::DisplayTypeOfSearch();
          if (optionForSearch == "1") shop.SearchForItem(typeOfSearch);
          if (optionForSearch == "2") shop.SearchForUser(typeOfSearch);
        }
      } while (optionForSearch != "3");
    }
  } while (option != "Exit");
  return 0;
}