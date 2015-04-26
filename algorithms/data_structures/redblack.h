#ifndef __REDBLACKTREE__
#define __REDBLACKTREE__


#define RED 0
#define BLACK 1

/*
	Red-Black Tree of (Key, Value) Pairs
	-red = 0, black = 1
	-Assume root is black
	-Same number of black nodes on all root-leave paths
	  (sum of all paths is same)
	-No two red nodes are adjacent
*/

template <typename Key, typename Value>
class RedBlackTree
{
	public:
	
		RedBlackTree();
		~RedBlackTree();
		
		bool insert(Key k, Value v);
		bool remove(Key k);
		Value find(Key k);
		void printKeys();
	
	private:

		template <typename Key, typename Value>
		struct Node
		{
			Node(Key k, Value v, Node<Key, Value> *p, int c)
			{
				key = k;
				val = v;
				parent = p;
				left = right = NULL;
				color = c;
			};

			Key key;
			Value val;
			int color;
			Node<Key, Value> *left;
			Node<Key, Value> *right;
			Node<Key, Value> *parent;
		};

		Node<Key, Value> *head;

		void inOrderTraversal(node *head, int height);

};



template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree()
{
	*head = NULL;
}


template <typename Key, typename Value>
bool RedBlackTree<Key, Value>::insert(Key k, Value v)
{
	if (head == NULL)
	{
		// head is always black
		head = new Node<Key, Value> (k, v, NULL, BLACK);
		return true;
	}

	//find where to insert key, temp points at child, temp2 parent
	Node<Key, Value> *temp, *temp2 = head;

	while (true)
	{ 
		// found where to place key
		if (temp == NULL) 
		{
			// if parent is black, just add child as red
			if (temp2->color == BLACK)
			{
				temp = new Node<Key,Value> (k, v, temp2, RED);
				
				// figure out left or right
				if (k > temp2->key)
					temp2->right = temp;
				else
					temp2->left = temp;
				return true;
			}

			/* if parent is red, it'll violate red property to add
			   red child, so we have to add black. This may violate
			   adjacent red property.
			   TODO: Implement this case	  		
			*/
			if (temp2->color == RED)
			{

			}
		}

		// not found yet, move head along
		temp2 = temp;

		if (k > temp->key)
			temp = temp->right;
		else if (k < temp->key)
			temp = temp->left;
		else
		{
			// key already exists, just update
			temp->value = v;
			return true;
		}
	}

}






#endif