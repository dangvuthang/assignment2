#include "SpecialUser.h"

SpecialUser::SpecialUser(string id, string name, string address, string phone, string role) : User(id, name, address, phone, role) {
    this->rewardPoint = 0;
}
SpecialUser::SpecialUser(string id, string name, string address, string phone, string role, int numberOfItemReturned, vector<string> listOfRental) 
    : User(id, name, address, phone, role, numberOfItemReturned, listOfRental) {
    this->rewardPoint = 0;
}
SpecialUser::SpecialUser() {}



int SpecialUser::GetRewardPoint() { return rewardPoint; }

void SpecialUser::setRewardPoint() {
    cout << "Enter new reward point: " << endl;
    cin >> this->rewardPoint;
}
void SpecialUser::AddPointOnRent() {
    rewardPoint += 10;
}
void SpecialUser::UsePointForRent() {
    if (rewardPoint >= 100) {
        cout << "used reward point for rent" << endl;
        rewardPoint -= 100;
        cout << "reward point now is: " << rewardPoint << endl;
    }
    else {
        cout << "sorry, you do not have enough reward points" << endl;
    }
}

