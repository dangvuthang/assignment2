#include "Shop.h"
#include "Menu.h"
#include <fstream>
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

bool isNumber(const string& str) {
  for (char const& c : str) {
    if (isdigit(c) == 0) return false;
  }
  return true;
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
  string index;
  if (type == 1) {
    if (!IsItemListEmpty(1)) {
      ShowAllItems(1);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= listOfVideoGames.size())) {
            cout << "Invalid option. Try again" << endl;
          }
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }
      } while (!(stoi(index) >= 1 && stoi(index) <= listOfVideoGames.size()));
    }
  } else if (type == 2) {
    if (!IsItemListEmpty(2)) {
      ShowAllItems(2);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= listOfDVDs.size())) {
            cout << "Invalid option. Try again" << endl;
          }
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }
      } while (!(stoi(index) >= 1 && stoi(index) <= listOfDVDs.size()));
    }
  } else if (type == 3) {
    if (!IsItemListEmpty(3)) {
      ShowAllItems(3);
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= listOfRecords.size())) {
            cout << "Invalid option. Try again" << endl;
          }
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }
      } while (!(stoi(index) >= 1 && stoi(index) <= listOfRecords.size()));
    }
  }
  return stoi(index) - 1;
}

int Shop::GetItemIndex(int type, bool onlyAvailableItem) {
  string index;
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
        cout << "No video game is currently available" << endl;
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= count))
            cout << "Invalid option. Try again" << endl;
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }

      } while (!(stoi(index) >= 1 && stoi(index) <= count));
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
        cout << "No video game is currently available" << endl;
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= count))
            cout << "Invalid option. Try again" << endl;
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }

      } while (!(stoi(index) >= 1 && stoi(index) <= count));
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
        cout << "No video game is currently available" << endl;
        return -1;
      }
      do {
        cout << "Select an item's number: ";
        cin >> index;
        if (isNumber(index)) {
          if (!(stoi(index) >= 1 && stoi(index) <= count))
            cout << "Invalid option. Try again" << endl;
        } else {
          cout << "Invalid option. Try again" << endl;
          index = "0";
        }

      } while (!(stoi(index) >= 1 && stoi(index) <= count));
    }
  }
  return count != 0 ? position[stoi(index) - 1] : -1;
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
void Shop::DisplayUserInfo(SpecialUser vip, int position) {
    cout << position << ". ID: " << vip.GetId() << ", Name: " << vip.GetName()
        << ", Address: " << vip.GetAddress() << ", Phone: " << vip.GetPhone()
        << ", Role: " << vip.GetRole() << ", Reward Points: " << vip.GetRewardPoint() << endl;
}
bool Shop::IsUserListEmpty(int type) {
    if (type == 3) {
        if (listOfSpecialUsers.size() == 0) {
            cout << "No Special User available" << endl;
            return true;
        }
        else {
            return false;
        }
    }
    else if (type == 2 || type == 1) {
        if (listOfUsers.size() == 0) {
            cout << "No users available" << endl;
            return true;
        }
        switch (type) {
        case 2:
            for (size_t i = 0; i < listOfUsers.size(); i++) {
                if (listOfUsers[i].GetRole() == "Regular") {
                    return false;
                }
                else {
                    cout << "No Regular users available" << endl;
                    return true;
                }
            }
            break;
        case 1:
            for (size_t i = 0; i < listOfUsers.size(); i++) {
                if (listOfUsers[i].GetRole() == "Guest") {
                    return false;
                }
                else {
                    cout << "No Guest users available" << endl;
                    return true;
                }
            }
            break;
        }
    }
    return false;
}

void Shop::AddUser() {
    bool newUser = true;
  User user;
  user.SetId();
  user.SetName();
  user.SetAddress();
  user.SetPhone();
  user.SetRole(true);
  listOfUsers.push_back(user);
}

