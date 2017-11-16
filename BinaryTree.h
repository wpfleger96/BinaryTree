#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "ItemType.h"

struct Node{
	ItemType key;
	Node* left;
	Node* right;
};

class BinaryTree{
public:	
	BinaryTree();
	~BinaryTree();
	void insert(ItemType &key);
	void deleteItem(ItemType &key);
	void retrieve(ItemType &item, bool &found);
	void preOrder() const;
	void inOrder() const;
	void postOrder() const;
	int getLength() const;

private:
	Node* root;
	int length;
	int countNodes(Node* tree) const;
	void insertItem(Node*& tree, ItemType item);
	void getItem(Node* tree, ItemType &item, bool &found);
	void destroy(Node* tree);
	void deleteNode(Node*& tree);
	void del(Node*& tree, ItemType item);
	void getPredecessor(Node* tree, ItemType &data);
	void pre(Node* tree) const;
	void in(Node* tree) const;
	void post(Node* tree) const;

};

#endif