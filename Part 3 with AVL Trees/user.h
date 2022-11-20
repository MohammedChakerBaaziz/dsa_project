#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "AVL.h"
#include "item.h"
#include "MembersHash.h"
using namespace std;


class User {
    private :
        string Name;
        long long int cardId;
        int experyMonth;
        int experyYear;
        string homeAdress;
    public :
        User (string name, long long int id, int month, int year, string adress) : Name(name), cardId(id), experyMonth(month), experyYear(year), homeAdress(adress) {cout <<"user \t" << this->Name << "\t" << this->cardId << "  is added \n";}
        bool ismember(HashTable<long long int>&) const;
        int command(AvlTree&, HashTable<long long int>&);
        bool addMember(HashTable<long long int>&,int);
        void commandFile(AvlTree&);   
};

/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */

#endif