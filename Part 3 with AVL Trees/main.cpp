#include <iostream>
#include"item.h"
#include"AVL.h"

int main()
{
    //test avl
    AvlTree avlt;
    Item item1("BABY FOOD","3",30,1000);
    Item item2("BATTERIES","2",15,6000);
    Item item3("BBQ","1",170,200);
    Item item4("BISCUITS","10",120,300);
    Item item5("BREAD","34",15,100);
    avlt.insert(item1);
    avlt.insert(item2);
    avlt.insert(item3);
    avlt.insert(item4);
    avlt.insert(item5);
    avlt.printTree();
    avlt.remove(item2);
    std::cout<<"after remove batteries"<<std::endl;
    avlt.printTree();

}