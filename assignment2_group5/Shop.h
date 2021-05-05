#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "SpecialItem.h"
#include "User.h"
using namespace std;
class Shop {
	private:
		vector<Item> listOfVideoGames;
		vector<SpecialItem> listOfDVDs;
		vector<SpecialItem> listOfRecords;
		vector<User> listOfUsers;
		void DisplayItemInfo(Item item, int position);
		void DisplayItemInfo(SpecialItem specialItem, int position);
		bool IsItemListEmpty();
		bool IsItemListEmpty(int type);
		void DisplayUserInfo(User user, int position);
		bool IsUserListEmpty();
	public:
		Shop();
		void AddItem(int type);
		void ShowVideoGames();
		void ShowDVDs();
		void ShowRecords();
		void ShowAllItems();
		void UpdateItem(int type);
		void DeleteItem(int type);
		void AddUser();
		void ShowAllUsers();
		void ShowAllUsers(int type);
		void UpdateUser();
};

