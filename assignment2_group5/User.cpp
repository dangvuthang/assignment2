#include "User.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

User::User() {
  this->numberOfItemReturned = 0;
  this->rewardPointForVIP = 0;
}
User::User(string id, string name, string address, string phone, string role,
           int numberOfItemReturned, int rewardPointForVIP, vector<string> listOfRentals) {
  this->id = id;
  this->name = name;
  this->address = address;
  this->phone = phone;
  this->role = role;
  this->numberOfItemReturned = numberOfItemReturned;
  this->listOfRentals = listOfRentals;
  // Add more field include it when save, and read. Tks you
  this->rewardPointForVIP = rewardPointForVIP;
}
string User::GetId() { return id; }
string User::GetName() { return name; }
string User::GetAddress() { return address; }
string User::GetPhone() { return phone; }
string User::GetRole() { return role; }
int User::GetRewardPointForVIP() { return rewardPointForVIP; }
int User::GetNumberOfItemReturned() { return numberOfItemReturned; }
vector<string> User::GetListOfRentals() { return listOfRentals; }
void User::SetId() {
  string input;
  do {
    cout << "Id (Format: Cxxx (x is a number)): ";
    cin >> input;
    if (!User::CheckId(input))
      cout << "Invalid format. Format: Cxxx (x is a number). Try again" << endl;
  } while (!User::CheckId(input));
  this->id = input;
}
void User::SetName() {
  cin.ignore();
  cout << "User's name: ";
  getline(cin, this->name);
}
void User::SetAddress() {
  cout << "Address: ";
  getline(cin, this->address);
}
void User::SetPhone() {
  cout << "Phone: ";
  cin >> this->phone;
}
void User::SetRole() {
  string input;
  do {
    cout << "Select user's account type: (1. Guest, 2. Regular, 3. VIP): ";
    cin >> input;
    if (!(input == "1" || input == "2" || input == "3"))
      cout << "Invalid option. Try again" << endl;
  } while (!(input == "1" || input == "2" || input == "3"));
  if (input == "1") this->role = "Guest";
  if (input == "2") this->role = "Regular";
  if (input == "3") this->role = "VIP";
}

void User::SetRole(string role) { this->role = role; }

void User::AddRental(string itemId) { this->listOfRentals.push_back(itemId); }

bool User::CheckId(string input) {
  if (input.length() != 4) return false;
  for (size_t i = 0; i < input.length(); i++) {
    if (i == 0) {
      if (input[i] == 'C')
        continue;
      else
        return false;
    }
    if (i > 0) {
      if (input[i] >= '0' && input[i] <= '9')
        continue;
      else
        return false;
    }
  }
  return true;
}

string User::ReturnRental(int index) {
  string itemId = listOfRentals[index];
  listOfRentals.erase(listOfRentals.begin() + index);
  this->numberOfItemReturned++;
  return itemId;
}

void User::UpdateRewardPointForVIP() {
  if (role != "VIP") {
    cout << "Only VIP can have reward point" << endl;
    return;
  }
  rewardPointForVIP += 10;
}

void User::UpdateRewardPointForVIP(bool usePointToBorrow) {
  if (usePointToBorrow) {
    if (role != "VIP") {
      cout << "Only VIP can have reward point " << endl;
      return;
    }
    rewardPointForVIP -= 100;
  } else
    this->UpdateRewardPointForVIP();
}