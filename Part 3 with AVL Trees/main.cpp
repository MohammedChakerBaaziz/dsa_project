#include <iostream>
#include"item.h"
#include"AVL.h"
#include<vector>
#include <fstream>
using namespace std;
int main()
{
    //test avl
    AvlTree avlt;
    /*Item item1("BABY FOOD","3",30,1000);
    Item item2("BATTERIES","2",15,6000);
    Item item3("BBQ","1",170,200);
    Item item4("BISCUITS","10",120,300);
    Item item5("BREAD","34",15,100);
    avlt.insert(item1);
    avlt.insert(item2);
    avlt.insert(item3);
    avlt.insert(item4);
    avlt.insert(item5);*/
    ifstream readitemsz("avltest.txt");

    if (!readitemsz.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    Item itemvect[63];
    Item* itr=itemvect;
    while (!(readitemsz.eof()))
    {
        getline(readitemsz>>ws, n, ',');
        getline(readitemsz>>ws, I, ',');
        getline(readitemsz>>ws, un, ',');
        getline(readitemsz>>ws,qua, '\n');
        itr->set_all(n,I,std::stoi(un),std::stoi(qua));
        itr++;
    }
   for(int i=0;i<63;i++)
    {
        avlt.insert(itemvect[i]);
    }
     avlt.printTree();
    readitemsz.close();
}
