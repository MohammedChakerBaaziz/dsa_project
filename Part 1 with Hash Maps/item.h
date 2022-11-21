#pragma once

#include <iostream>
#include <string>
#include <queue>
#include "ItemsHash.h"
using namespace std;

template <class T>
class HashTableItem;

class Item{
    private :
        string Name;
        long long int Id;
        int UnitPrice;
        int Quantity;

    public:
        Item();
        Item(const Item& a)
        {
            this->Name = a.Name;
            this->Id = a.Id;
            this->Quantity = a.Quantity;
            this->UnitPrice = a.UnitPrice;
        }
        Item(string & ,long long int&  ,int &,int &);        //copy constructure
        Item(string&&,long long int&&,int&&,int&&);    //move constructure
        ~Item();                                //destructure
        string get_name();
        size_t get_id();
        int get_Unit_price();
        int get_quantity();
        void set_name(string );
        void set_id(long long int);
        void set_unit_price(int);
        void set_Quantity(int);
        void set_all(string,long long int,int,int);
        Item operator= (const Item& a)
        {
            this ->Id = a.Id;
            this ->Name = a.Name;
            this ->UnitPrice = a.UnitPrice;
            this ->Quantity = a.Quantity;
            return *this;
        }
        Item operator= (Item&& a)
        {
            this ->Id = std::move(a.Id);
            this ->Name = std::move(a.Name);
            this ->UnitPrice = std::move(a.UnitPrice);
            this ->Quantity = std::move(a.Quantity);
            return *this;
        }
        
        template <class T>
        friend class HashTableItems;
};




