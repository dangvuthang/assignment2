#include "Item.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Item::Item(string id, string title, eRentalType rentalType, string loanType, int numberOfCopies, float rentalFee) {
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->loanType = loanType;
    this->numberOfCopies = numberOfCopies;
    this->availableCopies = numberOfCopies;
    this->rentalFee = rentalFee;
    this->rentalStatus = false;
}
Item::Item() {}
string Item::GetId() { return this->id; }
string Item::GetTitle() { return this->title; }
eRentalType Item::GetRentalType() { return this->rentalType; }

string Item::GetRentalTypeString() {
    string typeString = "";
    switch (rentalType) {
    case 1:
        typeString = "Game";
        break;
    case 2:
        typeString = "DVD";
        break;
    case 3:
        typeString = "Record";
        break;
    }
    return typeString;
}
string Item::GetLoanType() { return this->loanType; }
int Item::GetNumberOfCopies() { return this->numberOfCopies; }
int Item::GetAvailableCopies() { return this->availableCopies; }
float Item::GetRentalFee() { return this->rentalFee; }
bool Item::GetRentalStatus() { return this->rentalStatus; }
string Item::GetRentalStatusString() {
    string statusString = "";
    if (this->rentalStatus == true) {
        statusString = "Borrowed";
    }
    else {
        statusString = "Available";
    }
    return statusString;
}
void Item::SetId() {
    string input;
    do {
        cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
        cin >> input;
        if (!Item::CheckId(input))
            cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try again" << endl;
    } while (!Item::CheckId(input));
    this->id = input;
}
void Item::SetTitle() {
    cin.ignore();
    cout << "Enter new title of the item: ";
    getline(cin, this->title);
}
void Item::SetRentalType(eRentalType rentalType) {
    this->rentalType = rentalType;
}
void Item::SetLoanType() {
    string input;
    do {
        cout << "Select the loan type: (1. 2-day, 2. 1-week): ";
        cin >> input;
        if (!(input == "1" || input == "2"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2"));
    this->loanType = input == "1" ? "2-day" : "1-week";
}
void Item::SetNumberOfCopies(bool firstTimeCopies) {
    if (firstTimeCopies == true) {
        cout << "Enter number of copies of new item: " << endl;
        cin >> this->numberOfCopies;
    }
    else {
        // Add condition to check whole number
        int newAvailableCopies, newNumberOfCopies;
        do {
            cout << "Enter new number of copies: ";
            newAvailableCopies = this->availableCopies;
            cin >> newNumberOfCopies;
            newAvailableCopies = this->availableCopies + newNumberOfCopies - this->numberOfCopies;
            cout << "number of copies: " << this->numberOfCopies << endl;
            cout << "available copies: " << this->availableCopies << endl;
            if (newAvailableCopies < 0)
                cout << "new number of copies cannot be less than " << this->numberOfCopies - this->availableCopies << " which is the copies rented out" << endl;
        } while (newAvailableCopies < 0);
        this->numberOfCopies = newNumberOfCopies;
    }
}

void Item::SetAvailableCopies(bool isLendingTo) {
    if (isLendingTo == true) {
        this->availableCopies = this->availableCopies - 1;
        if (this->availableCopies == 0) this->rentalStatus = true;
    }
    else {
        int newAvailableCopies;
        do {
            cout << "Enter new available copies: ";
            cin >> newAvailableCopies;
            if (newAvailableCopies > this->numberOfCopies) {
                cout << "Available copies cannot be greater than number of copies";
            }
        } while (newAvailableCopies > this->numberOfCopies);
        this->availableCopies = newAvailableCopies;
    }

}
void Item::SetRentalFee() {
    // Add condition to check real number
    cout << "Enter new rental fee: ";
    cin >> this->rentalFee;
}
void Item::SetRentalStatus() {
    string input;
    do {
        cout << "Select rental status: (1. Borrowed, 2. Available): ";
        cin >> input;
        if (!(input == "1" || input == "2"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2"));
    this->rentalStatus = input == "1" ? true : false;
}
void Item::updateValueAfterReturning() {
    this->availableCopies++;
    this->rentalStatus = "false";
}
string Item::ToString() {
    stringstream ss;
    ss << rentalFee;
    string result = id + "," + title + "," + GetRentalTypeString() + "," + loanType + "," + to_string(numberOfCopies) + "," + ss.str() + GetRentalStatusString();
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
string Item::GetGenreString() {
    //cout << "this item has no genre";
    return "not categorized";
}
void Item::SetGenre() {
    cout << "set genre in Item";
}
