#include "Shop.h"

#include <iostream>
#include <sstream>
#include <string>
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
  } else {
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
  cout << position << ". "
       << "ID: " << item.GetId() << ", Title: " << item.GetTitle()
       << ", Rental type: " << item.GetRentalType()
       << ", Loan type: " << item.GetLoanType()
       << ", Number of copies: " << item.GetNumberOfCopies()
       << ", Rental fee: " << item.GetRentalFee()
       << ", Rental status: " << item.GetRentalStatus() << endl;
}

void Shop::DisplayItemInfo(SpecialItem specialItem, int position) {
  cout << position << ". "
       << "ID: " << specialItem.GetId() << ", Title: " << specialItem.GetTitle()
       << ", Rental type: " << specialItem.GetRentalType()
       << ", Loan type: " << specialItem.GetLoanType()
       << ", Number of copies: " << specialItem.GetNumberOfCopies()
       << ", Rental fee: " << specialItem.GetRentalFee()
       << ", Rental status: " << specialItem.GetRentalStatus()
       << ", Genre: " << specialItem.GetGenre() << endl;
}

bool Shop::IsItemListEmpty() {
  if (listOfVideoGames.size() == 0 && listOfDVDs.size() == 0 &&
      listOfRecords.size() == 0) {
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

void Shop::ShowAllItems() {
  if (!IsItemListEmpty()) {
    ShowAllItems(1);
    ShowAllItems(2);
    ShowAllItems(3);
  }
}

void Shop::ShowAllItems(int type) {
  if (type == 1) {
    if (!IsItemListEmpty(1)) {
      cout << "Video Games: " << endl;
      for (size_t i = 0; i < listOfVideoGames.size(); i++) {
        DisplayItemInfo(listOfVideoGames[i], i + 1);
      }
    }
  }
  if (type == 2) {
    if (!IsItemListEmpty(2)) {
      cout << "DVDs: " << endl;
      for (size_t i = 0; i < listOfDVDs.size(); i++) {
        DisplayItemInfo(listOfDVDs[i], i + 1);
      }
    }
  }
  if (type == 3) {
    if (!IsItemListEmpty(3)) {
      cout << "Movie Record: " << endl;
      for (size_t i = 0; i < listOfRecords.size(); i++) {
        DisplayItemInfo(listOfRecords[i], i + 1);
      }
    }
  }
}

void Shop::ShowAllOutOfStockItems() {
  cout << "Out of stock items: " << endl;
  if (!IsItemListEmpty(1)) {
    int count = 0;
    cout << "Video Games: " << endl;
    for (size_t i = 0; i < listOfVideoGames.size(); i++) {
      if (listOfVideoGames[i].GetRentalStatus() == "Borrowed" &&
          listOfVideoGames[i].GetNumberOfCopies() == 0)
        DisplayItemInfo(listOfVideoGames[i], ++count);
    }
    if (count == 0) cout << "No Video Games currently out of stock" << endl;
  }
  if (!IsItemListEmpty(2)) {
    int count = 0;
    cout << "DVDs: " << endl;
    for (size_t i = 0; i < listOfDVDs.size(); i++) {
      if (listOfDVDs[i].GetRentalStatus() == "Borrowed" &&
          listOfDVDs[i].GetNumberOfCopies() == 0)
        DisplayItemInfo(listOfDVDs[i], ++count);
    }
    if (count == 0) cout << "No DVDs currently out of stock" << endl;
  }
  if (!IsItemListEmpty(3)) {
    int count = 0;
    cout << "Movie Record: " << endl;
    for (size_t i = 0; i < listOfRecords.size(); i++) {
      if (listOfRecords[i].GetRentalStatus() == "Borrowed" &&
          listOfRecords[i].GetNumberOfCopies() == 0)
        DisplayItemInfo(listOfRecords[i], ++count);
    }
    if (count == 0) cout << "No Records currently out of stock" << endl;
  }
}

int Shop::GetItemIndex(int type) {
  int index = 0;
  if (type == 1) {
    if (!IsItemListEmpty(1)) {
      ShowAllItems(1);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= listOfVideoGames.size()))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= listOfVideoGames.size()));
    }
  } else if (type == 2) {
    if (!IsItemListEmpty(2)) {
      ShowAllItems(2);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= listOfDVDs.size()))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= listOfDVDs.size()));
    }
  } else if (type == 3) {
    if (!IsItemListEmpty(3)) {
      ShowAllItems(3);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= listOfRecords.size()))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= listOfRecords.size()));
    }
  }
  return index - 1;
}

