#include <iostream>
#include <fstream>
#include <cctype>
#include "user.h"
#include "item.h"
#include "QuadraticProbingUser.h"


using namespace std;


string::user get_quantity()
{
    return quantity;
}
string::user getcardid()
{
    return cardId;
}
int::user getexperyMonth()
 {
    return experyMonth;
 }
int::user getexperyYear()
 {
    return experyYear;
 }
string::user gethomeAdress()
 {
    return homeAdress;
 }

void::user set_card_id(string card)
{
    cardId=card;
}
void::user set_expery_month(int month)
{
    experyMonth=month;
}
void::user set_experyYear(int year)
{
    experyYear=year;
}

void::user set_name(string namoo)
{
    name=namoo;
}
void::user sethomeadress(string home)
{
    homeAdress=address;
}


bool User::ismember () const
{
    return Members.contains(*this);
}

int User::command (HashTable<Item>& items) 
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
        string name;
        cout << "Enter the name of the item \n";
        getline(cin >> ws,name);
        item.set_name(name);
        if(items.contains(item))
        {
            // maybe we should show informations of the item i.e. quantity & unit price
            int quantity =0;
            cout << "Enter the quantity you want to buy \n";
            do
            {
                cin >> quantity;
            }while (quantity <= 0);
            if(item.get_quantity()>=quantity)
            {
                myFile << name << "," << quantity << "," << item.get_Unit_price() << "," << quantity*item.get_Unit_price() << "\n";
                totalPrice += quantity * item.get_Unit_price();
                item.set_Quantity(item.get_quantity()-quantity);
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
        cout << "ENTER Y: ADD NEW ITEM\n"
             << "      N: FINISH COMMAND\n";
        do 
        {
            cin.get(check);
        }while(check != 'n' && check != 'y' && check != 'N' && check != 'Y');
        if (!islower(check))
        {
            check = tolower(check);
        }
        // case if the total price is higher than what the card contains : cannot be treated because we don't have the card's system and any additional data
    }
    myFile << totalPrice << "\n";
    myFile.close();
    cout << "Command finsihed successfully\n"
         << "The command will be sent to your Home address\n";
    return totalPrice;
    // confirm command and dispaly it
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
