#include "Shop.h"
#include <fstream>

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Shop::Shop() {}

void Shop::AddItem(eRentalType type) {
    Item* itemPtr;
    bool firstTimeCopies = true;
    if (type == game) {
        Item videoGame;
        videoGame.SetId();
        videoGame.SetTitle();
        videoGame.SetRentalType(type);
        videoGame.SetLoanType();
        videoGame.SetNumberOfCopies(firstTimeCopies);
        videoGame.SetRentalFee();
        //videoGame.SetRentalStatus();
        //listOfVideoGames.push_back(videoGame);
        itemPtr = &videoGame;
    }
    else {
        SpecialItem item;
        item.SetId();
        item.SetTitle();
        item.SetRentalType(type);
        item.SetLoanType();
        item.SetNumberOfCopies(firstTimeCopies);
        item.SetRentalFee();
        //item.SetRentalStatus();
        item.SetGenre();
        //type == 2 ? listOfDVDs.push_back(item) : listOfRecords.push_back(item);
        itemPtr = &item;
    }
    listOfItem.push_back(itemPtr);
    cout << "current list size: " << listOfItem.size() << endl;
    cout << "added item: " << endl;
    DisplayItemInfo(itemPtr, 1);
}
void Shop::DisplayItemInfo(Item* item, int position) {
    cout << position << ". "
        << "ID: " << item->GetId()
        << ", Title: " << item->GetTitle()
        << ", Rental type: " << item->GetRentalTypeString()
        << ", Loan type: " << item->GetLoanType()
        << ", Number of copies: " << item->GetNumberOfCopies()
        << ", Rental fee: " << item->GetRentalFee()
        << ", Rental status: " << item->GetRentalStatusString();
    if (item->GetRentalType() != game) {
        cout << ", Genre: " << item->GetGenreString() << endl;
    }
    else {
        cout << endl;
    }
}
bool Shop::IsItemListEmpty() {
    if (listOfItem.size() == 0) {
        cout << "There is no item in the shop" << endl;
        return true;
    }
    return false;
}
bool Shop::IsItemListEmpty(eRentalType type) {
    for (int i = 0; i < listOfItem.size(); i++) {
        if (listOfItem[i]->GetRentalType() == type) {
            return false;
        }
        else if (i == listOfItem.size() && listOfItem[i]->GetRentalType() != type) {
            switch (type) {
            case 1:
                cout << "There is no video game in the shop" << endl;
                return true;
                break;
            case 2:
                cout << "There is no DVD in the shop" << endl;
                return true;
                break;
            case 3:
                cout << "There is no movie record in the shop" << endl;
                return true;
                break;
            }
        }
    }
    return false;
}
void Shop::ShowAllItems() {
    cout << "size of Stock: " << listOfItem.size() << endl;

    if (!IsItemListEmpty()) {
        ShowAllItems(game);
        ShowAllItems(dvd);
        ShowAllItems(record);
    }
    /*
    for (int i = 0; i < listOfItem.size(); i++){
      cout << "ID: " << listOfItem[i]->GetId()
        << ", Title: " << listOfItem[i]->GetTitle()
        << ", Rental type: " << listOfItem[i]->GetRentalTypeString()
        << ", Loan type: " << listOfItem[i]->GetLoanType()
        << ", Number of copies: " << listOfItem[i]->GetNumberOfCopies()
        << ", Rental fee: " << listOfItem[i]->GetRentalFee()
        << ", Rental status: " << listOfItem[i]->GetRentalStatusString();
    }
    */
}
void Shop::ShowAllItems(eRentalType type) {
    if (!IsItemListEmpty(type)) {
        int count = 0;
        switch (type) {
        case 1:
            cout << "Video Games: " << endl;
            break;
        case 2:
            cout << "DVDs: " << endl;
            break;
        case 3:
            cout << "Movie Record: " << endl;
            break;
        }
        for (int i = 0; i < listOfItem.size(); i++) {
            cout << "show item type: " << listOfItem[i]->GetRentalType() << endl;
            cout << "show enum type: " << type << endl;
            if (listOfItem[i]->GetRentalType() == type) {
                DisplayItemInfo(listOfItem[i], i + 1);
                count++;
            }
        }
    }
}
void Shop::ShowAllOutOfStockItems() {
    cout << "Out of stock items: " << endl;
    if (!IsItemListEmpty(game)) {
        int count = 0;
        cout << "Video Games: " << endl;
        for (int i = 0; i < listOfVideoGames.size(); i++) {
            if (listOfItem[i]->GetRentalType() == game && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetNumberOfCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No Video Games currently out of stock" << endl;
    }
    if (!IsItemListEmpty(dvd)) {
        int count = 0;
        cout << "DVDs: " << endl;
        for (int i = 0; i < listOfDVDs.size(); i++) {
            if (listOfItem[i]->GetRentalType() == dvd && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetNumberOfCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No DVDs currently out of stock" << endl;
    }
    if (!IsItemListEmpty(record)) {
        int count = 0;
        cout << "Movie Record: " << endl;
        for (int i = 0; i < listOfRecords.size(); i++) {
            if (listOfItem[i]->GetRentalType() == record && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetNumberOfCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No Records currently out of stock" << endl;
    }
}
int Shop::GetItemIndex(eRentalType type) {
    int count = 0, index = 0;
    vector<int> position;
    cout << "the type of the item is: " << type << endl;
    switch (type) {
    case 1:
        if (!IsItemListEmpty(game)) {
            for (int i = 0; i < listOfItem.size(); i++) {
                cout << "item type: " << listOfItem[i]->GetRentalType() << endl;
                cout << "enum type: " << game << endl;
                if (listOfItem[i]->GetRentalType() == game) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    case 2:
        if (!IsItemListEmpty(dvd)) {
            for (int i = 0; i < listOfItem.size(); i++) {
                cout << "item type: " << listOfItem[i]->GetRentalType() << endl;
                cout << "enum type: " << dvd << endl;
                if (listOfItem[i]->GetRentalType() == dvd) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    case 3:
        if (!IsItemListEmpty(record)) {
            for (int i = 0; i < listOfRecords.size(); i++) {
                cout << "item type: " << listOfItem[i]->GetRentalType() << endl;
                cout << "enum type: " << record << endl;
                if (listOfItem[i]->GetRentalType() == record) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    }
    return count != 0 ? position[index - 1] : -1;
}
int Shop::GetItemIndex(eRentalType type, bool onlyAvailableItem) {
    int index = 0, count = 0;
    vector<int> position;
    switch (type) {
    case 1:
        if (!IsItemListEmpty(game)) {
            for (int i = 0; i < listOfItem.size(); i++) {
                if (listOfItem[i]->GetRentalType() == game && listOfItem[i]->GetNumberOfCopies() != 0 && listOfItem[i]->GetRentalStatus() != true) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    case 2:
        if (!IsItemListEmpty(dvd)) {
            for (int i = 0; i < listOfItem.size(); i++) {
                if (listOfItem[i]->GetRentalType() == dvd && listOfItem[i]->GetNumberOfCopies() != 0 && listOfItem[i]->GetRentalStatus() != true) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    case 3:
        if (!IsItemListEmpty(record)) {
            for (int i = 0; i < listOfRecords.size(); i++) {
                if (listOfItem[i]->GetRentalType() == record && listOfItem[i]->GetNumberOfCopies() != 0 && listOfItem[i]->GetRentalStatus() != true) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
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
        break;
    }
    return count != 0 ? position[index - 1] : -1;
}

void Shop::UpdateItem(eRentalType type) {
    int index = GetItemIndex(type);

    if (index == -1) return;
    if (type == game) {
        listOfVideoGames[index].SetTitle();
        listOfVideoGames[index].SetLoanType();
        listOfVideoGames[index].SetNumberOfCopies();
        listOfVideoGames[index].SetRentalFee();
        listOfVideoGames[index].SetRentalStatus();
    }
    else if (type == dvd) {
        listOfDVDs[index].SetTitle();
        listOfDVDs[index].SetLoanType();
        listOfDVDs[index].SetNumberOfCopies();
        listOfDVDs[index].SetRentalFee();
        listOfDVDs[index].SetRentalStatus();
        listOfDVDs[index].SetGenre();
    }
    else if (type == record) {
        listOfRecords[index].SetTitle();
        listOfRecords[index].SetLoanType();
        listOfRecords[index].SetNumberOfCopies();
        listOfRecords[index].SetRentalFee();
        listOfRecords[index].SetRentalStatus();
        listOfRecords[index].SetGenre();
    }
}

void Shop::DeleteItem(eRentalType type) {
    int index = GetItemIndex(type);
    if (index == -1) return;
    listOfItem.erase(listOfItem.begin() + index);

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
        for (int i = 0; i < listOfUsers.size(); i++) {
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
        for (int i = 0; i < listOfUsers.size(); i++) {
            if (listOfUsers[i].GetRole() == role)
                cout << ++count << ". ID: " << listOfUsers[i].GetId()
                << ", Name: " << listOfUsers[i].GetName()
                << ", Address: " << listOfUsers[i].GetAddress()
                << ", Phone: " << listOfUsers[i].GetPhone() << endl;
        }
    }
    if (count == 0) cout << "No users with this role available" << endl;
}

void Shop::RentItem(eRentalType type) {
    bool onlyAvailableItem = true;
    bool isLendingItem = true;
    int indexForItem = GetItemIndex(type, onlyAvailableItem);
    if (indexForItem == -1) return;
    int indexForUser = GetUserIndex();
    if (indexForUser == -1) return;

    if (listOfUsers[indexForUser].GetRole() == "Guest" &&
        listOfVideoGames[indexForItem].GetLoanType() == "2-day") {
        cout << "Only Regular and VIP member can borrow 2-day Video items" << endl;
        return;
    }
    listOfItem[indexForItem]->SetAvailableCopies(isLendingItem);
    listOfUsers[indexForUser].AddRental(listOfVideoGames[indexForItem].GetId());

}

Item* Shop::FindItemById(string itemId) {
    for (int i = 0; i < listOfItem.size(); i++) {
        if (listOfItem[i]->GetId() == itemId) {
            return listOfItem[i];
        }
    }
    return NULL;
}

User* Shop::FindUserById(string itemId) {
    for (int i = 0; i < listOfUsers.size(); i++) {
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
    for (int i = 0; i < listOfUsers.size(); i++) {
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

    for (int i = 0; i < u.GetListOfRentals().size(); i++) {
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
    string chosenReturnedItemId = listOfUsers[indexForUser].ReturnRental(indexForItem);
    FindItemById(chosenReturnedItemId)->updateValueAfterReturning();
}

void Shop::SearchForItem(int type) {
    if (type == 1) {
        string input;
        do {
            cout << "Id (Format: Ixxx-yyyy (x, y are number)): ";
            cin >> input;
            if (!Item::CheckId(input))
                cout << "Invalid format. Format: Ixxx-yyyy (x, y are number). Try again" << endl;
        } while (!Item::CheckId(input));
        Item* item = FindItemById(input);
        if (!item)
            cout << "Can not find item that match the description" << endl;
        else
            DisplayItemInfo(item, 1);
    }
    else if (type == 2) {
        int count = 0;
        string title;
        cin.ignore();
        cout << "Title of the item: ";
        getline(cin, title);
        for (int i = 0; i < listOfItem.size(); i++) {
            if (listOfItem[i]->GetTitle() == title) {
                DisplayItemInfo(listOfItem[i], ++count);
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
    }
    else if (type == 2) {
        int count = 0;
        string username;
        cin.ignore();
        cout << "User's name: ";
        getline(cin, username);
        for (int i = 0; i < listOfUsers.size(); i++) {
            if (listOfUsers[i].GetName() == username) {
                DisplayUserInfo(listOfUsers[i], ++count);
            }
        }
        if (count == 0)
            cout << "Can not find user that match the description" << endl;
    }
}
void Shop::StockFromStorage(string filename) {
    cout << "stocking up products from storage" << endl;
    // create an in file stream to read the file
    ifstream coeff(filename);
    // check if file can be opened or not
    if (coeff) {
        // the while loop ends then the end of the file is reached
        while (!coeff.eof()) {
            string id, title, rentalTypeString, loanType, copies, rentalFee, genreString, line;
            eRentalType type = game;
            eGenre genre = action;

            getline(coeff, line);
            // Vector of string to save tokens
            vector <string> tokens;
            // stringstream class check1
            stringstream check1(line);
            string intermediate;

            while (getline(check1, intermediate, ','))
            {
                tokens.push_back(intermediate);
            }
            id = tokens[0];
            title = tokens[1];
            rentalTypeString = tokens[2];
            loanType = tokens[3];
            copies = tokens[4];
            rentalFee = tokens[5];
            if (rentalTypeString == "Game") {
                type = game;
            }
            else if (rentalTypeString == "Record") {
                type = record;
            }
            else if (rentalTypeString == "DVD") {
                type = dvd;
            }
            Item* itemPtr = NULL;
            if (tokens.size() == 7) {
                genreString = tokens[6];
                if (genreString == "Action") {
                    genre = action;
                }
                else if (genreString == "Horror") {
                    genre = horror;
                }
                else if (genreString == "Drama") {
                    genre = drama;
                }
                else if (genreString == "Comedy") {
                    genre = comedy;
                }
                SpecialItem item(id, title, type, loanType, stoi(copies), stof(rentalFee), genre);
                itemPtr = &item;
            }
            else if (tokens.size() == 6) {
                Item videoGame(id, title, type, loanType, stoi(copies), stof(rentalFee));
                itemPtr = &videoGame;
            }
            /*
            cout << "from reading " << itemPtr->GetId() << ", "
                << itemPtr->GetTitle() << ", "
                << itemPtr->GetRentalType() << ", "
                << itemPtr->GetLoanType() << ", "
                << itemPtr->GetNumberOfCopies() << ", "
                << itemPtr->GetRentalFee() << endl;
            */

            DisplayItemInfo(itemPtr, 0);
            listOfItem.push_back(itemPtr);

        }
    }
    else {
        cout << "Error in File: Can not open file !!!" << endl;
    }
    coeff.close();
}