int Shop::GetItemIndex(int type, bool onlyAvailableItem) {
  int index = 0;
  int count = 0;
  vector<int> position;
  if (type == 1) {
    if (!IsItemListEmpty(1)) {
      for (size_t i = 0; i < listOfVideoGames.size(); i++) {
        if (listOfVideoGames[i].GetNumberOfCopies() != 0 &&
            listOfVideoGames[i].GetRentalStatus() != "Borrowed") {
          position.push_back(i);
          count++;
          DisplayItemInfo(listOfVideoGames[i], count);
        }
      }
      if (count == 0) {
        cout << "No video game is currently available";
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= count))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= count));
    }
  } else if (type == 2) {
    if (!IsItemListEmpty(2)) {
      for (size_t i = 0; i < listOfDVDs.size(); i++) {
        if (listOfDVDs[i].GetNumberOfCopies() != 0 &&
            listOfDVDs[i].GetRentalStatus() != "Borrowed") {
          position.push_back(i);
          count++;
          DisplayItemInfo(listOfDVDs[i], count);
        }
      }
      if (count == 0) {
        cout << "No video game is currently available";
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= count))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= count));
    }
  } else if (type == 3) {
    if (!IsItemListEmpty(3)) {
      for (size_t i = 0; i < listOfRecords.size(); i++) {
        if (listOfRecords[i].GetNumberOfCopies() != 0 &&
            listOfRecords[i].GetRentalStatus() != "Borrowed") {
          position.push_back(i);
          count++;
          DisplayItemInfo(listOfRecords[i], count);
        }
      }
      if (count == 0) {
        cout << "No video game is currently available";
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (!(index >= 1 && index <= count))
          cout << "Invalid option. Try again" << endl;
      } while (!(index >= 1 && index <= count));
    }
  }
  return count != 0 ? position[index - 1] : -1;
}

void Shop::UpdateItem(int type) {
  int index = GetItemIndex(type);
  if (index == -1) return;
  if (type == 1) {
    listOfVideoGames[index].SetTitle();
    listOfVideoGames[index].SetLoanType();
    listOfVideoGames[index].SetNumberOfCopies();
    listOfVideoGames[index].SetRentalFee();
    listOfVideoGames[index].SetRentalStatus();
  } else if (type == 2) {
    listOfDVDs[index].SetTitle();
    listOfDVDs[index].SetLoanType();
    listOfDVDs[index].SetNumberOfCopies();
    listOfDVDs[index].SetRentalFee();
    listOfDVDs[index].SetRentalStatus();
    listOfDVDs[index].SetGenre();
  } else if (type == 3) {
    listOfRecords[index].SetTitle();
    listOfRecords[index].SetLoanType();
    listOfRecords[index].SetNumberOfCopies();
    listOfRecords[index].SetRentalFee();
    listOfRecords[index].SetRentalStatus();
    listOfRecords[index].SetGenre();
  }
}

void Shop::DeleteItem(int type) {
  int index = GetItemIndex(type);
  if (index == -1) return;
  if (type == 1) {
    listOfVideoGames.erase(listOfVideoGames.begin() + index);
  } else if (type == 2) {
    listOfDVDs.erase(listOfDVDs.begin() + index);
  } else if (type == 3) {
    listOfRecords.erase(listOfRecords.begin() + index);
  }
}

void Shop::DisplayUserInfo(User user, int position) {
  cout << position << ". ID: " << user.GetId() << ", Name: " << user.GetName()
       << ", Address: " << user.GetAddress() << ", Phone: " << user.GetPhone()
       << ", Role: " << user.GetRole() << endl;
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
  if (!IsUserListEmpty()) {
    for (size_t i = 0; i < listOfUsers.size(); i++) {
      DisplayUserInfo(listOfUsers[i], i + 1);
    }
  }
}

int Shop::GetUserIndex() {
  int index = 0;
  if (!IsUserListEmpty()) {
    do {
      ShowAllUsers();
      cout << "Select a user: ";
      cin >> index;
      if (!(index >= 1 && index <= listOfUsers.size()))
        cout << "Invalid option. Try again" << endl;
    } while (!(index >= 1 && index <= listOfUsers.size()));
  }
  return index - 1;
}

void Shop::UpdateUser() {
  int index = GetUserIndex();
  if (index == -1) return;
  listOfUsers[index].SetName();
  listOfUsers[index].SetAddress();
  listOfUsers[index].SetPhone();
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
    for (size_t i = 0; i < listOfUsers.size(); i++) {
      if (listOfUsers[i].GetRole() == role)
        cout << ++count << ". ID: " << listOfUsers[i].GetId()
             << ", Name: " << listOfUsers[i].GetName()
             << ", Address: " << listOfUsers[i].GetAddress()
             << ", Phone: " << listOfUsers[i].GetPhone() << endl;
    }
  }
  if (count == 0) cout << "No users with this role available" << endl;
}

void Shop::RentItem(int type) {
  bool onlyAvailableItem = true;
  bool isLendingItem = true;
  int indexForItem = GetItemIndex(type, onlyAvailableItem);
  if (indexForItem == -1) return;
  int indexForUser = GetUserIndex();
  if (indexForUser == -1) return;
  if (type == 1) {
    if (listOfUsers[indexForUser].GetRole() == "Guest" &&
        listOfVideoGames[indexForItem].GetLoanType() == "2-day") {
      cout << "Only Regular and VIP member can borrow 2-day Video items"
           << endl;
      return;
    }
    listOfVideoGames[indexForItem].SetNumberOfCopies(isLendingItem);
    listOfUsers[indexForUser].AddRental(listOfVideoGames[indexForItem].GetId());
  }
  if (type == 2) {
    listOfDVDs[indexForItem].SetNumberOfCopies(isLendingItem);
    listOfUsers[indexForUser].AddRental(listOfDVDs[indexForItem].GetId());
  }
  if (type == 3) {
    listOfRecords[indexForItem].SetNumberOfCopies(isLendingItem);
    listOfUsers[indexForUser].AddRental(listOfRecords[indexForItem].GetId());
  }
}

