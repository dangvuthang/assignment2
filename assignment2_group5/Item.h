#pragma once
#include <iostream>
#include <string>
using namespace std;
class Item {
 private:
  string id;
  string title;
  string rentalType;
  string loanType;
  int numberOfCopies;
  float rentalFee;
  string rentalStatus;

 public:
  Item(string id, string title, string rentalType, string loanType,
       int numberOfCopies, float rentalFee, string rentalStatus);
  Item();
  string GetId();
  string GetTitle();
  string GetRentalType();
  string GetLoanType();
  int GetNumberOfCopies();
  float GetRentalFee();
  string GetRentalStatus();
  void SetId();
  void SetTitle();
  void SetRentalType(int type);
  void SetLoanType();
  void SetNumberOfCopies();
  void SetNumberOfCopies(bool isLendingTo);
  void updateValueAfterReturning();
  void SetRentalFee();
  void SetRentalStatus();
  string ToString();
  static bool CheckId(string input);
};
