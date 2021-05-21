#include "Shop.h"
#include <fstream>
#include "Item.h"
#include "SpecialItem.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Shop::Shop() {}

void Shop::AddItem(eRentalType type) {
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
        listOfItem.push_back(new Item(videoGame.GetId(), videoGame.GetTitle(), videoGame.GetRentalType(), videoGame.GetLoanType(), videoGame.GetNumberOfCopies(), videoGame.GetRentalFee() ));
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
        listOfItem.push_back(new SpecialItem(item.GetId(), item.GetTitle(), item.GetRentalType(), item.GetLoanType(), item.GetNumberOfCopies(), item.GetRentalFee(), item.GetGenre() ));
    }
    
    cout << "current list size: " << listOfItem.size() << endl;
    cout << "added item: " << endl;
    //DisplayItemInfo(itemPtr, 00);
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

}
void Shop::ShowAllItems(eRentalType type) {
    if (!IsItemListEmpty(type)) {
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
            Item* item = listOfItem[i];
            //cout << "show item NAME: " << listOfItem[i]->GetTitle() << endl;
            cout << "show item type: " << listOfItem[i]->GetRentalType() << endl;
            cout << "show enum type: " << type << endl;
            
            if (listOfItem[i]->GetRentalType() == type) {
                DisplayItemInfo(listOfItem[i], i + 1);
            }
        }
    }
}
void Shop::ShowAllOutOfStockItems() {
    cout << "Out of stock items: " << endl;
    if (!IsItemListEmpty(game)) {
        int count = 0;
        cout << "Video Games: " << endl;
        for (int i = 0; i < listOfItem.size(); i++) {
            if (listOfItem[i]->GetRentalType() == game && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetAvailableCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No Video Games currently out of stock" << endl;
    }
    if (!IsItemListEmpty(dvd)) {
        int count = 0;
        cout << "DVDs: " << endl;
        for (int i = 0; i < listOfItem.size(); i++) {
            if (listOfItem[i]->GetRentalType() == dvd && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetAvailableCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No DVDs currently out of stock" << endl;
    }
    if (!IsItemListEmpty(record)) {
        int count = 0;
        cout << "Movie Record: " << endl;
        for (int i = 0; i < listOfItem.size(); i++) {
            if (listOfItem[i]->GetRentalType() == record && listOfItem[i]->GetRentalStatus() == true && listOfItem[i]->GetAvailableCopies() == 0)
                DisplayItemInfo(listOfItem[i], ++count);
        }
        if (count == 0) cout << "No Records currently out of stock" << endl;
    }
}
int Shop::GetItemIndex(eRentalType type) {
    int count = 0, index = 0;
    vector<int> position;
    cout << "the type of the item is: " << type << endl;
    if (!IsItemListEmpty(type)) {
        for (int i = 0; i < listOfItem.size(); i++) {
            cout << "item type: " << listOfItem[i]->GetRentalType() << endl;
            cout << "enum type: " << type << endl;
            if (listOfItem[i]->GetRentalType() == type) {
                position.push_back(i);
                count++;
                DisplayItemInfo(listOfItem[i], count);
            }
        }
        if (count == 0) {
            switch (type) {
            case 1:
                cout << "No video game is Exist in store";
                return -1;
                break;
            case 2:
                cout << "No dvd is Exist in store";
                return -1;
                break;
            case 3:
                cout << "No movie record is Exist in store";
                return -1;
                break;
            }
        }
        do {
            cout << "Select an item's number: ";
            cin >> index;
            if (!(index >= 1 && index <= count))
                cout << "Invalid option. Try again" << endl;
        } while (!(index >= 1 && index <= count));
    }
    return count != 0 ? position[index - 1] : -1;
}
int Shop::GetItemIndex(eRentalType type, bool fullyAvailableItem) {
    int count = 0, index = 0;
    vector<int> position;
    cout << "the type of the item is: " << type << endl;
    if (!IsItemListEmpty(type)) {
        for (int i = 0; i < listOfItem.size(); i++) {
            cout << "item type: " << listOfItem[i]->GetRentalType() << endl;
            cout << "enum type: " << type << endl;
            if (fullyAvailableItem == true) {
                if (listOfItem[i]->GetRentalType() == type && listOfItem[i]->GetNumberOfCopies() == listOfItem[i]->GetAvailableCopies() && listOfItem[i]->GetRentalStatus() != true) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
                }
            }
            else {
                if (listOfItem[i]->GetRentalType() == type && listOfItem[i]->GetNumberOfCopies() != 0 && listOfItem[i]->GetRentalStatus() != true) {
                    position.push_back(i);
                    count++;
                    DisplayItemInfo(listOfItem[i], count);
                }
            }
        }
        if (fullyAvailableItem == true && count == 0) {
            switch (type) {
            case 1:
                cout << "No video game is Fully available";
                return -1;
                break;
            case 2:
                cout << "No dvd is Fully available";
                return -1;
                break;
            case 3:
                cout << "No movie record is Fully available";
                return -1;
                break;
            }
        }
        else if (fullyAvailableItem == false && count == 0) {
            switch (type) {
            case 1:
                cout << "No video game is currently available";
                return -1;
                break;
            case 2:
                cout << "No dvd is currently available";
                return -1;
                break;
            case 3:
                cout << "No movie record is currently available";
                return -1;
                break;
            }
        }
        do {
            cout << "Select an item's number: ";
            cin >> index;
            if (!(index >= 1 && index <= count))
                cout << "Invalid option. Try again" << endl;
        } while (!(index >= 1 && index <= count));
    }
    return count != 0 ? position[index - 1] : -1;
}

void Shop::UpdateItem(eRentalType type) {
    int index = GetItemIndex(type);
    if (index == -1) return;
    if (type == game) {
        listOfItem[index]->SetTitle();
        listOfItem[index]->SetLoanType();
        listOfItem[index]->SetNumberOfCopies(false);
        listOfItem[index]->SetRentalFee();
        listOfItem[index]->SetRentalStatus();
    }
    else if (type == dvd || type == record) {
        listOfItem[index]->SetTitle();
        listOfItem[index]->SetLoanType();
        listOfItem[index]->SetNumberOfCopies(false);
        listOfItem[index]->SetRentalFee();
        listOfItem[index]->SetRentalStatus();
        listOfItem[index]->SetGenre();
    }
}
void Shop::DeleteItem(eRentalType type) {
    int index = GetItemIndex(type, true);
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
    bool fullyAvailableItem = false;
    bool isLendingItem = true;
    int indexForItem = GetItemIndex(type, fullyAvailableItem);
    if (indexForItem == -1) return;
    int indexForUser = GetUserIndex();
    if (indexForUser == -1) return;

    if (listOfUsers[indexForUser].GetRole() == "Guest" &&
        listOfItem[indexForItem]->GetLoanType() == "2-day") {
        cout << "Only Regular and VIP member can borrow 2-day Video items" << endl;
        return;
    }
    listOfItem[indexForItem]->SetAvailableCopies(isLendingItem);
    listOfUsers[indexForUser].AddRental(listOfItem[indexForItem]->GetId());

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
        if (!item) {
            cout << "Can not find item that match the description" << endl;
        }
        else {
            DisplayItemInfo(item, 1);
        }
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
        if (count == 0) {
            cout << "Can not find item that match the description" << endl;
        }
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
            eRentalType rentalType = game;
            eGenre genre = action;
            getline(coeff, line);
            // Vector of string to save tokens
            vector <string> tokens;
            // stringstream class check1
            stringstream check1(line);
            string intermediate;
            while (getline(check1, intermediate, ',')) {
                tokens.push_back(intermediate);
            }
            cout << "size of line vector: " << tokens.size() << endl;
            id = tokens[0];
            title = tokens[1];
            rentalTypeString = tokens[2];
            loanType = tokens[3];
            copies = tokens[4];
            rentalFee = tokens[5];
            if (rentalTypeString == "Game") {
                rentalType = game;
            }
            else if (rentalTypeString == "Record") {
                rentalType = record;
            }
            else if (rentalTypeString == "DVD") {
                rentalType = dvd;
            }
           
            // Item videoGame();
            // SpecialItem item();
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
                SpecialItem item(id, title, rentalType, loanType, stoi(copies), stof(rentalFee), genre);
                listOfItem.push_back(new SpecialItem(id, title, rentalType, loanType, stoi(copies), stof(rentalFee), genre));
            }
            else if (tokens.size() == 6) {
                Item videoGame(id, title, rentalType, loanType, stoi(copies), stof(rentalFee));
                listOfItem.push_back(new Item(id, title, rentalType, loanType, stoi(copies), stof(rentalFee)));
            }
    
            
        }
    }
    else {
        cout << "Error in File: Can not open file !!!" << endl;
    }
    coeff.close();
}