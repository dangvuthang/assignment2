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
      for (size_t i = 0; i < listOfVideoGames.size(); i++) {
        cout << "Video Games: " << endl;
        DisplayItemInfo(listOfVideoGames[i], i + 1);
      }
    }
  }
  if (type == 2) {
    if (!IsItemListEmpty(2)) {
      for (size_t i = 0; i < listOfDVDs.size(); i++) {
        cout << "DVDs: " << endl;
        DisplayItemInfo(listOfDVDs[i], i + 1);
      }
    }
  }
  if (type == 3) {
    if (!IsItemListEmpty(3)) {
      for (size_t i = 0; i < listOfRecords.size(); i++) {
        cout << "Movie Record: " << endl;
        DisplayItemInfo(listOfRecords[i], i + 1);
      }
    }
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
  int indexForItem = GetItemIndex(type, true);
  if (indexForItem == -1) return;
  int indexForUser = GetUserIndex();
  if (indexForUser == -1) return;
  cout << "The chosen index for user " << indexForUser;
  cout << "The chosen index for item " << indexForItem;
  bool isLendingItem = true;
  if (type == 1) {
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