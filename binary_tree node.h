#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class Item>
class binary_tree_node
{
private:
    Item data;
    binary_tree_node* left;
    binary_tree_node* right;

public:

    //constructor
    binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
    {
        data = init_data;
        left = init_left;
        right = init_right;
    }

    
    Item& getData()
    {
        return data;
    }

    void setData(const Item& new_data)
    {
        data = new_data;
    }

    binary_tree_node*& getLeft()
    {
        return left;
    }

    void setLeft(binary_tree_node* new_left)
    {
        left = new_left;
    }

    binary_tree_node*& getRight()
    {
        return right;
    }

    void setRight(binary_tree_node* new_right)
    {
        right = new_right;
    }

    bool isLeaf() const
    {
        return (left == NULL && right == NULL);
    }

};

template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
    if (leaf == NULL)
        return;

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;

}

template<class Item>
void print_tree(const string& prefix, binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
    if (node != NULL)
    {
        cout << prefix;
        if (!root)
        {
            if (isLeft)
            {
                if (node->isLeaf())
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else
            {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false,true);
    }
}