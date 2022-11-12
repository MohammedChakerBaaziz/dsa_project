#include <iostream>
#include"bst.h"
#include<vector>
using namespace std;

int main()
{
 Binarysearchtree t1;
 Item item1("BABY FOOD","3",30,1000);
 Item item2("BATTERIES","2",15,6000);
 Item item3("BBQ","1",170,200);
 Item item4("BISCUITS","10",120,300);
 Item item5("BREAD","34",15,100);
    Node* p=NULL;
    t1.setroot(p);
    p=t1.insertelement(p,item1);
    t1.insertelement(p,item2);
    t1.insertelement(p,item3);
    t1.insertelement(p,item4);
    t1.in_order(p);
    std::cout<<" after delete"<<std::endl;
    t1.delete_item(p,item3);
    std::cout<<std::endl;
    t1.in_order(p);

}
