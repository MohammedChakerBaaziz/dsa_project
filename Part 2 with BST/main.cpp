#include <iostream>
#include"bst.h"
#include<vector>
#include <fstream>
#include <string>
#include <queue>
#include"item.h"
#include "bst.h"
using namespace std;

int main()
{
    Binarysearchtree t1;
    ifstream readitems("test.txt");
    if (!readitems.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    Item itemvect [63];
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
    for(int i=0;i<63;i++)
    {
       t1.insertelement(itemvect[i]);

    }
        t1.in_order(t1.getroot());
    cout<<"is the tree empty "<<t1.isempty()<<endl;

    readitems.close();
}
