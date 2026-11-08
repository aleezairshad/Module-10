#include<iostream>
#include<string>
#include<fstream>
#include"input.h"
#include"Animal.h"
#include"binary_tree node.h"
#include"bTree.h"
using namespace std;

void TreeContainerOfIntegers(bTree& bt);
char TreeOfStringMenu();
char TreeOfStringMenu();
void DisplayTree(binary_tree_node<string>* node);
void DisplayBranches(binary_tree_node<string>* node, string prefix, bool isLast);
void DeleteTree(binary_tree_node<string>*& node);
void TreeContainerOfIntegers();
void animalGuessingGame();
char animalGuessingGameMenu();


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
			TreeOfStringMenu();
		}
		break;
		case 2:
		{
			bTree bt;
			TreeContainerOfIntegers(bt);
			break;
		}
		break;
		case 3:
		{
			animalGuessingGame();
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

//option 2
void TreeContainerOfIntegers(bTree& bt)
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
			bt.insert(root, value);
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

//option 1
char TreeOfStringMenu()
{
    binary_tree_node<string>* root = NULL;

    do
    {
        system("cls");
        cout << "\n\t1> Tree of strings";
        cout << "\n\t" << string(75, char(205));

        cout << "\n\tA> Created root (trunk) with no leaf.";
        cout << "\n\tB> Root (trunk) grows two branches: branch #1 and branch #2.";
        cout << "\n\tC> Branches grows leaves.";
        cout << "\n\tD> Left leaf sprouts and yields a fruit (apple).";
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
            if (root->getLeft() == nullptr)
            {
                root->setLeft(new binary_tree_node<string>("branch #1"));
            }

            if (root->getRight() == nullptr)
            {
                root->setRight(new binary_tree_node<string>("branch #2"));
            }

            cout << "\n\t\tRoot grows two branches.\n";

            break;
        }
        case 'C':
        {
            cout << "\n\t\tOption C selected.\n";

            if (root == nullptr || root->getLeft() == nullptr || root->getRight() == nullptr)
            {
                cout << "\n\t\tERROR: Create branches first.\n";
                break;
            }

            // Grow leaves on both branches
            if (root->getLeft()->getLeft() == nullptr)
            {
                root->getLeft()->setLeft(new binary_tree_node<string>("left leaf"));
            }

            if (root->getRight()->getRight() == nullptr)
            {
                root->getRight()->setRight(new binary_tree_node<string>("right leaf"));
            }

            cout << "\n\t\tBranches grow leaves.\n";

            break;
        }
        case 'D':
        {
            cout << "\n\t\tOption D selected.\n";

            if (root == nullptr || root->getLeft() == nullptr || root->getLeft()->getLeft() == nullptr)
            {
                cout << "\n\t\tERROR: Grow leaves first.\n";
                break;
            }

            // Left leaf produces an apple
            binary_tree_node<string>* leaf = root->getLeft()->getLeft();

            if (leaf->getLeft() == nullptr)
            {
                leaf->setLeft(new binary_tree_node<string>("apple"));
            }

            cout << "\n\t\tLeft leaf yields an apple.\n";

            break;
        }
        case 'E':
        {
            cout << "\n\t\tOption E selected.\n";

            if (root == nullptr || root->getRight() == nullptr || root->getRight()->getRight() == nullptr)
            {
                cout << "\n\t\tERROR: Grow leaves first.\n";
                break;
            }

            // Right leaf produces two fruits
            binary_tree_node<string>* leaf = root->getRight()->getRight();

            if (leaf->getLeft() == nullptr)
            {
                leaf->setLeft(new binary_tree_node<string>("orange"));
            }

            if (leaf->getRight() == nullptr)
            {
                leaf->setRight(new binary_tree_node<string>("coconut"));
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

    cout << "\n\t" << node->getData() << "\n";

    if (node->getLeft() != nullptr)
    {
        DisplayBranches(node->getLeft(), "", node->getRight() == nullptr);
    }

    if (node->getRight() != nullptr)
    {
        DisplayBranches(node->getRight(), "", true);
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

    cout << " " << node->getData() << "\n";

    if (isLast)
    {
        prefix += "    ";
    }
    else
    {
        prefix += char(179);
        prefix += "   ";
    }

    if (node->getLeft() != nullptr)
    {
        DisplayBranches(node->getLeft(), prefix, node->getRight() == nullptr);
    }

    if (node->getRight() != nullptr)
    {
        DisplayBranches(node->getRight(), prefix, true);
    }
}
void DeleteTree(binary_tree_node<string>*& node)
{
    if (node == nullptr)
    {
        return;
    }
    binary_tree_node <string>* left = node->getLeft();
    binary_tree_node <string>* right = node->getRight();

    DeleteTree(left);
    DeleteTree(right);

    delete node;
    node = nullptr;

}

void TreeContainerOfIntegers()
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
			//insert(root, value);
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

//option 3
void animalGuessingGame()
{
	do
	{
		system("cls");
		cout << "\n\t3> Animal Guessing Game";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\tA game tree for a simple game of \"animal\" twenty questions would look like:\n";
		cout << "\n\t\t\t\t\t[ Is it a mammal? ]";
		cout << "\n\t\t\t\t\t     /         \\ ";
		cout << "\n\t\t\t\t\t    /           \\ ";
		cout << "\n\t\t\t[ Does it have stripes? ]     [ Is it a bird? ]";
		cout << "\n\t\t\t       /      \\                 /       \\";
		cout << "\n\t\t\t      /        \\               /         \\";
		cout << "\n\t\t\t( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )";
		cout << "\n\t\t\t\t\t\t  /       \\";
		cout << "\n\t\t\t\t\t\t /         \\";
		cout << "\n\t\t\t\t\t  ( Eagle )     ( Penguin )\n";
		cout << "\n\t A learning version of twenty questions: one that not only plays the game, but learns new objects when it loses.";

		char option;

		binary_tree_node<string>* root_ptr = beginning_tree();

		if (root_ptr == NULL)
		{
			cout << "\n\tERROR: Unable to initialize the tree.";
			return;
		}
		do
		{
			option = animalGuessingGameMenu();
			switch (toupper(option))
			{
			case 'A':
			{
				play(root_ptr);
			}
			break;

			case 'B':
			{
				ofstream file;
				file.open("animal.txt");
				preorderTraveral(file, root_ptr);
				file.close();
			}
			break;

			case '0':
			{
				cout << "\n\tThank you for teaching AI a thing or two\n";
				delete_tree(root_ptr);
				return;
			}

			default:
			{
				cout << "\n\tERROR: Invalid option\n";
			}
			break;
			}
			system("pause");
			system("cls");
		} while (option != '0');
	} while (true);
	
}

char animalGuessingGameMenu()
{

	system("cls");
	cout << "\n\tWelcome to Animal Guessing Game";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> Play the game";
	cout << "\n\t\tB> Save the game file";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("AB0"));
	
}