#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "QuadraticProbingUser.h"
#include "item.h"
using namespace std;


class User {
    private :
        string Name;
        string cardId;
        int experyMonth;
        int experyYear;
        string homeAdress;
    public :
        explicit User(string name, string cardId, int month, int year, string adress) : Name(name), cardId(cardId), homeAdress(adress)
        {
            while (month <=0 || month > 12)
            {
                cout << "Month entered is invalid, re-enter a correct month \n";
                cin >> this->experyMonth;
            }
            while(experyYear < 2022)
            {
                cout << "The expery year is incorrect or the card is dead, enter a correct or a valid year \n";
                cin >> this->experyYear;
            }
        }
        bool ismember() const;
        int command(HashTable<Item>&);
        bool addMember(int);   
        friend class HashTable;
        static HashTable<User> Members;
};

/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */

#endif