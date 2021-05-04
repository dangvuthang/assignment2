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

void Shop::ShowVideoGames() {
	if (listOfVideoGames.size() == 0) {
		cout << "There is no video game in the shop" << endl;
	}
	else
		for (size_t i = 0; i < listOfVideoGames.size(); i++)
		{
			cout << "Video Games: " << endl;
			cout << i + 1 << ". " << "ID: " << listOfVideoGames[i].GetId() << ", Title: " << listOfVideoGames[i].GetTitle() << ", Rental type: " << listOfVideoGames[i].GetRentalType() << ", Loan type: " << listOfVideoGames[i].GetLoanType() << ", Number of copies: " << listOfVideoGames[i].GetNumberOfCopies() << ", Rental fee: " << listOfVideoGames[i].GetRentalFee() << ", Rental status: " << listOfVideoGames[i].GetRentalStatus() << endl;
		}
}

void Shop::ShowDVDs() {
	if (listOfDVDs.size() == 0) {
		cout << "There is no dvd in the shop" << endl;
	}
	else
		for (size_t i = 0; i < listOfDVDs.size(); i++)
		{
			cout << "DVDs: " << endl;
			cout << i + 1 << ". " << "ID: " << listOfDVDs[i].GetId() << ", Title: " << listOfDVDs[i].GetTitle() << ", Rental type: " << listOfDVDs[i].GetRentalType() << ", Loan type: " << listOfDVDs[i].GetLoanType() << ", Number of copies: " << listOfDVDs[i].GetNumberOfCopies() << ", Rental fee: " << listOfDVDs[i].GetRentalFee() << ", Rental status: " << listOfDVDs[i].GetRentalStatus() << ", Genre: " << listOfDVDs[i].GetGenre() << endl;
		}
}

void Shop::ShowRecords() {
	if (listOfRecords.size() == 0) {
		cout << "There is no movie record in the shop" << endl;
	}
	else
		for (size_t i = 0; i < listOfRecords.size(); i++)
		{
			cout << "Movie Record: " << endl;
			cout << i + 1 << ". " << "ID: " << listOfRecords[i].GetId() << ", Title: " << listOfRecords[i].GetTitle() << ", Rental type: " << listOfRecords[i].GetRentalType() << ", Loan type: " << listOfRecords[i].GetLoanType() << ", Number of copies: " << listOfRecords[i].GetNumberOfCopies() << ", Rental fee: " << listOfRecords[i].GetRentalFee() << ", Rental status: " << listOfRecords[i].GetRentalStatus() << ", Genre: " << listOfRecords[i].GetGenre() << endl;
		}
}

void Shop::ShowAllItems() {
	ShowVideoGames();
	ShowDVDs();
	ShowRecords();
}

void Shop::UpdateItem(int type) {
	int index;
	if (type == 1) {
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
	else if (type == 2) {
		ShowDVDs();
		if (listOfDVDs.size() == 0) return;
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
	else if (type == 3) {
		ShowRecords();
		if (listOfRecords.size() == 0) return;
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

void Shop::DeleteItem(int type) {
	int index;
	if (type == 1) {
		ShowVideoGames();
		if (listOfVideoGames.size() == 0) return;
		do {
			cout << "Select an item's number to update: ";
			cin >> index;
			// Check make sure input is int (exception)
			if (!(index >= 1 && index <= listOfVideoGames.size())) cout << "Invalid option. Try again" << endl;
		} while (!(index >= 1 && index <= listOfVideoGames.size()));
		index--;
		listOfVideoGames.erase(listOfVideoGames.begin() + index);
	}
	else if (type == 2) {
		ShowDVDs();
		if (listOfDVDs.size() == 0) return;
		do {
			cout << "Select an item's number to update: ";
			cin >> index;
			// Check make sure input is int (exception)
			if (!(index >= 1 && index <= listOfDVDs.size())) cout << "Invalid option. Try again" << endl;
		} while (!(index >= 1 && index <= listOfDVDs.size()));
		index--;
		listOfDVDs.erase(listOfDVDs.begin() + index);
	}
	else if (type == 3) {
		ShowRecords();
		if (listOfRecords.size() == 0) return;
		do {
			cout << "Select an item's number to update: ";
			cin >> index;
			// Check make sure input is int (exception)
			if (!(index >= 1 && index <= listOfRecords.size())) cout << "Invalid option. Try again" << endl;
		} while (!(index >= 1 && index <= listOfRecords.size()));
		index--;
		listOfRecords.erase(listOfRecords.begin() + index);
	}
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
	if (listOfUsers.size() == 0) {
		cout << "No users available" << endl;
		return;
	}
	for (size_t i = 0; i < listOfUsers.size(); i++)
	{
		cout << i + 1 << ". ID: " << listOfUsers[i].GetId() << ", Name: " << listOfUsers[i].GetName() << ", Address: " << listOfUsers[i].GetAddress() << ", Phone: " << listOfUsers[i].GetPhone() << ", Role: " << listOfUsers[i].GetRole() << endl;
	}
}

void Shop::UpdateUser() {
	int index;
	ShowAllUsers();
	if (listOfUsers.size() == 0) return;
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

void Shop::ShowAllUsers(int type) {
	string role;
	int count = 0;
	if (type == 1) role = "Guest";
	if (type == 2) role = "Regular";
	if (type == 3) role = "VIP";
	if (listOfUsers.size() == 0) {
		cout << "No users available" << endl;
		return;
	}
	for (size_t i = 0; i < listOfUsers.size(); i++)
	{
		if (i == 0) {
			if (type == 1) cout << "Guest Role: " << endl;
			if (type == 2) cout << "Regular Role: " << endl;
			if (type == 3) cout << "VIP Role: " << endl;
		}
		if (listOfUsers[i].GetRole() == role) 
			cout << ++count  << ". ID: " << listOfUsers[i].GetId() << ", Name: " << listOfUsers[i].GetName() << ", Address: " << listOfUsers[i].GetAddress() << ", Phone: " << listOfUsers[i].GetPhone() << endl;
	}
}

