#include "Shop.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Shop::Shop() {}

void Shop::AddItem(int type) {
	if (type == 1) {
		Item videoGame;
		videoGame.SetId();
		videoGame.SetTitle();
		videoGame.SetRentalType(type);
		videoGame.SetLoanType();
		videoGame.SetNumberOfCopies();
		videoGame.SetRentalFee();
		videoGame.SetRentalStatus();
		listOfVideoGames.push_back(videoGame);
	}
	else {
		SpecialItem item;
		item.SetId();
		item.SetTitle();
		item.SetRentalType(type);
		item.SetLoanType();
		item.SetNumberOfCopies();
		item.SetRentalFee();
		item.SetRentalStatus();
		item.SetGenre();
		type == 2 ? listOfDVDs.push_back(item) : listOfRecords.push_back(item);
	}
}

void Shop::DisplayItemInfo(Item item, int position) {
	cout << position << ". " << "ID: " << item.GetId() << ", Title: " << item.GetTitle() << ", Rental type: " << item.GetRentalType() << ", Loan type: " << item.GetLoanType() << ", Number of copies: " << item.GetNumberOfCopies() << ", Rental fee: " << item.GetRentalFee() << ", Rental status: " << item.GetRentalStatus() << endl;
}

void Shop::DisplayItemInfo(SpecialItem specialItem, int position) {
	cout << position << ". " << "ID: " << specialItem.GetId() << ", Title: " << specialItem.GetTitle() << ", Rental type: " << specialItem.GetRentalType() << ", Loan type: " << specialItem.GetLoanType() << ", Number of copies: " << specialItem.GetNumberOfCopies() << ", Rental fee: " << specialItem.GetRentalFee() << ", Rental status: " << specialItem.GetRentalStatus() << ", Genre: " << specialItem.GetGenre() << endl;
}

bool Shop::IsItemListEmpty() {
	if (listOfVideoGames.size() == 0 && listOfDVDs.size() == 0 && listOfRecords.size() == 0) {
		cout << "There is no item in the shop" << endl;
		return true;
	}
	return false;
}

bool Shop::IsItemListEmpty(int type) {
	if (type == 1) {
		if (listOfVideoGames.size() == 0) {
			cout << "There is no video game in the shop" << endl;
			return true;
		}
	}
	if (type == 2) {
		if (listOfDVDs.size() == 0) {
			cout << "There is no DVD in the shop" << endl;
			return true;
		}
	}
	if (type == 3) {
		if (listOfRecords.size() == 0) {
			cout << "There is no movie record in the shop" << endl;
			return true;
		}
	}
	return false;
}

void Shop::ShowVideoGames() {
	if (!IsItemListEmpty(1)) {
		for (size_t i = 0; i < listOfVideoGames.size(); i++)
		{
			cout << "Video Games: " << endl;
			DisplayItemInfo(listOfVideoGames[i], i + 1);
		}
	}
}

void Shop::ShowDVDs() {
	if (!IsItemListEmpty(2)) {
		for (size_t i = 0; i < listOfDVDs.size(); i++)
		{
			cout << "DVDs: " << endl;
			DisplayItemInfo(listOfDVDs[i], i + 1);
		}
	}
}

void Shop::ShowRecords() {
	if (!IsItemListEmpty(3)) {
		for (size_t i = 0; i < listOfRecords.size(); i++)
		{
			cout << "Movie Record: " << endl;
			DisplayItemInfo(listOfRecords[i], i + 1);
		}
	}
}

void Shop::ShowAllItems() {
	if (!IsItemListEmpty()) {
		ShowVideoGames();
		ShowDVDs();
		ShowRecords();
	}
}

