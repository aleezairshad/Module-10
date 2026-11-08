#include"bTree.h"
using namespace std;

bTree::bTree() : insertion(0) {}

template<class Item>
void insert(binary_tree_node<Item>*& node, const Item& value)
{
    if (node == NULL)
    {
        node = new binary_tree_node<Item>(value);
    }
    else if (value < node->getData())
    {
        insert(node->getLeft(), value);
    }
    else if (value > node->getData())
    {
        insert(node->getRight(), value);
    }
}

