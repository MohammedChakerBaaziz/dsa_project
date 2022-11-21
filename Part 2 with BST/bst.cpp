#include "bst.h"
#include<iostream>
#include<set>
#include"item.h"
Binarysearchtree::Binarysearchtree()//the default constructor
{
    root=NULL;
}
void Binarysearchtree::setroot(Node* p)
{
    //set the root
    root=p;
}

bool Binarysearchtree::isempty()
{
    if(root==nullptr)
    {
        return true ;
    }
    else
    {
        return false;
    }
}

Node* Binarysearchtree::getroot()
{
    //get the root
    return root;
}
Node* Binarysearchtree::insertelement(Node*r,Item &obj)
{
    //function to add items to the storage.
    if(r==NULL)
    {
        Node* head= new Node(obj);
        r=head;
        r->data=obj;
    }
    else
    {
        long long  int value1=std::stoi(obj.get_id());
        long long int value2=std::stoi(r->data.get_id());
        if(value1<value2)
        {
            r->left=insertelement(r->left,obj);
        }
        else
        {
            r->right=insertelement(r->right,obj);
        }
    }
    return r;
};
void Binarysearchtree::insertelement(Item& obj)
{
    root=insertelement(root,obj);
}
void Binarysearchtree::in_order(Node* root)
{
    //display items
    if(root==NULL)
    {
        return ;
    }
    in_order(root->left);
    std::cout<<root->data.get_name()<<"---"<<root->data.get_id()<<std::endl;
    in_order(root->right);
}
Node* Binarysearchtree::delete_item(Node* root,Item &obj)
{
    if (root== NULL) // Empty Tree
        return NULL;
    if(std::stoi(root->data.get_id())==std::stoi(obj.get_id()))
    {
        delete root;
    }
    else if (std::stoi(obj.get_id()) < std::stoi(root->data.get_id())) // Item exists in left sub tree
        root->left = delete_item(root->left, obj);
    else if (std::stoi(obj.get_id())  > std::stoi(root->data.get_id())) // item exists in right sub tree
        root->right =delete_item(root->right, obj);
    else
    {
        if (root->left == NULL && root->right == NULL) // leaf node
            root = NULL;
        else if (root->left != NULL && root->right == NULL) // one child on the left
        {
            root->data.get_id() = root->left->data.get_id();
            delete root->left;
            root->left = NULL;
        }
        else if (root->left == NULL && root->right != NULL) // one child on the right
        {
            root->data.get_id() = root->right->data.get_id();
            delete root->right;
            root->right = NULL;
        }
        else
        {
            Node* maxi_node = Findmax(root->left);
            root->data.get_id() = maxi_node->data.get_id();
            root->left=	delete_item(root->left, maxi_node->data);

        }

    }
    return root;
}



Node* Binarysearchtree::contain(Node* r, Item obj)
{
    if( r == nullptr )
        return nullptr;
    else
    {
        long long  int value1=std::stoi(r->data.get_id());
        long long   int value2=std::stoi(obj.get_id());

        if (value1==value2)
            return r;

        else if( value2 < value1 )
        {
            return contain( r->left,obj );
        }
        else if( value1 < value2 )
        {

            return contain( r->right,obj );
        }
    }
}
bool Binarysearchtree:: searchit(Item HA)
{
    Node* this_node=contain(root,HA);

    if(this_node==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
