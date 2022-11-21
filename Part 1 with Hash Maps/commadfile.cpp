// leader : Hamaidi Mohammed Idriss Hamadi
// command fucntion with files part 1 (also for parts 2 and 3 with small changes in parameters) 

#include <iostream>
#include <fstream>
#include <map>
#include "ItemsHash.h"
#include "Item.h"
#include "user.h"
#include "MembersHash.h"
using namespace std;


using std::cout;

/*
   this is the command function which was supposed to work with files so that it reads the data set and generate the commands of the user
   The way of fuctionning : explained in the report
*/
void commandFile(HashTableItems<long long int>& items,HashTable<long long int>& members)
{
    cout << "test 2\n";
    struct userDetail
    {
        User object;
        int lineInCSV;
        userDetail(User a,int b) : object(a), lineInCSV(b) {}
    };
    int escape=0;
    int currentLine=0;
    queue<User> member;
    queue<User> nonMembers;
    queue<int> currentLineMember;
    queue<int>currentLineNon;
    
    fstream users;
    users.open("userz.txt",fstream::in);
    if (!users.is_open())
        cout << "problem when openning the file \n";
    ofstream myFile;
    while (!(users.eof()))
    { escape++;
        cout << "test 45\n";
        string line;
        string name;
        string Id;
        string month;
        string year;
        string address;
        getline(users>>ws, name, ',');
        getline(users>>ws, Id, ',');
        getline(users>>ws,address, ','); //what if he doesn't have a command
        getline(users>>ws, month, ',');
        getline(users>>ws, year, ',');
        getline(users>>ws,line , '\n');
        long long int id = std::stoi(Id);
        cout << "YEar :\t" << year << endl;
        int Year = std::stoi(year);
        cout << "test 2\n";
        User tempObj = User(name, id, month, Year, address);
        //int current = currentLine;
        //userDetail temp = userDetail(tempObj, current);
        if(members.contains(id))
        {
            member.push(tempObj); //may cause a problem
            currentLineMember.push(currentLine);
                    cout<<"breakpoint push"<<endl;

        }
        else
        {
            nonMembers.push(tempObj);
            currentLineNon.push(currentLine);

        }
        if(escape==1149)
        {
            break;
        }
    }

    cout << "test \n";

    int counter =0;
    while(!member.empty())
    {
        cout << "test 3\n";
        users.clear();
        users.seekg(0);
        User temp = member.front();
        int lineNow = currentLineMember.front();
        string fileName = temp.Name + ".csv";
        myFile.open (fileName);
        cout << "test 4\n";
        myFile << temp.Name << "\n";
        myFile << temp.cardId << "\n";
        myFile << temp.homeAdress << "\n";
        int totalPrice = 0;
        string line;
        cout << "test 5\n";
        while(getline(users>>ws, line, '\n')&& counter != lineNow)
        {
            counter++;
        }

        int counter2 = 0;
        cout << "test 6\n";
        while(getline(users>>ws, line, ',') && counter2 < 5)
        {
            counter2 ++;
        }
        cout << "test 7\n";
        char ch;
        string itemId;
        string quantity;
        long long int idItem;
        int quant;
        bool check = true;
        do {
            getline(users>>ws, itemId, ',');
            getline(users>>ws, quantity, ',');
            idItem = std::stoi(itemId);
            quant = std::stoi(quantity);
            cin.get(ch);
            cout << "test 8\n"; // may cause a problem
            if(items.contains(items.findPos(idItem)))
            {
            //  item = items;
                // maybe we should show informations of the item i.e. quantity & unit price
                Item* itemInHash = &items.objects[items.findPos(idItem)];
                std::cout << "The quantity in the store is\t" << itemInHash->get_quantity() << endl
                    << "The unit price \t" << itemInHash->get_Unit_price() <<endl;

                // fix this while loop in case the user enters a string
                cout << "test 10\n";
                if(itemInHash->get_quantity()>=quant)
                {
                    cout << "test 11\n";
                    myFile << itemInHash->get_name() << "," << quant << "," << itemInHash->get_Unit_price() << "," << quant*itemInHash->get_Unit_price() << "\n";
                    cout << "test 12\n";
                    totalPrice += quant * itemInHash->get_Unit_price();
                    itemInHash->set_Quantity(itemInHash->get_quantity()-quant);
                    cout << "test 13\n";
                    if(itemInHash->get_quantity() == 0)
                    {
                        std::cout << "Item is no longer available in the store \n";
                        
                    } 
               }
                else 
                {
                    std::cout << "The quantity the store has is less than your command \n";
                }
            }
            counter =0;
        }while(ch != '\n');
    }
    counter =0;
    int i =0;
    int totalPrice = 0;
            cout<<"breakpoint last"<<endl;

    while(!nonMembers.empty())
    {
        cout<<"breakpoint 1"<<endl;
        users.clear();
        users.seekg(0);
                cout<<"breakpoint 2"<<endl;

        User temp = nonMembers.front();
                cout<<"breakpoint 3"<<endl;

        int lineN = currentLineNon.front();
                cout<<"breakpoint 4"<<endl;

        string fileName = to_string(temp.cardId) + ".csv";
        cout << fileName;
        myFile.open(fileName, ios::out);
        myFile << temp.Name << "\n";
        myFile << temp.cardId << "\n";
        myFile << temp.homeAdress << "\n";
        string line;
        while(counter++ < lineN-1)
        {
            getline(users>>ws, line, '\n');
            counter++;
        }

        int counter2 = 0;
        while(getline(users>>ws, line, ',') && counter2 < 4)
        {
            counter2 ++;
        }
        string itemId;
        string quantity;
        long long int idItem;
        int quant;
        bool check = true;
        string lineA;
        while (getline(users>>ws, lineA, ';'))
        {
            cout << lineA<< endl;
        
            int i=0;
            char character = lineA[0];
            cout << character << endl;
            while(static_cast<char>(lineA[i]) != ';')
            {
                itemId ="";
                quantity = "";
        cout << "test 67\n";
        cout<<"break point 1"<<endl;
        int k=0;

                while(lineA[i] != ',')
                {
                    k++;
                    itemId += static_cast<char>(lineA[i]);
                    character = int(lineA[++i]) - '0';
                    cout << int(character) << endl;
                    cout << itemId << endl;
                            cout<<"break point 2"<<endl;
i++;
                }
                cout<<"item is "<<itemId<<endl;
            
                cout << itemId << endl;
                i++;
                cout<<i<<endl;
                // exit(0);
                while(lineA[i] != ',')
                {
                    quantity += static_cast<char>(lineA[i]);
                            cout<<"break point 3"<<endl;

                }
                                cout <<"quantity is " <<quantity << endl;
    exit(0);


                idItem = std::stoi(itemId);
                quant = std::stoi(quantity);
                Item Itemp;
                Itemp.set_id(idItem);
                Itemp.set_Quantity(quant);
                        cout<<"break point 4"<<endl;
    //exit(0);

                if(items.contains(Itemp.get_id()))
                {
                        exit(0);

                            cout<<"break point 5"<<endl;

                /*  item = items; */
                    // maybe we should show informations of the item i.e. quantity & unit price
                    std::cout << "\nmembers \t" << member.size() << "\nNon members \t" << nonMembers.size() << endl;
                    Item* itemInHash = &items.objects[items.findPos(idItem)];
                    std::cout << "The quantity the user wants to buy :\t" << Itemp.get_quantity() << endl;
                    std::cout << "The quantity in the store is\t" << itemInHash->get_quantity() << endl
                        << "The unit price \t" << itemInHash->get_Unit_price() <<endl;
        cout<<"break point 6"<<endl;

                    // fix this while loop in case the user enters a string

                    if(itemInHash->get_quantity()>=quant)
                    {
                                cout<<"break point 7"<<endl;

                        cout << "teste \n" << endl;
                        myFile << itemInHash->get_name() << "," << quant << "," << itemInHash->get_Unit_price() << "," << quant*itemInHash->get_Unit_price() << "\n";

                        totalPrice += quant * itemInHash->get_Unit_price();
                        itemInHash->set_Quantity(itemInHash->get_quantity()-quant);

        /*                 if(itemInHash->get_quantity() == 0)
                        {
                            std::cout << "Item is no longer available in the store \n";
                            
                        } */
                                cout<<"break point 8"<<endl;

                    }
                    else 
                    {
                                cout<<"break point 9"<<endl;

                        std::cout << "The quantity the store has is less than your command \n";
                    }
                }


                character =int(lineA[++i]) - '0';
            }
            counter =0;
        }
        myFile << totalPrice << "\n";
        myFile.close();
        nonMembers.pop();
        currentLineNon.pop();
    }
    cout << "test 456\n";
    myFile.close();
    

}

    // Simple main
