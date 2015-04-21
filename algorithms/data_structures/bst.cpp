#include "bst.h"

using namespace std;

Bst::node::node(string& _val, node *_parent, bool _leftchild)
{
	val = _val;
	left = NULL;
	right = NULL;
	parent = _parent;
	leftchild = _leftchild;
}


Bst::Bst()
{
	m_head = NULL;
}

Bst::~Bst()
{
	while (remove(m_head->val))
		continue;
}

bool Bst::contains(string& a)
{
	node *temp = m_head;

	while (temp)
	{
		if (a < temp->val)
			temp = temp->left;
		else if (a > temp->val)
			temp = temp->right;
		else
			return true;
	}
	return false;
}

bool Bst::insert(string& a)
{
	if (m_head == NULL)
	{
		m_head = new node(a, NULL, false);
		return true;
	}
	

	node *temp = m_head;
	while (true)
	{
		if (a < temp->val)
		{	
			if (temp->left)
				temp = temp->left;
			else
			{
				temp->left = new node(a, temp, true);
				return true;
			}
		}
		else
		{ 	
			if (temp->right)
				temp = temp->right;
			else
			{
				temp->right = new node(a, temp, false);
				return true;
			}
		}
	}

	
	return true;
}

bool Bst::remove(string& a)
{
	
	node *temp = m_head;

	while (temp) 
	{
		// found node to delete
		if (temp->val == a)
		{
			// no children
			if (temp->left == NULL && temp->right == NULL)
			{
				
				if (temp->parent)
				{
					
					if (temp->leftchild)
						temp->parent->left = NULL;
					else
						temp->parent->right = NULL;

					delete temp;
				}
				else
				{
					delete temp;
					m_head = NULL;

				}
				return true;
			}

			// one child on right
			if (temp->left == NULL && temp->right != NULL)
			{
				if (temp->parent)
				{
					if (temp->leftchild)
					{
						temp->right->parent = temp->parent;
						temp->parent->left = temp->right;
							
					}
					else
					{
						temp->right->parent = temp->parent;
						temp->parent->right = temp->right;

					}
					delete temp;
				}
				else
				{
					m_head = temp->right;
					m_head->parent = NULL;
					delete temp; 
				}
				return true;

			}

			// one child on left
			if (temp->left != NULL && temp->right == NULL)
			{
				if (temp->parent)
				{
					if (temp->leftchild)
					{
						temp->left->parent = temp->parent;
						temp->parent->left = temp->left;
					}
					else
					{
						temp->left->parent = temp->parent;
						temp->parent->right = temp->left;
					}

					delete temp;
				}
				else
				{
					m_head = temp->left;
					m_head->parent = NULL;
					delete temp;
				}

				return true;
			}

			// two children
			if (temp->left != NULL && temp->right != NULL)
			{
				// replace temp with largest val in left subtree
				// then delete said value
				node *temp2 = temp->left;
				
				while (temp2->right)
					temp2 = temp2->right;

				temp->val = temp2->val;
				
				if (temp2->leftchild)
					temp2->parent->left = NULL;
				else
					temp2->parent->right = NULL;

				delete temp2;
				return true;

			}

		}
		else if (a < temp->val)
			temp = temp->left;
		else
			temp = temp->right;

	}


	return false;
}

void Bst::printInOrder()
{
	inOrderTraversal(m_head);
}

void Bst::inOrderTraversal(node *temp)
{
	if (temp == NULL)
		return;

	inOrderTraversal(temp->left);
	cout << " " << temp->val << " ";
	inOrderTraversal(temp->right);

}

int main()
{
	Bst tree;
	cout << "Enter in words and they will stay alphabetized, enter word again to remove. Type quit() to quit. \n\n" << endl;
	for (;;)
	{
		cout << "Enter a word: ";
		string a;
		cin >> a;
		
		if (a == "quit()") //to test destructor
			break;
		if (tree.contains(a))
			tree.remove(a);
		else
			tree.insert(a);
		
		cout << "\n\n>";
		tree.printInOrder();
		cout << "\n\n";
	}
}


