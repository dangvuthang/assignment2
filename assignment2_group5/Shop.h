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
	vector<Item*> listOfItem;

	void DisplayItemInfo(Item* item, int position);
	//void DisplayItemInfo(SpecialItem *specialItem, int position);
	bool IsItemListEmpty();
	bool IsItemListEmpty(eRentalType type);
	void DisplayUserInfo(User user, int position);
	bool IsUserListEmpty();

public:
	Shop();
	void AddItem(eRentalType type);
	void ShowAllItems();
	void ShowAllItems(eRentalType type);
	void ShowAllOutOfStockItems();
	void UpdateItem(eRentalType type);
	void DeleteItem(eRentalType type);
	void AddUser();
	void ShowAllUsers();
	void ShowAllUsers(int type);
	void UpdateUser();
	int GetItemIndex(eRentalType type);
	int GetItemIndex(eRentalType type, bool onlyAvailableItem);
	int GetUserIndex();
	void RentItem(eRentalType type);
	void ReturnItem();
	void SearchForItem(int type);
	void SearchForUser(int type);
	Item* FindItemById(string itemId);
	User* FindUserById(string userId);
	void StockFromStorage(string filename);
};
