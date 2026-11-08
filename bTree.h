#pragma once
#include "binary_tree node.h"
using namespace std;

//template class
template <class Item>
class bTree
{
private:
	binary_tree_node<Item>* root; //for the root
	int countAccumulator;
	void insertBST(binary_tree_node<Item>*& node, const Item& value);//this is the function decide where to insert
	//helper function for the traversal
	void preOrderBST(binary_tree_node<Item>* node) const;
	void inOrderBST(binary_tree_node<Item>* node) const;
	void postOrderBST(binary_tree_node<Item>* node) const;
public:
	bTree();
	~bTree();
	void insert(const Item& value); //this insert function is what the user uses in main
	int  count() const;
	bool search(const Item& value) const;
	void preOrderTraversal() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;
	void deleteTree();
};