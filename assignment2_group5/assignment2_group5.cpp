#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Item.h"
#include "Menu.h"
#include "Shop.h"
#include "SpecialItem.h"
#include "User.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "To run: <program> <item file csv name> <customer csv file name>"
         << endl;
    exit(0);
  }

  string itemFile = argv[1];
  string customerFile = argv[2];
  string option;
  Shop shop;

  cout << "Loading data..." << endl;
  shop.loadItem(itemFile);
  shop.loadUser(customerFile);
  shop.UpdateID();
  cout << "Done." << endl;

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
    } else if (option == "3") {
      int type = Menu::DisplayTypeOfPromotion();
      shop.PromoteAUser(type);
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

  // SAVE
  cout << "Saving data to..." << endl;
  shop.saveItem(itemFile);
  shop.saveUser(customerFile);
  cout << "Done." << endl;

  cout << "ASSIGNMENT 2 GROUP 5" << endl;
  cout << "s3879303@rmit.edu.vn, Thang, Dang" << endl;

  return 0;
}