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
Node* Binarysearchtree::getroot(){
    //get the root
    return root;
}
Node* Binarysearchtree::insertelement(Node* p,Item &obj)
{
    //function to add items to the storage.
    if(p==NULL){
        p=new Node(obj);
        p->left=p->right=NULL;
    }
    else if(obj.get_id()<p->data.get_id())
    {
            p->left=insertelement(p->left,obj);
    }
    else{
            p->right=insertelement(p->right,obj);
    }
    return p;
};
void Binarysearchtree::in_order(Node* r)const{
    //display items
    if(r==NULL){
        return ;
    }
    in_order(r->left);
    std::cout<<r->data.get_name()<<std::endl;
    in_order(r->right);
}
/*Node* Binarysearchtree::delete_item(Node* root,Item &obj)
{
    if(!(contain(root,obj)))
        {
        return nullptr;
        }
    else
{
    if( root == nullptr )
        return nullptr; // Item not found; do nothing
    if( obj.get_id() < root->data.get_id() )
        delete_item( root->left,obj  );
    else if( root->data.get_id() < obj.get_id() )
        delete_item( root->right, obj );
    else if( root->left != nullptr && root->right != nullptr ) // Two children
    {
        root->data.get_id() = findMinimum( root->right )->data.get_id();
        delete_item( root->right, root->data );
    }
    else
    {
        Node *oldNode = root;
        root = ( root->left != nullptr ) ? root->left : root->right;
        delete oldNode;
        oldNode=nullptr;

    }
}
}*/
Node* Binarysearchtree::delete_item(Node* root,Item &obj)
{
    if(root == NULL) {
        std::cout<<"Node to be deleted is not present.!"<<std::endl;
        return root;
    }
    else if(obj.get_id() < root->data.get_id()) {
        root->left = delete_item(root->left, obj);
    } else if(obj.get_id()> root->data.get_id()) {
        root->right = delete_item(root->right, obj);
    } else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL) {
            Node* temporary = root;
            root = root->right;
            delete temporary;
        }
        else if(root->right == NULL) {
            Node* temporary = root;
            root = root->left;
            delete temporary;
        } else {
            Node* temporary = findMinimum(root->right);
            root->data = temporary->data;
            root->left = delete_item(root->right, temporary->data);
        }
    }
    return root;
}
bool Binarysearchtree::contain(Node* root, Item& obj)const
{
    if( root == nullptr )
        return false;

    else if( obj.get_id() < root->data.get_id() )
        return contain( root->left,obj );

    else if( root->data.get_id() < obj.get_id() )
        return contain( root->right,obj );

    else
        return true;
}

