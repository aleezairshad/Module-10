#include<iostream>
#include<string>
#include"input.h"
#include"binary_tree node.h"
using namespace std;

void TreeContainerOfIntegers(binary_tree_node<string>*& root_ptr);

int main()
{
	binary_tree_node<string>* root_ptr = NULL;
	do
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 10: Trees by Jacob O and Victor(12/4/26)"
			<< "\n\t" << string(90, char(205))
			<< "\n\t\t1> Tree of strings"
			<< "\n\t\t2> Tree container of integers"
			<< "\n\t\t3> Animal guessing game"
			<< "\n\t" << string(90, char(196))
			<< "\n\t\t0> Quit"
			<< "\n\t" << string(90, char(205));
		int choice = inputInteger("\n\tEnter your choice: ", 0, 3);
		switch (choice)
		{
		case 1:
		{
			// Tree of strings
		}
		break;
		case 2:
		{
			TreeContainerOfIntegers(root_ptr);
			break;
		}
		break;
		case 3:
		{
			// Animal guessing game
		}
		break;
		case 0:
			return 0;
		default:
			cout << "\n\tInvalid choice. Please try again.\n";
			break;
		}
	} while (true);
	
}

void TreeContainerOfIntegers(binary_tree_node<string>*& root_ptr)
{
	binary_tree_node<int>* root = NULL;
	int choice;
	do
	{
		system("cls");
		cout << "\n\tTree Container of Integers"
			<< "\n\t" << string(90, char(205))
			<< "\n\t\t1> Insert an integer"
			<< "\n\t\t2> Print the tree"
			<< "\n\t\t3> Delete the tree"
			<< "\n\t" << string(90, char(196))
			<< "\n\t\t0> Return to main menu"
			<< "\n\t" << string(90, char(205));
		choice = inputInteger("\n\tEnter your choice: ", 0, 3);
		switch (choice)
		{
		case 1:
		{
			int value = inputInteger("\n\tEnter an integer to insert: ");
			insert(root, value);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\n\tCurrent tree:\n";
			print_tree("", root, false, true, false);
			system("pause");
			break;
		}
		case 3:
		{
			delete_tree(root);
			root = NULL;
			cout << "\n\tTree deleted." << endl;
			system("pause");
			break;
		}
		case 0:
			return;
		default:
			cout << "\n\tInvalid choice. Please try again." << endl;
			system("pause");
			break;
		}
	} while (true);
}
