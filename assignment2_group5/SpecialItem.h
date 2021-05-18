#pragma once
#include <iostream>
#include <string>

#include "Item.h"
using namespace std;
enum eGenre { action = 1, horror, drama, comedy };
class SpecialItem : public Item {
private:
	eGenre genre;

public:
	SpecialItem(string id, string title, eRentalType rentalType, string loanType, int numberOfCopies, float rentalFee, eGenre genre);
	eGenre GetGenre();
	virtual string GetGenreString();
	void SetGenre();
	SpecialItem();
	string ToString();
};
