#ifndef __BST__
#define __BST__

#include <iostream>
#include <string>


// binary search tree of strings, for auto
// alphabetization

class Bst
{

public:
	
	Bst();

	bool insert(std::string& a);
	bool remove(std::string& a);
	bool contains(std::string& a);
	int pathBetweenNodes(std::string& a, std::string& b);
	void printInOrder();

	~Bst();

private:

	struct node
	{
		// if left is true, node is a left child.
		node(std::string& _val, node *_parent, bool _leftchild);
		std::string val;
		node *left;
		node *right;
		node *parent;
		bool leftchild;
	};
	
	void inOrderTraversal(node *temp);
	int pathHelper(node *temp, std::string& low, std::string& high);
	node *m_head;

};

#endif
