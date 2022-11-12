#ifndef BST_H
#define BST_H
#include"item.h"

class Node{
    Item data;
    Node* left;
    Node* right;
    Node();
    Node(Item &obj){
        this->data=obj;
    }
    friend class Binarysearchtree;
};
class Binarysearchtree{
    private:
        Node* root;
        //utility function
         Node * findMinimum( Node*ptr )const
{
    if( ptr == nullptr )
        return nullptr;
    if( ptr->left == nullptr )
        return ptr;
    return findMinimum( ptr->left );
 }

    public:
        Binarysearchtree();
        void setroot(Node*p);
        Node* getroot();
        Node* insertelement(Node*,Item&);
        Node* delete_item(Node*,Item&);
        bool contain(Node*, Item&)const;
        void in_order(Node*)const;

};
#endif // BST_H
