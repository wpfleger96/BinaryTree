#include "ItemType.h"
#include "BinaryTree.h"
#include <fstream>
#include <iostream>
#include <cstddef>

using namespace std;

int main(int, char**);

static bool isValid(char);

int main(int argc, char*argv[]){

	BinaryTree *tree;
	tree = new BinaryTree;
	ItemType item;
	int input;
	static fstream fs;

	//Opens the input file
	fs.open(argv[1],fstream::in);


	//Reads through the input file and adds the items to the list
	if(fs.is_open()){
		fs>>input;
		while(!fs.eof()){
			item.initialize(input);
			tree->insert(item);
			fs>>input;
		}
	}

	else{
		cout << "File could not be opened. Try again." << endl;
		return 0;
	}


	cout << "Commands - insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), quit (q)" << endl;
	char cmd;
	cout << "Enter a command: ";
	cin >> cmd;
	cout << endl;
	//Main command loop
	while( cmd != 'q'){
		//Tests for valid user input
		if(!(isValid(cmd))){
			cout << "Command not recognized. Try again" << endl;
			cout << "Enter a command: ";
			cin >> cmd;
			continue;
		}
		
		//User wants to insert an item
		if(cmd == 'i'){
			cout << "Enter the number to insert: ";
			int num;
			cin >> num;
			ItemType temp;
			temp.initialize(num);
			tree->insert(temp);
			tree->inOrder();
			cout << endl;
		}
		//User wants to delete an item
		else if(cmd == 'd'){
			cout << "Enter the number to delete: ";
			int num;
			cin >> num; 
			ItemType temp;
			temp.initialize(num);
			tree->deleteItem(temp);
			tree->inOrder();
			cout << endl;
		}
		//User wants the list's length
		else if(cmd == 'l'){
			cout << "Length: " << tree->getLength() << endl;
		}
		//User wants to retrieve an item
		else if(cmd == 'r'){
			cout << "Item to be retrieved: ";
			int num;
			cin >> num;
			ItemType temp;
			temp.initialize(num);
			bool found = false;
			tree->retrieve(temp, found);
			if(found)
				cout << "Item found in tree" << endl;
			else
				cout << "Item not in tree" << endl;
		}
		//User wants to print in-order
		else if(cmd == 'n'){
			cout << "In order: ";
			tree->inOrder();
			cout << endl;
		}
		//User wants to print pre-order
		else if(cmd == 'p'){
			cout << "Pre order: ";
			tree->preOrder();
			cout << endl;
		}
		else if(cmd == 'o'){
			cout << "Post order: ";
			tree->postOrder();
			cout << endl;
		}
		else if(cmd == 'q'){
			cout << "Exiting..." << endl;
			exit(EXIT_SUCCESS);
		}

		cout << "Enter a command: ";
		cin >> cmd;
		cout << endl;
	}


	return 0;
}

//Function to validate the user input
static bool isValid(char inp){
	if(!(inp == 'i' || inp == 'd' || inp == 'r' || inp == 'l' || inp == 'n' || inp == 'p' || inp=='o' ||  inp == 'q'))
		return false;
	else
		return true;
}
