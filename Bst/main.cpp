#include <iostream>
#include"bst.h"
#include<vector>
using namespace std;

int main()
{
 Binarysearchtree t1;
 Item item1("BABY FOOD","17302664",30,1000);
 Item item2("BATTERIES","3601530",15,6000);
 Item item3("BBQ","1004775",170,200);
 Item item4("BISCUITS","16700260",120,300);
 Item item5("BREAD","34600011",15,100);
    Node* p=NULL;
    t1.setroot(p);
    p=t1.insertelement(p,item1);
    t1.insertelement(p,item2);
    t1.insertelement(p,item3);
    t1.insertelement(p,item4);
    std::cout<<t1.contain(p,item5);
    std::cout<<std::endl;
    t1.in_order(p);
    std::cout<<" after delete"<<std::endl;
    t1.delete_item(p,item1);
    std::cout<<std::endl;
    t1.in_order(p);

}
