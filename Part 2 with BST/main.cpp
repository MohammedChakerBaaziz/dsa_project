#include <iostream>
#include"bst.h"
#include<vector>
using namespace std;

int main()
{
    cout<<"break point"<<endl;
    Binarysearchtree t1;
    /*Item item1("BABY FOOD","3",30,1000);
    Item item2("BATTERIES","2",15,6000);
    Item item3("BBQ","1",170,200);
    Item item4("BISCUITS","10",120,300);
    Item item5("BREAD","34",15,100);
    cout<<"break point"<<endl;

       p=t1.insertelement(p,item1);
       t1.insertelement(p,item2);
       t1.insertelement(p,item3);
       t1.insertelement(p,item4);*/

    Node* p=NULL;
    t1.setroot(p);
    ifstream readitems("test.txt");

    if (!readitems.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    Item itemvect[63];
    Item* itr=itemvect;

    while (!readitems.eof()-1)
    {

        getline(readitems>>ws, n, ',');
        getline(readitems>>ws, I, ',');
        getline(readitems>>ws, un, ',');
        getline(readitems>>ws,qua, '\n');
        itr->set_all(n,I,std::stoi(un),std::stoi(qua));
        itr++;
    }
    for(int i=0;i<63;i++)
    {
        std::cout<<i<<std::endl;
        std::cout<<itemvect[i].get_name()<<std::endl;
    }
    std::cout<<itemvect[0].get_name();
        cout<<"break point 8"<<endl;

        //t1.in_order(p);
        cout<<"break point 9 "<<endl;

    readitems.close();


}
