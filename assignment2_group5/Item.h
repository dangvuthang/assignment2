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
    int availableCopies;
    float rentalFee;
    string rentalStatus;

    public:
    Item(string id, string title, string rentalType, string loanType, int numberOfCopies, int availableCopies, float rentalFee, string rentalStatus);
    Item(string id, string title, string rentalType, string loanType, int numberOfCopies, float rentalFee);
    Item();
    bool isNumber(string input);
    string GetId();
    string GetTitle();
    string GetRentalType();
    string GetLoanType();
    int GetNumberOfCopies();
    int GetAvailableCopies();
    float GetRentalFee();
    string GetRentalStatus();
    void SetId();
    void SetTitle();
    void SetRentalType(int type);
    void SetLoanType();
    void SetNumberOfCopies(bool newItem);
    void SetAvailableCopies(bool isLendingTo);
    void updateValueAfterRenting();
    void updateValueAfterReturning();
    void SetRentalFee();
    void SetRentalStatus();
    string ToString();
    static bool CheckId(string input);
};