int main( )
{

    HashTableItems<long long int> items;
    ifstream readitems("test.txt");
    if (!readitems.is_open())
        std::cout << "ERROR: File Open" << '\n';

    string n;
    string I;
    string un;
    string qua;
    Item itemvect [63];
    int j=0;
    while (!readitems.eof())
    {

        getline(readitems>>ws, n, ',');
        getline(readitems>>ws, I, ',');
        getline(readitems>>ws, un, ',');
        getline(readitems>>ws,qua, '\n');
        int number=std::stoi(un);
        int number2=std::stoi(qua);
        long long int id= std::stoi(I);
        itemvect[j].set_all(n,id,number,number2);
        j++;
    }
    //cout<<"is the tree empty "<<items.<<endl;
    for(int i=0;i<63;i++)
    {
       items.insert(itemvect[i].get_id(), itemvect[i]);
    }
    readitems.close();
    HashTable<long long int> members;
 Item a("coffee", 101, 234, 34);
    Item b("drink", 202, 244, 94);
    Item c("water", 303, 224, 14);
    Item d("sandwich", 404, 274, 74);
    HashTableItems<long long int> items;
    items.insert(a.get_id(), a);
    items.insert(b.get_id(), b);
    items.insert(c.get_id(), c);
    items.insert(d.get_id(), d);

    cout << items.objects.size() << endl;
    for (int i=0;i<items.objects.size();i++)
    {
        cout << items.objects[i].get_id() << endl;
    }
    User temp("chaker",123,"12",2022,"n'gaous");
    temp.command(items, members);
    //commandFile(items, members);

}


// if expery date is invalid


// define the delete
// define the items' display
