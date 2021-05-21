#include "Item.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Item::Item(string id, string title, string rentalType, string loanType, int numberOfCopies, int availableCopies, float rentalFee, string rentalStatus) {
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->numberOfCopies = numberOfCopies;
    this->availableCopies = availableCopies;
    this->rentalFee = rentalFee;
    this->rentalStatus = rentalStatus;
}
Item::Item(string id, string title, string rentalType, string loanType, int numberOfCopies, float rentalFee) {
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->numberOfCopies = numberOfCopies;
    this->availableCopies = numberOfCopies;
    this->rentalFee = rentalFee;
    this->rentalStatus = "Available";
}
Item::Item() {}
bool Item::isNumber(string input) {
    for (char const& c : input) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
string Item::GetId() { return id; }
string Item::GetTitle() { return title; }
string Item::GetRentalType() { return rentalType; }
string Item::GetLoanType() { return loanType; }
int Item::GetNumberOfCopies() { return numberOfCopies; }
int Item::GetAvailableCopies() { return availableCopies;  }
float Item::GetRentalFee() { return rentalFee; }
string Item::GetRentalStatus() { return rentalStatus; }

void Item::SetId() {
    string input;
    do {
        cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
        cin >> input;
        if (!Item::CheckId(input))
            cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try again" << endl;
    } while (!Item::CheckId(input));
    id = input;
}
void Item::SetTitle() {
    cin.ignore();
    cout << "Title of the item: ";
    getline(cin, title);
}
void Item::SetRentalType(int type) {
    switch (type) {
    case 1:
        rentalType = "Game";
        break;
    case 2:
        rentalType = "DVD";
        break;
    case 3:
        rentalType = "Record";
        break;
    }
}
void Item::SetLoanType() {
    string input;
    do {
        cout << "Select the loan type: (1. 2-day, 2. 1-week): ";
        cin >> input;
        if (!(input == "1" || input == "2"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2"));
    loanType = input == "1" ? "2-day" : "1-week";
}
void Item::SetNumberOfCopies(bool newItem) {
    if (newItem == true) {
        cout << "Enter number of copies of new item: " << endl;
        cin >> numberOfCopies;
    }
    else {
        int newAvailableCopies, newNumberOfCopies;
        string input;
        do {
            newAvailableCopies = availableCopies;
            cout << "Enter new number of copies: ";
            cin >> input;
            if (isNumber(input)) {
                newNumberOfCopies = stoi(input);
                newAvailableCopies = availableCopies + newNumberOfCopies - numberOfCopies;
                cout << "number of copies: " << numberOfCopies << endl;
                cout << "available copies: " << availableCopies << endl;
            }
            else {
                cout << "Number of copies Must be a number" << endl;
            }
            if (newAvailableCopies < 0)
                cout << "new number of copies cannot be less than " << numberOfCopies - availableCopies << " which is the copies rented out" << endl;
        } while (newAvailableCopies < 0);
        numberOfCopies = newNumberOfCopies;
    }
}
void Item::SetAvailableCopies(bool isLendingTo) {
    if (isLendingTo == true) {
        availableCopies = availableCopies - 1;
        if (availableCopies == 0) rentalStatus = true;
    } else {
        int newAvailableCopies;
        do {
            cout << "Enter new available copies: ";
            string input;
            cin >> input;
            if (isNumber(input)) {
                newAvailableCopies = stoi(input);
                if (newAvailableCopies > numberOfCopies) {
                    cout << "Available copies cannot be greater than number of copies";
                }
            }
            else {
                cout << "Available copies Must be a number" << endl;
            }
        } while (newAvailableCopies > numberOfCopies);
        availableCopies = newAvailableCopies;
    }
}
void Item::SetRentalFee() {
    // Add condition to check real number
    cout << "Rental fee: ";
    string input;
    cin >> input;
    if (isNumber(input)) {
        rentalFee = stof(input);
    } else {
        cout << "Rental fee must be a number" << endl;
    }
}
void Item::SetRentalStatus() {
    string input;
    do {
        cout << "Select rental status: (1. Borrowed, 2. Available): ";
        cin >> input;
        if (!(input == "1" || input == "2"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2"));
    rentalStatus = input == "1" ? "Borrowed" : "Available";
}
void Item::updateValueAfterRenting() {
    availableCopies--;
    if (availableCopies == 0) {
        rentalStatus = "Borrowed";
    }
}
void Item::updateValueAfterReturning() {
    if (availableCopies == 0) {
        rentalStatus = "Available";
    }
    availableCopies++;
}
string Item::ToString() {
    stringstream ss;
    ss << rentalFee;
    string result = id + "," + title + "," + rentalType + "," + loanType + "," + to_string(numberOfCopies) + "," + ss.str() + rentalStatus;
    return result;
}
bool Item::CheckId(string input) {
    if (input.length() != 9) return false;
    for (size_t i = 0; i < input.length(); i++) {
        if (i == 0) {
            if (input[i] == 'I')
            continue;
        else
            return false;
        }
        if (i < 4) {
            if (input[i] >= '0' && input[i] <= '9')
            continue;
        else
            return false;
        }
        if (i == 4) {
            if (input[i] == '-')
            continue;
        else
            return false;
        }
        if (i > 4) {
            if (input[i] >= '0' && input[i] <= '9')
            continue;
        else
            return false;
        }
    }
    return true;
}
