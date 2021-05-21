#pragma once
#include "User.h"
class SpecialUser : public User {
private:
	int rewardPoint;
public:
	int GetRewardPoint();
	void setRewardPoint();
	SpecialUser(string id, string name, string address, string phone, string role);
	SpecialUser(string id, string name, string address, string phone, string role, int numberOfItemReturned, vector<string> listOfRentals, int rewardPoint);
	SpecialUser();
	void AddPointOnRent();
	void UsePointForRent();
};