#include<iostream>
#include<string>
#include"input.h"
#include"binary_tree node.h"
using namespace std;



char TreeOfStringMenu();

void DisplayTree(binary_tree_node<string>* node);
void DisplayBranches(binary_tree_node<string>* node, string prefix, bool isLast);
void DeleteTree(binary_tree_node<string>*& node);

// Global tree
binary_tree_node<string>* root = nullptr;

int main()
{
	binary_tree_node<string>* root_ptr = NULL;
	do
	{

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
			cout << "\n\tTree container of integers\n";
			TreeContainerOfIntegers(root_ptr);
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

char TreeOfStringMenu()
{

    do
    {
        system("cls");
        cout << "\n\t1> Tree of strings";
        cout << "\n\t" << string(75, char(205));

        cout << "\n\tA> Created root (trunk) with no leaf.";
        cout << "\n\tB> Root (trunk) grows two branches: branch #1 and branch #2.";
        cout << "\n\tC> Branches grows leaves.";
        cout << "\n\tD>. Left leaf sprouts and yields a fruit (apple).";
        cout << "\n\tE> Right leaf sprouts and yields two fruits (orange and coconut).";
        cout << "\n\tF> Delete tree.";
        cout << "\n\tG> Display current tree.";
        cout << "\n\t" << string(75, char(196));
        cout << "\n\t0> Exit";
        cout << "\n\t" << string(75, char(205));
        char option = toupper(inputChar("\n\tOption: ", static_cast<string>("0abcdefg")));

        switch (option)
        {
        case 'A':
        {

            //creates the root of the trunk
            DeleteTree(root);

            root = new binary_tree_node<string>("trunk");

            cout << "\n\t\tRoot (trunk) created.\n";

            break;
        }

        case 'B':
        {
            cout << "\n\t\tOption B selected.\n";

            if (root == nullptr)
            {
                cout << "\n\t\tERROR: Create the root first.\n";
                break;
            }

            // Create two branches
            if (root->left() == nullptr)
            {
                root->set_left(new binary_tree_node<string>("branch #1"));
            }

            if (root->right() == nullptr)
            {
                root->set_right(new binary_tree_node<string>("branch #2"));
            }

            cout << "\n\t\tRoot grows two branches.\n";

            break;
        }
        case 'C':
        {
            cout << "\n\t\tOption C selected.\n";

            if (root == nullptr || root->left() == nullptr || root->right() == nullptr)
            {
                cout << "\n\t\tERROR: Create branches first.\n";
                break;
            }

            // Grow leaves on both branches
            if (root->left()->left() == nullptr)
            {
                root->left()->set_left(new binary_tree_node<string>("left leaf"));
            }

            if (root->right()->right() == nullptr)
            {
                root->right()->set_right(new binary_tree_node<string>("right leaf"));
            }

            cout << "\n\t\tBranches grow leaves.\n";

            break;
        }
        case 'D':
        {
            cout << "\n\t\tOption D selected.\n";

            if (root == nullptr || root->left() == nullptr || root->left()->left() == nullptr)
            {
                cout << "\n\t\tERROR: Grow leaves first.\n";
                break;
            }

            // Left leaf produces an apple
            binary_tree_node<string>* leaf = root->left()->left();

            if (leaf->left() == nullptr)
            {
                leaf->set_left(new binary_tree_node<string>("apple"));
            }

            cout << "\n\t\tLeft leaf yields an apple.\n";

            break;
        }
        case 'E':
        {
            cout << "\n\t\tOption E selected.\n";

            if (root == nullptr || root->right() == nullptr || root->right()->right() == nullptr)
            {
                cout << "\n\t\tERROR: Grow leaves first.\n";
                break;
            }

            // Right leaf produces two fruits
            binary_tree_node<string>* leaf = root->right()->right();

            if (leaf->left() == nullptr)
            {
                leaf->set_left(new binary_tree_node<string>("orange"));
            }

            if (leaf->right() == nullptr)
            {
                leaf->set_right(new binary_tree_node<string>("coconut"));
            }

            cout << "\n\t\tRight leaf yields orange and coconut.\n";

            break;
        }
        case 'F':
        {
            cout << "\n\t\tOption F selected.\n";

            DeleteTree(root);

            cout << "\n\t\tTree deleted.\n";

            break;
        }
        case 'G':
        {
            cout << "\n\t\tOption G selected.\n";

            cout << "\n\t\tCurrent tree:\n";

            DisplayTree(root);

            break;
        }

        case '0':
        {
            return 0;
        }
        }


        cout << "\n";
        system("pause");
        system("cls");


    } while (true);
}
void DisplayTree(binary_tree_node<string>* node)
{
    if (node == nullptr)
    {
        cout << "\n\tThe tree is empty.\n";
        return;
    }

    cout << "\n\t" << node->data() << "\n";

    if (node->left() != nullptr)
    {
        DisplayBranches(node->left(), "", node->right() == nullptr);
    }

    if (node->right() != nullptr)
    {
        DisplayBranches(node->right(), "", true);
    }
}
void DisplayBranches(binary_tree_node<string>* node, string prefix, bool isLast)
{
    if (node == nullptr)
    {
        return;
    }

    cout << "\t" << prefix;

    if (isLast)
    {
        cout << char(192) << string(3, char(196));
    }
    else
    {
        cout << char(195) << string(3, char(196));
    }

    cout << " " << node->data() << "\n";

    if (isLast)
    {
        prefix += "    ";
    }
    else
    {
        prefix += char(179);
        prefix += "   ";
    }

    if (node->left() != nullptr)
    {
        DisplayBranches(node->left(), prefix, node->right() == nullptr);
    }

    if (node->right() != nullptr)
    {
        DisplayBranches(node->right(), prefix, true);
    }
}
void DeleteTree(binary_tree_node<string>*& node)
{
    if (node == nullptr)
    {
        return;
    }
    binary_tree_node <string>* left = node->left();
    binary_tree_node <string>* right = node->right();

    DeleteTree(left);
    DeleteTree(right);

    delete node;
    node = nullptr;

}




void TreeContainerOfIntegers(binary_tree_node<string>*& root_ptr)
{
	binary_tree_node<int>* root = NULL;
	int choice;
	do
	{
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
		}
		break;
		case 2:
		{
			cout << "\n\tCurrent tree:\n";
			print_tree("", root, false, true, false);
		}
		break;
		case 3:
		{
			delete_tree(root);
			root = NULL;
			cout << "\n\tTree deleted.\n";
		}
		break;
		case 0:
			return;
		default:
			cout << "\n\tInvalid choice. Please try again.\n";
			break;
		}
	} while (true);
}