void Shop::ShowAllUsers() {
    ShowAllUsers(1);
    ShowAllUsers(2);
    ShowAllUsers(3);
}
int Shop::ShowAllUsers(int type) {
    string role;
    int count = 0;
    switch (type) {
    case 1:
        role = "Guest";
        cout << "Guest Role: " << endl;
        break;
    case 2:
        role = "Regular";
        cout << "Regular Role: " << endl;
        break;
    case 3:
        role = "VIP";
        cout << "VIP Role: " << endl;
        break;
    }
    if (type == 1 || type == 2) {
        for (size_t i = 0; i < listOfUsers.size(); i++) {
            if (listOfUsers[i].GetRole() == role) {
                count++;
                DisplayUserInfo(listOfUsers[i], count);
            }
        }
    }
    if (type == 3) {
        for (size_t i = 0; i < listOfSpecialUsers.size(); i++) {
            count++;
            DisplayUserInfo(listOfSpecialUsers[i], count);
        }
    }
    if (count == 0) cout << "No " << role << " users with is available" << endl;
    return count;
}
int Shop::GetUserIndex(int type) {
    int index = 0;
    bool specialUser{};
    if (type == 1 || type == 2) {
        specialUser = false;
    }
    else if (type == 3) {
        specialUser = true;
    }
    if (!IsUserListEmpty(type)) {
        int userCount = ShowAllUsers(type);
        if (specialUser == false) {
            do {
                cout << "Select a user: ";
                cin >> index;
                if (!(index >= 1 && index <= userCount)) {
                    cout << "Invalid option. Try again" << endl;
                }
            } while (!(index >= 1 && index <= userCount));
        }
        else if (specialUser == true) {
            do {
                cout << "Select a Special user: ";
                cin >> index;
                if (!(index >= 1 && index <= listOfSpecialUsers.size())) {
                    cout << "Invalid option. Try again" << endl;
                }
            } while (!(index >= 1 && index <= listOfSpecialUsers.size()));

        }
    }
    return index - 1;
}
int Shop::GetUserIndex(bool specialUser) {
    int index = 0;
    int count = 0;
    vector<int> position;
    if (listOfUsers.size() != 0 && specialUser == false) {
        for (size_t i = 0; i < listOfUsers.size(); i++) {
            if (listOfUsers[i].GetNumberOfItemReturned() >= 3) {
                position.push_back(i);
                count++;
                DisplayUserInfo(listOfUsers[i], count);
            }
        }
        if (count == 0) {
            cout << "No user eligible for promotion";
            return -1;
        }
        do {
            cout << "Select an user to Promote: ";
            cin >> index;
            if (!(index >= 1 && index <= count))
                cout << "Invalid option. Try again" << endl;
        } while (!(index >= 1 && index <= count));
    }
    return count != 0 ? position[index - 1] : -1;
}
void Shop::UpdateUser(int type) {
  int index = GetUserIndex(type);
  if (index == -1) return;
  listOfUsers[index].SetName();
  listOfUsers[index].SetAddress();
  listOfUsers[index].SetPhone();
}
void Shop::DeleteUser(int type) {
    int index = GetUserIndex(type);
    if (index == -1) return;
    if (type == 1 || type == 2) {
        for (size_t i = 0; i < listOfUsers[index].GetListOfRentals().size(); i++) {
            string returnItemId = listOfUsers[index].GetListOfRentals()[i];
            FindItemById(returnItemId)->updateValueAfterReturning();
        }
    }
    else if (type == 3) {
        for (size_t i = 0; i < listOfSpecialUsers[index].GetListOfRentals().size(); i++) {
            string returnItemId = listOfSpecialUsers[index].GetListOfRentals()[i];
            FindItemById(returnItemId)->updateValueAfterReturning();
        }
    }
    listOfUsers.erase(listOfUsers.begin() + index);
}
void Shop::PromoteUser() {
    bool specialUser = false;
    bool newUser = false;
    int index = GetUserIndex(specialUser);
    if (index == -1) return;
    if (listOfUsers[index].GetRole() == "Guest") {
        listOfUsers[index].SetRole(newUser);
    }
    else if (listOfUsers[index].GetRole() == "Regular") {
        SpecialUser vip(listOfUsers[index].GetId(), listOfUsers[index].GetName(), listOfUsers[index].GetAddress(), listOfUsers[index].GetPhone(), "VIP");
        for (size_t i = 0; i < listOfUsers[index].GetListOfRentals().size(); i++) {
            vip.GetListOfRentals().push_back(listOfUsers[index].GetListOfRentals()[i]);
        }

        listOfSpecialUsers.push_back(vip);
        listOfUsers.erase(listOfUsers.begin() + index);
    }
}
void Shop::RentItem(int userType) {
  bool onlyAvailableItem = true;
  bool specialUser{};
  int indexForUser = GetUserIndex(userType);
  if (indexForUser == -1) return;
  int itemType = Menu::DisplayTypeOfItem();
  int indexForItem = GetItemIndex(itemType, onlyAvailableItem);
  if (indexForItem == -1) return;
  
  if (userType == 1 || userType == 2) {
      specialUser = false;
  }
  else if (userType == 3) {
      specialUser = true;
  }
  if (listOfUsers[indexForUser].GetRole() == "Guest") {
      if (listOfUsers[indexForUser].GetListOfRentals().size() > 2) {
          cout << "Guest member can only borrow a maximum of 2 items" << endl;
          return;
      }
      switch (itemType) {
      case 1:
          if (listOfVideoGames[indexForItem].GetLoanType() == "2-day") {
              cout << "Only Regular and VIP member can borrow 2-day Video Games" << endl;
              return;
          }
          break;
      case 2:
          if (listOfDVDs[indexForItem].GetLoanType() == "2-day") {
              cout << "Only Regular and VIP member can borrow 2-day DVDs" << endl;
              return;
          }
          break;
      case 3:
          if (listOfRecords[indexForItem].GetLoanType() == "2-day") {
              cout << "Only Regular and VIP member can borrow 2-day Movie Records" << endl;
              return;
          }
          break;
      }
  }
  if (specialUser == false) {
      switch (itemType) {
      case 1:
          listOfUsers[indexForUser].AddRental(listOfVideoGames[indexForItem].GetId());
          FindItemById(listOfVideoGames[indexForItem].GetId())->updateValueAfterRenting();
          break;
      case 2:
          listOfUsers[indexForUser].AddRental(listOfDVDs[indexForItem].GetId());
          FindItemById(listOfDVDs[indexForItem].GetId())->updateValueAfterRenting();
          break;
      case 3:
          listOfUsers[indexForUser].AddRental(listOfRecords[indexForItem].GetId());
          FindItemById(listOfRecords[indexForItem].GetId())->updateValueAfterRenting();
          break;
      }
  }
  else if (specialUser == true) {
      switch (itemType) {
      case 1:
          listOfSpecialUsers[indexForUser].AddRental(listOfVideoGames[indexForItem].GetId());
          FindItemById(listOfVideoGames[indexForItem].GetId())->updateValueAfterRenting();
          break;
      case 2:
          listOfSpecialUsers[indexForUser].AddRental(listOfDVDs[indexForItem].GetId());
          FindItemById(listOfDVDs[indexForItem].GetId())->updateValueAfterRenting();
          break;
      case 3:
          listOfSpecialUsers[indexForUser].AddRental(listOfRecords[indexForItem].GetId());
          FindItemById(listOfRecords[indexForItem].GetId())->updateValueAfterRenting();
          break;
      }
      listOfSpecialUsers[indexForItem].AddPointOnRent();
      int option = 0;
      cout << "Would you like to use reward points to rent item ?" << endl;
      cout << "1. YES " << endl;
      cout << "2. NO " << endl;
      cout << "Enter your opton: ";
      cin >> option;
      if (option == 1) {
          listOfSpecialUsers[indexForUser].UsePointForRent();
      }
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
SpecialUser* Shop::FindSpecialUserById(string itemId) {
    for (size_t i = 0; i < listOfSpecialUsers.size(); i++) {
        if (listOfSpecialUsers[i].GetId() == itemId) {
            return &listOfSpecialUsers[i];
        }
    }
    return NULL;
}
void Shop::ReturnItem() {
    int count = 0, indexForUser, indexForItem;
    string  indexSelectUser, indexSelectItem;
    vector<int> positionUser;
    int userType = Menu::DisplayTypeOfUser();

    if (userType == 1 || userType == 2) {
        for (size_t i = 0; i < listOfUsers.size(); i++) {
            if (listOfUsers[i].GetListOfRentals().size() > 0) {
                count++;
                DisplayUserInfo(listOfUsers[i], count);
                positionUser.push_back(i);
            }
        }
        if (count == 0) {
            cout << "There is no user that borrow the item from the shop" << endl;
            return;
        }
        do {
            cout << "Select a user: ";
            cin >> indexSelectUser;
            if (isNumber(indexSelectUser)) {
                if (!(stoi(indexSelectUser) >= 1 && stoi(indexSelectUser) <= count))
                    cout << "Invalid option. Try again" << endl;
            }
            else {
                cout << "Invalid option. Try again" << endl;
                indexSelectUser = "0";
            }
        } while (!(stoi(indexSelectUser) >= 1 && stoi(indexSelectUser) <= count));
        int userIndexNum = stoi(indexSelectUser);
        userIndexNum--;
        indexForUser = positionUser[userIndexNum];
        User u = listOfUsers[indexForUser];
        for (size_t i = 0; i < u.GetListOfRentals().size(); i++) {
            Item* item = FindItemById(u.GetListOfRentals()[i]);
            cout << i + 1 << ". ID: " << item->GetId() << ", Title: " << item->GetTitle() << endl;
        }
        do {
            cout << "Select an item to return: ";
            cin >> indexSelectItem;
            if (!(stoi(indexSelectItem) >= 1 && stoi(indexSelectItem) <= u.GetListOfRentals().size()))
                cout << "Invalid option. Try again" << endl;
        } while (!(stoi(indexSelectItem) >= 1 && stoi(indexSelectItem) <= u.GetListOfRentals().size()));
        indexForItem = stoi(indexSelectItem);
        indexForItem--;
        string chosenReturnedItemId = u.GetListOfRentals()[indexForItem];
        listOfUsers[indexForUser].ReturnRental(indexForItem);
        FindItemById(chosenReturnedItemId)->updateValueAfterReturning();
        cout << u.GetName() << " successfully return an item" << endl;
    }
    else if (userType == 3) {
        for (size_t i = 0; i < listOfSpecialUsers.size(); i++) {
            if (listOfSpecialUsers[i].GetListOfRentals().size() > 0) {
                count++;
                DisplayUserInfo(listOfSpecialUsers[i], count);
                positionUser.push_back(i);
            }
        }
        if (count == 0) {
            cout << "There is no Special user that borrow the item from the shop" << endl;
            return;
        }
        do {
            cout << "Select a user: ";
            cin >> indexSelectUser;
            if (isNumber(indexSelectUser)) {
                if (!(stoi(indexSelectUser) >= 1 && stoi(indexSelectUser) <= count))
                    cout << "Invalid option. Try again" << endl;
            }
            else {
                cout << "Invalid option. Try again" << endl;
                indexSelectUser = "0";
            }
        } while (!(stoi(indexSelectUser) >= 1 && stoi(indexSelectUser) <= count));
        int userIndexNum = stoi(indexSelectUser);
        userIndexNum--;
        indexForUser = positionUser[userIndexNum];
        SpecialUser vip = listOfSpecialUsers[indexForUser];
        for (size_t i = 0; i < vip.GetListOfRentals().size(); i++) {
            Item* item = FindItemById(vip.GetListOfRentals()[i]);
            cout << i + 1 << ". ID: " << item->GetId() << ", Title: " << item->GetTitle() << endl;
        }
        do {
            cout << "Select an item to return: ";
            cin >> indexSelectItem;
            if (!(stoi(indexSelectItem) >= 1 && stoi(indexSelectItem) <= vip.GetListOfRentals().size()))
                cout << "Invalid option. Try again" << endl;
        } while (!(stoi(indexSelectItem) >= 1 && stoi(indexSelectItem) <= vip.GetListOfRentals().size()));
        indexForItem = stoi(indexSelectItem);
        indexForItem--;
        string chosenReturnedItemId = vip.GetListOfRentals()[indexForItem];
        vip.ReturnRental(indexForItem);
        FindItemById(chosenReturnedItemId)->updateValueAfterReturning();
        cout << vip.GetName() << " successfully return an item" << endl;
    }
}

void Shop::SearchForItem(int type) {
  if (type == 1) {
    string input;
    do {
      cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
      cin >> input;
      if (!Item::CheckId(input))
        cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try "
                "again"
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

void Shop::SearchForUser(int searchType, int userType) {
    if (searchType == 1) {
        string input;
        do {
            cout << "Id (Format: Cxxx (x is a number)): ";
            cin >> input;
            if (!User::CheckId(input))
                cout << "Invalid format. Format: Cxxx (x is a number). Try again"
                << endl;
        } while (!User::CheckId(input));
        if (userType == 1 || userType == 2) {
            User* u = FindUserById(input);
            if (!u) {
                cout << "Can not find user that match the description" << endl;
            }
            else {
                DisplayUserInfo(*u, 1);
            }
        }
        else if (userType == 3) {
            SpecialUser* vip = FindSpecialUserById(input);
            if (!vip) {
                cout << "Can not find Special user that match the description" << endl;
            }
            else {
                DisplayUserInfo(*vip, 1);
            }
        }
    }
    else if (searchType == 2) {
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

void Shop::saveItem(string itemFile) {
  ofstream itemcsv(itemFile);

  itemcsv << "Type,ID,Title,Rental type,Loan Type,Number of copies,Rental "
             "fee,Rental status,genre"
          << endl;

  // Save video games
  for (Item item : this->listOfVideoGames) {
    itemcsv << "1," << item.GetId() << "," << item.GetTitle() << ","
            << item.GetRentalType() << "," << item.GetLoanType() << ","
            << item.GetNumberOfCopies() << "," << item.GetRentalFee() << ","
            << item.GetRentalStatus() << ","
            << "N/A\n";
  }

  // Save DVDs
  for (SpecialItem item : this->listOfDVDs) {
    itemcsv << "2," << item.GetId() << "," << item.GetTitle() << ","
            << item.GetRentalType() << "," << item.GetLoanType() << ","
            << item.GetNumberOfCopies() << "," << item.GetRentalFee() << ","
            << item.GetRentalStatus() << "," << item.GetGenre() << "\n";
  }

  // Save Records
  for (SpecialItem item : this->listOfRecords) {
    itemcsv << "3," << item.GetId() << "," << item.GetTitle() << ","
            << item.GetRentalType() << "," << item.GetLoanType() << ","
            << item.GetNumberOfCopies() << "," << item.GetRentalFee() << ","
            << item.GetRentalStatus() << "," << item.GetGenre() << "\n";
  }

  itemcsv.close();
}

void Shop::saveUser(string userFile) {
  ofstream usercsv(userFile);

  usercsv << "ID,name,address,phone,role,number of item returned,list rentals"
          << endl;

  // Save video games
  for (User user : this->listOfUsers) {
    usercsv << user.GetId() << "," << user.GetName() << "," << user.GetAddress()
            << "," << user.GetPhone() << "," << user.GetRole() << ","
            << user.GetNumberOfItemReturned() << ",";

    vector<string> listOfRental = user.GetListOfRentals();
    for (auto it = listOfRental.begin(); it != listOfRental.end(); ++it) {
      if (it != listOfRental.begin()) usercsv << ";";
      usercsv << *it;
    }
    usercsv << "\n";
  }
}

void Shop::loadItem(string itemFile) {
  ifstream itemcsv(itemFile);

  if (!itemcsv.is_open()) {
    cout << "Cannot load items" << endl;
    return;
  }

  string line;

  // Get column name
  if (itemcsv.good()) getline(itemcsv, line);

  while (getline(itemcsv, line)) {
    stringstream ss(line);
    vector<string> resultLine;

    while (ss.good()) {
      string substr;
      getline(ss, substr, ',');
      resultLine.push_back(substr);
    }

    switch (stoi(resultLine[0])) {
      case 1:
        this->listOfVideoGames.push_back(
            Item(resultLine[1], resultLine[2], resultLine[3], resultLine[4],
                 stoi(resultLine[5]), stof(resultLine[6]), resultLine[7]));
        break;
      case 2:
        this->listOfDVDs.push_back(
            SpecialItem(resultLine[1], resultLine[2], resultLine[3],
                        resultLine[4], stoi(resultLine[5]), stof(resultLine[6]),
                        resultLine[7], resultLine[8]));
        break;
      case 3:
        this->listOfRecords.push_back(
            SpecialItem(resultLine[1], resultLine[2], resultLine[3],
                        resultLine[4], stoi(resultLine[5]), stof(resultLine[6]),
                        resultLine[7], resultLine[8]));
        break;
    }
  }
}

void Shop::loadUser(string userFile) {
  ifstream usercsv(userFile);

  if (!usercsv.is_open()) {
    cout << "Cannot load users" << endl;
    return;
  }

  string line;

  // Get column name
  if (usercsv.good()) getline(usercsv, line);

  while (getline(usercsv, line)) {
    stringstream ss(line);
    vector<string> resultLine;
    vector<string> listOfRentals;

    while (ss.good()) {
      string substr;
      getline(ss, substr, ',');
      resultLine.push_back(substr);
    }

    if (resultLine.back() != "") {
      ss = stringstream(resultLine.back());
      while (ss.good()) {
        string substr;
        getline(ss, substr, ';');
        listOfRentals.push_back(substr);
      }
    }
    if (resultLine[4] == "Guest" || resultLine[4] == "Regular") {
        this->listOfUsers.push_back(
        User(resultLine[0], resultLine[1], resultLine[2], resultLine[3],
             resultLine[4], stoi(resultLine[5]), listOfRentals));
    }
    else if (resultLine[4] == "VIP"){
        this->listOfSpecialUsers.push_back(
            SpecialUser(resultLine[0], resultLine[1], resultLine[2], resultLine[3],
                resultLine[4], stoi(resultLine[5]), listOfRentals));
    }
    
    
  }
}