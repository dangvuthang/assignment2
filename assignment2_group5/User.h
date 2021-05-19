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

	public:
		User(string id, string name, string address, string phone, string role);
		User();
		string GetId();
		string GetName();
		string GetAddress();
		string GetPhone();
		string GetRole();
		int GetNumberOfItemReturned();
		vector<string> GetListOfRentals();
		void SetId();
		void SetName();
		void SetAddress();
		void SetPhone();
		void SetRole(bool newUser);
		void ReturnRental(int index);
		void AddRental(string itemId);
		static bool CheckId(string input);
};
