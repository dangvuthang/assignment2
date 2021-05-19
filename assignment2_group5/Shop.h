#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "SpecialItem.h"
#include "User.h"
#include "SpecialUser.h"

using namespace std;
class Shop {
	private:
		vector<Item> listOfVideoGames;
		vector<SpecialItem> listOfDVDs;
		vector<SpecialItem> listOfRecords;
		vector<User> listOfUsers;
		vector<SpecialUser> listOfSpecialUsers;

		void DisplayItemInfo(Item item, int position);
		void DisplayItemInfo(SpecialItem specialItem, int position);
		bool IsItemListEmpty();
		bool IsItemListEmpty(int type);
		void DisplayUserInfo(User user, int position);
		void DisplayUserInfo(SpecialUser vip, int position);
		bool IsUserListEmpty(int type);
	public:
	Shop();
		void AddItem(int type);
		void ShowAllItems();
		void ShowAllItems(int type);
		void ShowAllOutOfStockItems();
		void UpdateItem(int type);
		void DeleteItem(int type);
		void AddUser();
		void ShowAllUsers();
		int ShowAllUsers(int type);
		void UpdateUser(int type);
		void DeleteUser(int type);
		void PromoteUser();
		int GetItemIndex(int type);
		int GetItemIndex(int type, bool onlyAvailableItem);
		int GetUserIndex(int type);
		int GetUserIndex(bool specialUser);
		void addItemToUserList(bool specialUser,int userIndex, int itemIndex, int type);
		void RentItem(int userType);
		void ReturnItem();
		void SearchForItem(int type);
		void SearchForUser(int type);
		Item* FindItemById(string itemId);
		User* FindUserById(string userId);
};