void Shop::UpdateItem(int type) {
	int index;
	if (type == 1) {
		if(!IsItemListEmpty(1)) {
			ShowVideoGames();
			if (listOfVideoGames.size() == 0) return;
			do {
				cout << "Select an item's number to update: ";
				cin >> index;
				if (!(index >= 1 && index <= listOfVideoGames.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfVideoGames.size()));
			index--;
			listOfVideoGames[index].SetTitle();
			listOfVideoGames[index].SetLoanType();
			listOfVideoGames[index].SetNumberOfCopies();
			listOfVideoGames[index].SetRentalFee();
			listOfVideoGames[index].SetRentalStatus();
		}
	}
	else if (type == 2) {
		if (!IsItemListEmpty(2)) {
			ShowDVDs();
			do {
				cout << "Select an item's number to update: ";
				cin >> index;
				if (!(index >= 1 && index <= listOfDVDs.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfDVDs.size()));
			index--;
			listOfDVDs[index].SetTitle();
			listOfDVDs[index].SetLoanType();
			listOfDVDs[index].SetNumberOfCopies();
			listOfDVDs[index].SetRentalFee();
			listOfDVDs[index].SetRentalStatus();
			listOfDVDs[index].SetGenre();
		}
	}
	else if (type == 3) {
		if (!IsItemListEmpty(3)) {
			ShowRecords();
			do {
				cout << "Select an item's number to update: ";
				cin >> index;
				if (!(index >= 1 && index <= listOfRecords.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfRecords.size()));
			index--;
			listOfRecords[index].SetTitle();
			listOfRecords[index].SetLoanType();
			listOfRecords[index].SetNumberOfCopies();
			listOfRecords[index].SetRentalFee();
			listOfRecords[index].SetRentalStatus();
			listOfRecords[index].SetGenre();
		}
	}
}

void Shop::DeleteItem(int type) {
	int index;
	if (type == 1) {
		if (!IsItemListEmpty(1)) {
			ShowVideoGames();
			do {
				cout << "Select an item's number to delete: ";
				cin >> index;
				// Check make sure input is int (exception)
				if (!(index >= 1 && index <= listOfVideoGames.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfVideoGames.size()));
			index--;
			listOfVideoGames.erase(listOfVideoGames.begin() + index);
		}
	}
	else if (type == 2) {
		if (!IsItemListEmpty(2)) {
			ShowDVDs();
			do {
				cout << "Select an item's number to delete: ";
				cin >> index;
				// Check make sure input is int (exception)
				if (!(index >= 1 && index <= listOfDVDs.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfDVDs.size()));
			index--;
			listOfDVDs.erase(listOfDVDs.begin() + index);
		}
	}
	else if (type == 3) {
		if (!IsItemListEmpty(3)) {
			ShowRecords();
			do {
				cout << "Select an item's number to delete: ";
				cin >> index;
				// Check make sure input is int (exception)
				if (!(index >= 1 && index <= listOfRecords.size())) cout << "Invalid option. Try again" << endl;
			} while (!(index >= 1 && index <= listOfRecords.size()));
			index--;
			listOfRecords.erase(listOfRecords.begin() + index);
		}
	}
}

void Shop::DisplayUserInfo(User user, int position) {
	cout << position << ". ID: " << user.GetId() << ", Name: " << user.GetName() << ", Address: " << user.GetAddress() << ", Phone: " << user.GetPhone() << ", Role: " << user.GetRole() << endl;
}

bool Shop::IsUserListEmpty() {
	if (listOfUsers.size() == 0) {
		cout << "No users available" << endl;
		return true;
	}
	return false;
}



void Shop::AddUser() {
	User user;
	user.SetId();
	user.SetName();
	user.SetAddress();
	user.SetPhone();
	user.SetRole();
	listOfUsers.push_back(user);
}

void Shop::ShowAllUsers() {
	if (IsUserListEmpty()) {
		for (size_t i = 0; i < listOfUsers.size(); i++)
		{
			DisplayUserInfo(listOfUsers[i], i + 1);
		}
	}
}

void Shop::UpdateUser() {
	int index;
	if (!IsUserListEmpty()) {
		do {
			cout << "Select a user to update: ";
			cin >> index;
			if (!(index >= 1 && index <= listOfUsers.size())) cout << "Invalid option. Try again" << endl;
		} while (!(index >= 1 && index <= listOfUsers.size()));
		index--;
		listOfUsers[index].SetName();
		listOfUsers[index].SetAddress();
		listOfUsers[index].SetPhone();
	}
}

void Shop::ShowAllUsers(int type) {
	string role;
	int count = 0;
	if (type == 1) {
		role = "Guest";
		cout << "Guest Role: " << endl;
	} 
	if (type == 2) {
		role = "Regular";
		if (type == 2) cout << "Regular Role: " << endl;
	} 
	if (type == 3) {
		role = "VIP";
		cout << "VIP Role: " << endl;
	} 
	if (!IsUserListEmpty()) {
		for (size_t i = 0; i < listOfUsers.size(); i++)
		{
			if (listOfUsers[i].GetRole() == role)
				cout << ++count << ". ID: " << listOfUsers[i].GetId() << ", Name: " << listOfUsers[i].GetName() << ", Address: " << listOfUsers[i].GetAddress() << ", Phone: " << listOfUsers[i].GetPhone() << endl;
		}
	}
}

