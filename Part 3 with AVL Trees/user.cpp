#include <iostream>
#include <fstream>
#include <cctype>
#include "user.h"
#include "item.h"
#include "AVL.h"


using namespace std;


bool User::ismember (HashTable<long long int>& members) const
{
    return members.contains(this->cardId);
}

int User::command (AvlTree& items, HashTable<long long int>& members) 
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
        long long int id;
        cout << "Enter the id of the item \n";
        cin >> id;
        item.set_id(id);

        if(items.contains(item))
        {
           /*  item = items; */
            // maybe we should show informations of the item i.e. quantity & unit price
            AvlTree::AvlNode* itemInTree = items.getItem(id);
            int quantity =0;
            cout << "Enter the quantity you want to buy \n";
            cout << "The quantity in the store is\t" << itemInTree->element.get_quantity() << endl
                 << "The unit price \t" << itemInTree->element.get_Unit_price() <<endl;

// fix this while loop in case the user enters a string
            do {
                cin >> quantity;
            }while(quantity < 0);

            if(itemInTree->element.get_quantity()>=quantity)
            {
                myFile << itemInTree->element.get_name() << "," << quantity << "," << itemInTree->element.get_Unit_price() << "," << quantity*itemInTree->element.get_Unit_price() << "\n";

                totalPrice += quantity * itemInTree->element.get_Unit_price();
                itemInTree->element.set_Quantity(itemInTree->element.get_quantity()-quantity);

                if(itemInTree->element.get_quantity() == 0)
                {
                    cout << "Item is no longer available in the store \n";
                    items.removeItem_Avl(item, items.root);
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
        } while (check != 'n'&& check != 'N'&& check != 'y' && check != 'Y');
        

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


void User::commandFile(AvlTree& items)
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
