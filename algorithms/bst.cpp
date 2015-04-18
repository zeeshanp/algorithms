#include <iostream>
#include <string>


using namespace std;


// binary search tree of strings, for auto
// alphabetization

class Bst
{

public:
	
	Bst();

	bool insert(string& a);
	void printInOrder();

	~Bst();

private:

	struct node
	{
		node(string& val);
		string val;
		node *left;
		node *right;
	};
	
	void inOrderTraversal(node *temp);
	node *m_head;

};

Bst::node::node(string& _val)
{
	val = _val;
	left = NULL;
	right = NULL;
}


Bst::Bst()
{
	m_head = NULL;
}

Bst::~Bst()
{
	return;
}

bool Bst::insert(string& a)
{
	if (m_head == NULL)
	{
		m_head = new node(a);
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
				temp->left = new node(a);
				return true;
			}
		}
		else
		{ 
			
			if (temp->right)
				temp = temp->right;
			else
			{
				temp->right = new node(a);
				return true;
			}
		}
	}

	
	return true;
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
	cout << "Enter in words and they will stay alphabetized!!" << endl;
	for (;;)
	{
		cout << "Enter a word:";
		string a;
		cin >> a;
		tree.insert(a);
		cout << "\n\n>";
		tree.printInOrder();
		cout << "\n\n";
	}
}


