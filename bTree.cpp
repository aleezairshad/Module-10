#include"bTree.h"
using namespace std;

//constructor
template<class Item>
bTree<Item>::bTree()
{
    root = nullptr;
    countAccumulator = 0;
}

//insert helper for insert function
template<class Item>
void bTree<Item>::insertBST(binary_tree_node<Item>*& node, const Item& value)
{
    if (node == NULL)
    {
        node = new binary_tree_node<Item>(value);
        countAccumulator++;
    }
    else if (value < node->getData())
    {
        insertBST(node->getLeft(), value);
    }
    else
    {
        insertBST(node->getRight(), value);
    }
}

//pre-order traversal helper
template<class Item>
void bTree<Item>::preOrderBST(binary_tree_node<Item>* node) const
{
    if (node == nullptr)
    {
        return;
    }

    cout << "\n\t\t" << node->getData();

    preOrderBST(node->getLeft());
    preOrderBST(node->getRight());
}

//in-order traversal helper
template<class Item>
void bTree<Item>::inOrderBST(binary_tree_node<Item>* node) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrderBST(node->getLeft());
    cout << "\n\t\t" << node->getData();
    inOrderBST(node->getRight());
}

//post-order traversal helper
template<class Item>
void bTree<Item>::postOrderBST(binary_tree_node<Item>* node) const
{
    if (node == nullptr)
    {
        return;
    }
    postOrderBST(node->getLeft());
    postOrderBST(node->getRight());
    cout << "\n\t\t" << node->getData();
}

//insert function
template<class Item>
void bTree<Item>::insert(const Item& value)
{
    insertBST(root, value);
}

//pre-order traversal
template<class Item>
void bTree<Item>::preOrderTraversal() const
{
    preOrderBST(root);
}

//in-order traversal
template<class Item>
void bTree<Item>::inOrderTraversal() const
{
    inOrderBST(root);
}

//post-order traversal
template<class Item>
void bTree<Item>::postOrderTraversal() const
{
    postOrderBST(root);
}

//count function
template<class Item>
int bTree<Item>::count() const
{
    return countAccumulator;
}

//search function
template<class Item>
bool bTree<Item>::search(const Item& value) const
{
    binary_tree_node<Item>* current = root; //copy the address of the root to search, I don't want to modify the root ptr
    while (current != nullptr)
    {
        if (value == current->getData())
        {
            return true;
        }
        else if(value < current->getData())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }

    return false;
}


//delete tree to use in the destructor, it's like a helper for destructor
template<class Item>
void bTree<Item>::deleteTree()
{
    delete_tree(root);
    root = nullptr;
    countAccumulator = 0;
}

//destructor
template <class Item>
bTree<Item>::~bTree()
{
    delete_tree(root);
}

template class bTree<int>;
