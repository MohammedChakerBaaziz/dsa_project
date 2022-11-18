#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "AVL.h"
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
        User (string name, string id, int month, int year, string adress) : Name(name), cardId(id), experyMonth(month), experyYear(year), homeAdress(adress) {cout <<"user \t" << this->Name << "\t" << this->cardId << "  is added \n";}
        /* bool ismember() const; */
        int command(AvlTree&);
        /* bool addMember(int);  */  
};

/* class Member
{
    public : 
        HashTable<User>* membersTable = new HashTable<User>();
}; */

#endif