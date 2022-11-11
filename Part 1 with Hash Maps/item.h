#ifndef item_h
#define item_h

#include <iostream>
#include <string>
#include <queue>
using namespace std;


class Item{
    private :
        string Name;
        string Id;
        int UnitPrice;
        int Quantity;
    
    public:
        Item();
        Item(string & ,string &  ,int &,int &);        //copy constructure
        Item(string&&,string&&,int&&,int&&);    //move constructure
        ~Item();                                //destructure
        string get_name();
        string get_id();
        int get_Unit_price();
        int get_quantity();
        void set_name(string );
        void set_id(string);
        void set_unit_price(int);
        void set_Quantity(int);
        static HashTable<Item> Items; //we need to make the hashTable works with the item class
};

// we need a constructor with values + in the constructor it directly inserts in the hashmap



#endif