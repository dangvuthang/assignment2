#pragma once
#include <iostream>
#include <string>

#include "Item.h"
using namespace std;
class SpecialItem : public Item {
    private:
    string genre;
    public:
    SpecialItem(string id, string title, string rentalType, string loanType, int numberOfCopies, int availableCopies, float rentalFee, string rentalStatus, string genre);
    SpecialItem(string id, string title, string rentalType, string loanType, int numberOfCopies, float rentalFee, string genre);
    SpecialItem();
    string GetGenre();
    void SetGenre();
    string ToString();
};
