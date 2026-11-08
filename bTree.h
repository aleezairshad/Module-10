#pragma once
#include "binary_tree node.h"
using namespace std;

class bTree
{
private:
	int insertion;
public:
	bTree();
	void insert(binary_tree_node<int>*& node, const int& value);
};