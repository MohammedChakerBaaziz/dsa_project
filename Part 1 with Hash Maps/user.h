#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "ItemsHash.h"
#include "item.h"
#include "MembersHash.h"
using namespace std;

template <class T>
class HashTableItems;

class User {
    private :
        string Name;
        long long int cardId;
        string experyMonth;
        int experyYear;
        string homeAdress;
    public :
        User (string name, long long int id, string month, int year, string adress) : Name(name), cardId(id), experyMonth(month), experyYear(year), homeAdress(adress) {cout <<"user \t" << this->Name << "\t" << this->cardId << "  is added \n";}
        bool ismember(HashTable<long long int>&) const;
        int command(HashTableItems<long long int>&, HashTable<long long int>&);
        bool addMember(HashTable<long long int>&,int);
        friend void commandFile(HashTableItems<long long int>&,HashTable<long long int>&);
};
/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */
