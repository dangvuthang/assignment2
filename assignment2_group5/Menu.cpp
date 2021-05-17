#include "Menu.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::DisplayMainMenu() {
    cout << "------------------------------" << endl;
    cout << "Welcome to Genie video store" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add a new item, update or delete an existing item" << endl;
    cout << "2. Add new customer or update an existing customer" << endl;
    cout << "3. Promote an existing customer" << endl;
    cout << "4. Rent an item" << endl;
    cout << "5. Return an item" << endl;
    cout << "6. Display all items" << endl;
    cout << "7. Display out-of-stock items" << endl;
    cout << "8. Display all customers" << endl;
    cout << "9. Display group of customers" << endl;
    cout << "10. Search items or customers" << endl;
    cout << "Exit." << endl;
    cout << "------------------------------" << endl;
}
void Menu::DisplayCRUDForItem() {
    cout << "------------------------------" << endl;
    cout << "1. Add new item" << endl;
    cout << "2. Update an item" << endl;
    cout << "3. Delete an item" << endl;
    cout << "4. Back" << endl;
    cout << "------------------------------" << endl;
}

void Menu::DisplayCRUDForUser() {
    cout << "------------------------------" << endl;
    cout << "1. Add new customer" << endl;
    cout << "2. Update a customer" << endl;
    cout << "3. Back" << endl;
    cout << "------------------------------" << endl;
}

void Menu::DisplaySearchMenu() {
    cout << "------------------------------" << endl;
    cout << "1. Search for items" << endl;
    cout << "2. Search for users" << endl;
    cout << "3. Back" << endl;
    cout << "------------------------------" << endl;
}

eRentalType Menu::DisplayTypeOfItem() {
    eRentalType type;
    string input;
    do {
        cout << "Select the type of item: (1. Video Game, 2. DVD, 3. Movie "
            "Record): ";
        cin >> input;
        if (!(input == "1" || input == "2" || input == "3")) {
            cout << "Invalid option. Try again" << endl;
        }
    } while (!(input == "1" || input == "2" || input == "3"));
    if (input == "1") type = game;
    if (input == "2") type = dvd;
    if (input == "3") type = record;
    return type;
}

int Menu::DisplayTypeOfSearch() {
    string type;
    do {
        cout << "Select the type of search (1. By ID, 2. By Name): ";
        cin >> type;
        if (!(type == "1" || type == "2")) {
            cout << "Invalid option. Try again" << endl;
        }
    } while (!(type == "1" || type == "2"));
    return stoi(type);
}
