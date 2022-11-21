#include <iostream>
#include"bst.h"
#include<vector>
#include <fstream>
#include <string>
#include <queue>
#include"item.h"
#include "bst.h"
#include "MembersHash.h"
#include "user.h"
using namespace std;

int main()
{
    HashTable<long long int> members;
    Binarysearchtree t1;
    ifstream readitems("test.txt");
    if (!readitems.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    Item itemvect [62];
    int j=0;
    while (!readitems.eof())
    {

        getline(readitems>>ws, n, ',');
        getline(readitems>>ws, I, ',');
        getline(readitems>>ws, un, ',');
        getline(readitems>>ws,qua, '\n');
        int number=std::stoi(un);
        int number2=std::stoi(qua);
        itemvect[j].set_all(n,I,number,number2);
        j++;
    }
    cout<<"is the tree empty "<<t1.isempty()<<endl;
    for(int i=0; i<62; i++)
    {
        t1.insertelement(itemvect[i]);
    }
    t1.in_order(t1.getroot());


    readitems.close();
    User temp("chaker", 1234, 12, 2023, "algiers");
   int topg= temp.command(t1, members);
   cout<<topg<<endl;
}
