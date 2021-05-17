#pragma once
#include <iostream>
#include <string>
using namespace std;

enum eRentalType { game = 1, dvd, record };
class Item {
private:
    string id;
    string title;
    eRentalType rentalType;
    string loanType;
    int numberOfCopies;
    int availableCopies;
    float rentalFee;
    bool rentalStatus;

public:
    Item(string id, string title, eRentalType rentalType, string loanType,
        int numberOfCopies, float rentalFee);
    Item();
    string GetId();
    string GetTitle();
    eRentalType GetRentalType();
    string GetRentalTypeString();
    string GetLoanType();
    int GetNumberOfCopies();
    int GetAvailableCopies();
    float GetRentalFee();
    bool GetRentalStatus();
    string GetRentalStatusString();
    void SetId();
    void SetTitle();
    void SetRentalType(eRentalType type);
    void SetLoanType();
    void SetNumberOfCopies();
    void SetNumberOfCopies(bool firstTimeCopies);
    void SetAvailableCopies();
    void SetAvailableCopies(bool isLendingTo);
    void updateValueAfterReturning();
    void SetRentalFee();
    void SetRentalStatus();
    string ToString();
    static bool CheckId(string input);
    virtual string GetGenreString();
};
