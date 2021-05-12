#include "Item.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Item::Item(string id, string title, string rentalType, string loanType,
           int numberOfCopies, float rentalFee, string rentalStatus) {
  this->id = id;
  this->title = title;
  this->rentalType = rentalType;
  this->loanType = loanType;
  this->numberOfCopies = numberOfCopies;
  this->rentalFee = rentalFee;
  this->rentalStatus = rentalStatus;
}
Item::Item() {}
string Item::GetId() { return id; }
string Item::GetTitle() { return title; }
string Item::GetRentalType() { return rentalType; }
string Item::GetLoanType() { return loanType; }
int Item::GetNumberOfCopies() { return numberOfCopies; }
float Item::GetRentalFee() { return rentalFee; }
string Item::GetRentalStatus() { return rentalStatus; }
void Item::SetId() {
  string input;
  do {
    cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
    cin >> input;
    if (!Item::CheckId(input))
      cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try again"
           << endl;
  } while (!Item::CheckId(input));
  this->id = input;
}
void Item::SetTitle() {
  cin.ignore();
  cout << "Title of the item: ";
  getline(cin, this->title);
}
void Item::SetRentalType(int type) {
  if (type == 1)
    this->rentalType = "Game";
  else if (type == 2)
    this->rentalType = "DVD";
  else if (type == 3)
    this->rentalType = "Record";
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
void Item::SetNumberOfCopies() {
  // Add condition to check whole number
  cout << "Number of copies: ";
  cin >> this->numberOfCopies;
}
void Item::SetNumberOfCopies(bool isLendingTo) {
  if (isLendingTo) {
    this->numberOfCopies = this->numberOfCopies - 1;
    if (this->numberOfCopies == 0) this->rentalStatus = "Borrowed";
  } else
    this->SetNumberOfCopies();
}

void Item::SetRentalFee() {
  // Add condition to check real number
  cout << "Rental fee: ";
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
  this->rentalStatus = input == "1" ? "Borrowed" : "Available";
}
string Item::ToString() {
  stringstream ss;
  ss << rentalFee;
  string result = id + "," + title + "," + rentalType + "," + loanType + "," +
                  to_string(numberOfCopies) + "," + ss.str() + rentalStatus;
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
