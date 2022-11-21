#include <iostream>
#include <fstream>
#include <cctype>
#include "user.h"
#include "item.h"
#include "bst.h"


using namespace std;


bool User::ismember (HashTable<long long int>& members) const
{
    return members.contains(this->cardId);
}

int User::command (Binarysearchtree& items, HashTable<long long int>& members)
{
    ofstream myFile;
    string fileName = this->Name + ".csv";
    myFile.open (fileName);
    myFile << this->Name << "\n";
    myFile << this->cardId << "\n";
    myFile << this->homeAdress << "\n";
    int totalPrice = 0;
    char check = 'y';
    while (check != 'n')
    {
        Item item; //object
        string id;
        cout << "Enter the id of the item \n";
        getline(cin>>ws, id);
        item.set_id(id);

        if(items.searchit(item))
        {
            cout<<"item foumd"<<endl;
            /*  item = items; */
            // maybe we should show informations of the item i.e. quantity & unit price
            Node* itemInTree = items.getItem(id);
            int quantity =0;
            cout << "Enter the quantity you want to buy \n"<<endl;
            cout << "The quantity in the store is\t" << itemInTree->data.get_quantity() << endl;
            cout  << "The unit price \t" << itemInTree->data.get_Unit_price() <<endl;

// fix this while loop in case the user enters a string
            do
            {
                cin >> quantity;
            }
            while(quantity < 0);

            if(itemInTree->data.get_quantity()>=quantity)
            {
                myFile << itemInTree->data.get_name() << "," << quantity << "," << itemInTree->data.get_Unit_price() << "," << quantity*itemInTree->data.get_Unit_price() << "\n";

                totalPrice += quantity * itemInTree->data.get_Unit_price();
                cout<<"break point 1"<<endl;
                itemInTree->data.set_Quantity(itemInTree->data.get_quantity()-quantity);
                cout<<"break point 2 "<<itemInTree->data.get_quantity()<<endl;

                if(itemInTree->data.get_quantity() == 0)
                {
                    cout << "Item is no longer available in the store \n";
                    items.delete_item(items.root, item);
                }
            }
            else
            {
                cout << "The quantity the store has is less than your command \n";
            }
        }
        else
        {
            cout << "Item is not founded \n";
        }
        cout << "\nThe total price is :\t" << totalPrice << endl
             << "\nENTER Y: ADD NEW ITEM\n"
             << "      N: FINISH COMMAND\n";

        do
        {
            cin.get(check);
        }
        while (check != 'n'&& check != 'N'&& check != 'y' && check != 'Y');


        if (!islower(check))
        {
            cin >> ws;
            check = tolower(check);
        }
        // case if the total price is higher than what the card contains : cannot be treated because we don't have the card's system and any additional data
    }
    if(totalPrice >= 100000)
    {
        bool entered = this->addMember(members, totalPrice);
        cout << "is he entered ?\t" << entered << endl;
    }
    myFile << totalPrice << "\n";
    myFile.close();
    cout << "Command finsihed successfully\n"
         << "\nThe total price is :\t" << totalPrice << endl
         << "\nThe command will be sent to your Home address\n";
    return totalPrice;
    // confirm command and dispaly it
}


void User::commandFile(Binarysearchtree& items)
{
    ofstream myFile;
    string fileName = this->Name + ".csv";
    myFile.open (fileName);
    myFile << this->Name << "\n";
    myFile << this->cardId << "\n";
    myFile << this->homeAdress << "\n";
    int totalPrice = 0;

}

bool User::addMember(HashTable<long long int>& members, int totalprice)
{
    if(totalprice >= 100000)
    {
        return members.insert(this->cardId);
    }
    return false;
}


// add method of dealing with the queue
// methods of items

