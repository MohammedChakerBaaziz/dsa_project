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
        bool ismember() const;
        int command(HashTable<Item>&);
        bool addMember(int);   
        friend class HashTable;
        static HashTable<User> Members;
        void Set_name(string namo);
        void set_card_id(string cardo);
        void set_expery_month(int month);
        void set_experyYear(int year);
        void sethomeadress(string home);

        string getname();
        string getcardid();
        int getexperyMonth();
        int getexperyYear();
        string gethomeAdress();

};

/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */

#endif