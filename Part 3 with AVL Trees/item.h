#ifndef item_h
#define item_h

#include <iostream>
#include <string>
#include <queue>
using namespace std;


class Item{
    private :
        string Name;
        long long int Id;
        int UnitPrice;
        int Quantity;

    public:
        Item();
        Item(string & ,long long int &  ,int &,int &);        //copy constructure
        Item(string&&,long long int&&,int&&,int&&);    //move constructure
        ~Item();                                //destructure
        string get_name();
        long long int get_id();
        int get_Unit_price();
        int get_quantity();
        void set_name(string );
        void set_id(long long int);
        void set_unit_price(int);
        void set_Quantity(int);
        void set_all(string,long long int,int,int);
        friend class Binarysearchtree;
};




#endif
