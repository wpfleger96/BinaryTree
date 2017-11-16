#include "BinaryTree.h"
#include "ItemType.h"
#include <iostream>
#include <cstddef>

using namespace std;

//Constructor
BinaryTree::BinaryTree(){
	root=NULL;
	length=0;

}

//Destructor
BinaryTree::~BinaryTree(){
	destroy(root);
}

void BinaryTree::destroy(Node* tree){
	if(tree != NULL){
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
	}
}

//Insert item 
void BinaryTree::insert(ItemType &item){
	insertItem(root, item);
}

//Insert item helper function
void BinaryTree::insertItem(Node*& tree, ItemType item){
	if(tree == NULL){
		tree = new Node;
		tree->right=NULL;
		tree->left=NULL;
		tree->key=item;
	}
	else if(item.compareTo(tree->key) == LESS){
		insertItem(tree->left, item);
	}
	else if(item.compareTo(tree->key) == GREATER){
		insertItem(tree->right, item);
	}
}

//Delete item
void BinaryTree::deleteItem(ItemType &item){
	del(root, item);
}

//Delete helper function (finds correct node)
void BinaryTree::del(Node*& tree, ItemType item){
	if(item.compareTo(tree->key) == LESS)
		del(tree->left, item);
	else if(item.compareTo(tree->key) == GREATER)
		del(tree->right, item);
	else
		deleteNode(tree);
}

//Delete helper function (actually deletes node)
void BinaryTree::deleteNode(Node*& tree){
	ItemType tempItem;
	Node* tempNode;
	tempNode = tree;
	if(tree->left == NULL){
		tree = tree->right;
		delete tempNode;
	}
	else if(tree->right == NULL){
		tree = tree->left;
		delete tempNode;
	}
	else{
		getPredecessor(tree->left, tempItem);
		tree->key = tempItem;
		del(tree->left, tempItem);
	}
}	

//Gets predecessor of given node
void BinaryTree::getPredecessor(Node* tree, ItemType &item){
	while(tree->right != NULL)
		tree = tree->right;
	item = tree->key;
}

//Retrieve item
void BinaryTree::retrieve(ItemType &item, bool &found){
	getItem(root, item, found);
}

//Retrieve helper function
void BinaryTree::getItem(Node* tree, ItemType& item, bool &found){
	if(tree == NULL)
		found = false;
	else if(item.compareTo(tree->key) == LESS)
		getItem(tree->left, item, found);
	else if(item.compareTo(tree->key) == GREATER)
		getItem(tree->right, item, found);
	else{
		item=tree->key;
		found=true;
	}

}

//Print pre-order
void BinaryTree::preOrder() const{
	pre(root);
}

//Pre-order print helper function
void BinaryTree::pre(Node* tree) const{
	if(tree == NULL)
		return;
	cout << tree->key.getValue() << " ";
	pre(tree->left);
	pre(tree->right);
}

//Print in-order
void BinaryTree::inOrder() const{
	in(root);
}

//In-order print helper function
void BinaryTree::in(Node* tree) const{
	if(tree == NULL)
		return;
	in(tree->left);
	cout << tree->key.getValue() << " ";
	in(tree->right);
}

//Post-order print
void BinaryTree::postOrder() const{
	post(root);
}

//Post-order print helper function
void BinaryTree::post(Node* tree) const{
	if(tree == NULL)
		return;
	post(tree->left);
	post(tree->right);
	cout << tree->key.getValue() << " ";
}

//Returns tree length
int BinaryTree::getLength() const{
	Node* temp = root;
	return countNodes(temp);
}

//Length helper function
int BinaryTree::countNodes(Node* tree) const{
	if(tree == NULL)
		return 0;
	else
		return countNodes(tree->left) + countNodes(tree->right) + 1;
}

