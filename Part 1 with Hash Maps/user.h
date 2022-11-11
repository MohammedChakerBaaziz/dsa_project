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
};

/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */

#endif