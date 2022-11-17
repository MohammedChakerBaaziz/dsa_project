#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class Item
{
private:
    string Name;
    string Id;
    int UnitPrice;
    int Quantity;

public:
    Item();
    Item(string &, string &, int &, int &);     // copy constructure
    Item(string &&, string &&, int &&, int &&); // move constructure
    ~Item();                                    // destructure
    string get_name();
    string get_id();
    int get_Unit_price();
    int get_quantity();
    void set_name(string);
    void set_id(string);
    void set_unit_price(int);
    void set_Quantity(int);
    void set_all(string,string,int,int);
    // Item operator=(Item &);
    friend class Binarysearchtree;
};
string Item::get_name()
{
    return Name;
};
string Item::get_id()
{
    return Id;
};
int Item::get_Unit_price()
{
    return UnitPrice;
};
int Item::get_quantity()
{
    return Quantity;
};
void Item::set_all(string n,string i,int un=100,int q=0)
{
    set_name(n);
    set_id(i);
    set_unit_price(un);
    set_Quantity(q);
};
void Item::set_name(string name1)
{
    Name = name1;
};

void Item::set_id(string id1)
{
    Id = id1;
};

void Item::set_Quantity(int quanti)
{
    Quantity = quanti;
};

void Item::set_unit_price(int price)
{
    UnitPrice = price;
};
Item::Item(){};
Item::Item(string &name, string &id, int &unitprice, int &quantity)
{
    Name = name;
    Id = id;
    UnitPrice = unitprice;
    Quantity = quantity;
};
Item::Item(string &&name, string &&id, int &&unitprice, int &&quantity)
{
    Name = std::move(name);
    Id = std::move(id);
    UnitPrice = std::move(unitprice);
    Quantity = std::move(quantity);
};
/*Item Item::operator=(Item &obj)
{
    Item nwobj;
    nwobj.Name=obj.Name;
    nwobj.Id=obj.Id;
    nwobj.Quantity=obj.Quantity;
    nwobj.UnitPrice=obj.UnitPrice;
    return nwobj;
}*/
Item::~Item()
{
    Name = " ";
    Id = " ";
    UnitPrice = 0;
    Quantity = 0;
}

int main()
{

    ifstream readitems("read.csv");

    if (!readitems.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    std::vector<Item> itemvect(62);
    auto itr=itemvect.begin();
    while (readitems.good())
    {

            getline(readitems>>ws, n, ',');
            getline(readitems>>ws, I, ',');
            getline(readitems>>ws, un, ',');
            getline(readitems>>ws,qua , '\n');
            itr->set_all(n,I,std::stoi(un),std::stoi(qua));
            itr++;
        /*getline(readitems,name,',');
        getline(readitems,ID,',');
        getline(readitems,unit_price,',');
        getline(readitems,quantity,'\n');*/
    }
    for(itr=itemvect.begin();itr!=itemvect.end(); itr++){
        std::cout<<itr->get_name()<<"----"<<itr->get_id()<<"----"<<itr->get_Unit_price()<<"----"<<itr->get_quantity()<<std::endl;

    }

    readitems.close();
}