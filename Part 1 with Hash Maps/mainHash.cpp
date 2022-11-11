#include <iostream>
#include <vector>
#include "user.h"
#include <item.h>


using namespace std;

int main()
{

    User me("chaker", "1235423", 12, 2023, "Algiers");
    Item potato;
    potato.set_id("1213230");
    potato.set_name("potato");
    potato.set_Quantity(2343);
    potato.set_unit_price(120);

    // generator of the items stock instead of adding them one by one (csv of items and read it)
}