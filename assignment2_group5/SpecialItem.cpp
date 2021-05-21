#include "SpecialItem.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Item.h"
using namespace std;
SpecialItem::SpecialItem(string id, string title, string rentalType, string loanType, int numberOfCopies, int availableCopies, float rentalFee, string rentalStatus, string genre)
    : Item(id, title, rentalType, loanType, numberOfCopies, availableCopies, rentalFee, rentalStatus) {
    this->genre = genre;
}
SpecialItem::SpecialItem(string id, string title, string rentalType, string loanType, int numberOfCopies, float rentalFee, string genre)
    : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {
    this->genre = genre;
}
SpecialItem::SpecialItem() : Item() {}

string SpecialItem::GetGenre() { return genre; }
void SpecialItem::SetGenre() {
    string input;
    do {
        cout << "Select genre: (1. Action, 2.Horror, 3.Drama, 4.Comedy): ";
        cin >> input;
        if (!(input == "1" || input == "2" || input == "3" || input == "4"))
            cout << "Invalid option. Try again" << endl;
    } while (!(input == "1" || input == "2" || input == "3" || input == "4"));
    if (input == "1") this->genre = "Action";
    if (input == "2") this->genre = "Horror";
    if (input == "3") this->genre = "Drama";
    if (input == "4") this->genre = "Comedy";
}
string SpecialItem::ToString() {
    stringstream ss;
    ss << GetRentalFee();
    string result = this->GetId()
      + "," + this->GetTitle()
      + "," +this->GetRentalType()
      + "," + this->GetLoanType()
      + "," +to_string(this->GetNumberOfCopies())
      + "," + ss.str() +this->GetRentalStatus() + genre;
    return result;
}
