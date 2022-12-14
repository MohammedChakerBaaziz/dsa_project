#include <iostream>
#include"item.h"
#include "user.h"
#include"AVL.h"
#include "MembersHash.h"

int main()
{
    HashTable<long long int> members;
    //test avl
    AvlTree avlt;
    Item item1("BABY FOOD",3,30,1000);
    Item item2("BATTERIES",2,15,6000);
    Item item3("BBQ",1,170,200);
    Item item4("BISCUITS",10,120,300);
    Item item5("BREAD",34,15,100);
    avlt.insert(item1);
    avlt.insert(item2);
    avlt.insert(item3);
    avlt.insert(item4);
    avlt.insert(item5);
    avlt.printTree();
    User temp("chaker", 1234567, 12, 2023, "alger");
    temp.command(avlt, members);
    if(temp.ismember(members))
    {
        cout << "he is  \n\n\n";
        temp.command(avlt, members);
    }
}

/* missions left :
- wait for the csv file of user & items to generalize and test the remaining functions
- wait to fix the problem of one input is missed
- fix the two remaining small problems in the do while loops of the command fucntion
- use what's done here with the bst and hashmap data structures
- comment the file to explain
- check what they pushed and the setters getters of the user class
- make the file version of the command function
- use the hash table of the members in the avl and bst parts
*/

// work on the display, each time he buys, clear the sreen and show if he wants to continue with the total price, then if yes show items with input