Item* Shop::FindItemById(string itemId) {
  for (size_t i = 0; i < listOfVideoGames.size(); i++) {
    if (listOfVideoGames[i].GetId() == itemId) {
      return &listOfVideoGames[i];
    }
  }
  for (size_t i = 0; i < listOfDVDs.size(); i++) {
    if (listOfDVDs[i].GetId() == itemId) {
      return &listOfDVDs[i];
    }
  }
  for (size_t i = 0; i < listOfRecords.size(); i++) {
    if (listOfRecords[i].GetId() == itemId) {
      return &listOfRecords[i];
    }
  }
  return NULL;
}

User* Shop::FindUserById(string itemId) {
  for (size_t i = 0; i < listOfUsers.size(); i++) {
    if (listOfUsers[i].GetId() == itemId) {
      return &listOfUsers[i];
    }
  }
  return NULL;
}

void Shop::ReturnItem() {
  int count = 0;
  int indexForUser;
  int indexForItem;
  vector<int> position;
  for (size_t i = 0; i < listOfUsers.size(); i++) {
    if (listOfUsers[i].GetListOfRentals().size() > 0) {
      DisplayUserInfo(listOfUsers[i], ++count);
    }
  }
  if (count == 0) {
    cout << "There is no user that borrow the item from the shop" << endl;
    return;
  }

  do {
    cout << "Select a user: ";
    cin >> indexForUser;
    if (!(indexForUser >= 1 && indexForUser <= count))
      cout << "Invalid option. Try again" << endl;
  } while (!(indexForUser >= 1 && indexForUser <= count));
  indexForUser--;
  User u = listOfUsers[indexForUser];

  for (size_t i = 0; i < u.GetListOfRentals().size(); i++) {
    Item* item = FindItemById(u.GetListOfRentals()[i]);
    cout << i + 1 << ". ID: " << item->GetId()
         << ", Title: " << item->GetTitle() << endl;
  }
  do {
    cout << "Select an item to return: ";
    cin >> indexForItem;
    if (!(indexForItem >= 1 && indexForItem <= u.GetListOfRentals().size()))
      cout << "Invalid option. Try again" << endl;
  } while (!(indexForItem >= 1 && indexForItem <= u.GetListOfRentals().size()));
  indexForItem--;
  string chosenReturnedItemId =
      listOfUsers[indexForUser].ReturnRental(indexForItem);
  FindItemById(chosenReturnedItemId)->updateValueAfterReturning();
}

void Shop::SearchForItem(int type) {
  if (type == 1) {
    string input;
    do {
      cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
      cin >> input;
      if (!Item::CheckId(input))
        cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try again"
             << endl;
    } while (!Item::CheckId(input));
    Item* item = FindItemById(input);
    if (!item)
      cout << "Can not find item that match the description" << endl;
    else
      DisplayItemInfo((*item), 1);
  } else if (type == 2) {
    int count = 0;
    string title;
    cin.ignore();
    cout << "Title of the item: ";
    getline(cin, title);
    for (size_t i = 0; i < listOfVideoGames.size(); i++) {
      if (listOfVideoGames[i].GetTitle() == title) {
        DisplayItemInfo(listOfVideoGames[i], ++count);
      }
    }
    for (size_t i = 0; i < listOfDVDs.size(); i++) {
      if (listOfDVDs[i].GetId() == title) {
        DisplayItemInfo(listOfDVDs[i], ++count);
      }
    }
    for (size_t i = 0; i < listOfRecords.size(); i++) {
      if (listOfRecords[i].GetId() == title) {
        DisplayItemInfo(listOfRecords[i], ++count);
      }
    }
    if (count == 0)
      cout << "Can not find item that match the description" << endl;
  }
}

void Shop::SearchForUser(int type) {
  if (type == 1) {
    string input;
    do {
      cout << "Id (Format: Cxxx (x is a number)): ";
      cin >> input;
      if (!User::CheckId(input))
        cout << "Invalid format. Format: Cxxx (x is a number). Try again"
             << endl;
    } while (!User::CheckId(input));
    User* u = FindUserById(input);
    if (!u)
      cout << "Can not find user that match the description" << endl;
    else
      DisplayUserInfo(*u, 1);
  } else if (type == 2) {
    int count = 0;
    string username;
    cin.ignore();
    cout << "User's name: ";
    getline(cin, username);
    for (size_t i = 0; i < listOfUsers.size(); i++) {
      if (listOfUsers[i].GetName() == username) {
        DisplayUserInfo(listOfUsers[i], ++count);
      }
    }
    if (count == 0)
      cout << "Can not find user that match the description" << endl;
  }
}
