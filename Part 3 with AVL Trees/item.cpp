#include "item.h"
#include <iostream>
#include <string>
string Item::get_name(){
return Name;
};
string Item::get_id(){
return Id;
};
int Item::get_Unit_price(){
    return UnitPrice;
};
int Item::get_quantity(){
    return Quantity;
};

void Item::set_name(string name1){
Name=name1;
};

void Item::set_id(string id1){
Id=id1;
};

void Item::set_Quantity(int quanti){
Quantity=quanti;
};

void Item::set_unit_price(int price){
UnitPrice=price;
};
Item::Item(){};
Item::Item(string &name, string &id,int & unitprice,int & quantity){
    Name=name;
    Id=id;
    UnitPrice=unitprice;
    Quantity=quantity;
};
void Item::set_all(string n,string i,int un=100,int q=0)
{
    set_name(n);
    set_id(i);
    set_unit_price(un);
    set_Quantity(q);
};
Item::Item(string &&name, string &&id,int && unitprice,int && quantity){
    Name=std::move(name);
    Id=std::move(id);
    UnitPrice=std::move(unitprice);
    Quantity=std::move(quantity);
};
Item::~Item(){
    Name=" ";
    Id=" ";
    UnitPrice=0;
    Quantity=0;
};
