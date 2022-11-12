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
    std::cout<<r->data.get_id()<<std::endl;
    in_order(r->right);
}
Node* Binarysearchtree::delete_item(Node* root,Item &obj)
	{
		if (root== NULL) // Empty Tree
			return NULL;
			if(root->data.get_id()==obj.get_id())
			{
			    delete root;
			}
		else if (obj.get_id() < root->data.get_id()) // Item exists in left sub tree
			root->left = delete_item(root->left, obj);
		else if (obj.get_id()  > root->data.get_id()) // item exists in right sub tree
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


