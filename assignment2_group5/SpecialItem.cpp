#include "SpecialItem.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Item.h"
using namespace std;
SpecialItem::SpecialItem(string id, string title, eRentalType rentalType, string loanType, int numberOfCopies, float rentalFee, eGenre genre)
    : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {
    this->genre = genre;
}
eGenre SpecialItem::GetGenre() { return this->genre; }
string SpecialItem::GetGenreString() {
    string genreString = "";
    switch (genre) {
    case 1:
        genreString = "Action";
        break;
    case 2:
        genreString = "Horror";
        break;
    case 3:
        genreString = "Drama";
        break;
    case 4:
        genreString = "Comedy";
        break;
    }
    return genreString;
}
void SpecialItem::SetGenre() {
    string input;
    do {
        cout << "Select genre: (1. Action, 2.Horror, 3.Drama, 4.Comedy): ";
        cin >> input;
        if (!(input == "1" || input == "2" || input == "3" || input == "4"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2" || input == "3" || input == "4"));
    if (input == "1") this->genre = action;
    if (input == "2") this->genre = horror;
    if (input == "3") this->genre = drama;
    if (input == "4") this->genre = comedy;
}

SpecialItem::SpecialItem() : Item() {}

string SpecialItem::ToString() {
    stringstream ss;
    ss << GetRentalFee();

    string result = this->GetId() + "," + this->GetTitle() + "," +
        this->GetRentalTypeString() + "," + this->GetLoanType() + "," +
        to_string(this->GetNumberOfCopies()) + "," + ss.str() +
        this->GetRentalStatusString() + GetGenreString();
    return result;
}
