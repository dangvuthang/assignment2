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
  vector<string> listOfId;
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
  bool CheckIfUserCanBorrowItem(int itemType, int indexForItem,
                                int indexForUser);

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
  void ShowAllUsers(int type);
  void PromoteAUser(int type);
  void UpdateUser();
  int GetItemIndex(int type);
  int GetItemIndex(int type, bool onlyAvailableItem);
  int GetUserIndex();
  void RentItem(int type);
  void ReturnItem();
  void SearchForItem(int type);
  void SearchForUser(int type);
  Item* FindItemById(string itemId);
  User* FindUserById(string userId);
  void saveItem(string itemFile);
  void saveUser(string userFile);
  void loadItem(string itemFile);
  void loadUser(string userFile);
  void UpdateID();

};
