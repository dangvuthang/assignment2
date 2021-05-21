#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User {
 private:
  string id;
  string name;
  string address;
  string phone;
  string role;
  int numberOfItemReturned;
  vector<string> listOfRentals;
  int rewardPointForVIP;

 public:
  User();
  User(string id, string name, string address, string phone, string role,
       int numberOfItemReturned, vector<string> listOfRentals);
  string GetId();
  string GetName();
  string GetAddress();
  string GetPhone();
  string GetRole();
  int GetNumberOfItemReturned();
  int GetRewardPointForVIP();
  vector<string> GetListOfRentals();
  void SetId();
  void SetName();
  void SetAddress();
  void SetPhone();
  void SetRole();
  void SetRole(string role);
  void UpdateRewardPointForVIP();
  void UpdateRewardPointForVIP(bool usePointToBorrow);
  string ReturnRental(int index);
  void AddRental(string itemId);
  static bool CheckId(string input);
};
