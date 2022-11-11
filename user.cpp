#include <iostream>
#include <fstream>
#include <cctype>
#include "user.h"
#include "item.h"
#include "QuadraticProbingUser.h"


using namespace std;


bool User::ismember () const
{
    return Members.contains(*this);
}

int User::command (HashTable<Item>& items) 
{
    int totalPrice = 0;
    char check = 'y';
    while (check != 'n')
    {
        Item item; //object
        string name;
        cout << "Enter the name of the item \n";
        getline(cin >> ws,name);
        item.setname(name);
        if(items.contains(item))
        {
            // maybe we should show informations of the item i.e. quantity & unit price
            int quantity =0;
            cout << "Enter the quantity you want to buy \n";
            while (quantity <= 0)
            {
                cin >> quantity;
            }
            if(item.getquantity()>=quantity)
            {
                // add to the file csv
                totalPrice += quantity * item.getunitprice();
            }
            // treat else cases (maybe he re-enter)
            // treat the case if after the command an the quantity of element is 0
        }
        cout << "ENTER Y: ADD NEW ITEM\n"
             << "      N: FINISH COMMAND\n";
        do {
            cin.get(check);
        }while(check != 'n' && check != 'y' && check != 'N' && check != 'Y');
        if (!islower(check))
        {
            check = tolower(check);
        }
        // case if the total price is higher than what the card contains : cannot be treated because we don't have the card's system and any additional data
        
        // send to adress
    }
    // confirm command and dispaly it
    // return the file or send to email
}


bool User::addMember(int totalprice)
{
    if(totalprice >= 100000)
    {
        return Members.insert(*this);
    }
    return false;
}


// add method of dealing with the queue
// methods of items
