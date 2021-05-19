#pragma once
#include <iostream>
#include <string>

#include "Item.h"
using namespace std;
class SpecialItem : public Item {
    private:
    string genre;
    public:
        SpecialItem(string id, string title, string rentalType, string loanType,
        int numberOfCopies, float rentalFee, string rentalStatus, string genre);
        string GetGenre();
        void SetGenre();
        SpecialItem();
        string ToString();
};
