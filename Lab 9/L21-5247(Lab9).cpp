
// Muhammad Farhan Bukhari-----------21L-5247------------BCS-3F1
// Lab 9 (AVL Trees)


//Q2 starting after line 325

#include<iostream>
using namespace std;

template<class T>
class AVL
{
	struct AVLNode
	{
	public :
		T data;
		int height;
		AVLNode* right;
		AVLNode* left;

		AVLNode()
		{
			right = NULL;
			left = NULL;
			height = 0;
			data = 0;
		}
	};

	AVLNode* root;

public:

	AVL()
	{
		root = nullptr;
	}

	void insert(T element)
	{
		insert(element, root);
	}

	void insert(T element, AVLNode*& temp)
	{
		if (temp)
		{
			if (element < temp->data) {
				insert(element, temp->left);
			}
			else if (element > temp->data) {
				insert(element, temp->right);
			}
		}

		else
		{
			temp = new AVLNode;
			temp->data = element;
		}

		balance(temp);
	}

	T max(T el1, T el2)
	{
		if (el1 >= el2) {
			return el1;
		}
		else {
			return el2;
		}
	}

	int height()
	{
		return height(root);
	}

	int height(AVLNode* temp)
	{
		if (temp != nullptr)
			return max(height(temp->left), height(temp->right)) + 1;

		else return -1;
	}

	bool balance(AVLNode*& temp)
	{
		if (temp != nullptr)
		{
			if (height(temp->right) - height(temp->left) < -1)
			{
				if (temp->left != nullptr)
				{
					if (height(temp->left->left) >= height(temp->left->right))
					{
						rightRotate(temp);
					}

					else
					{
						doubleLeftRightRotation(temp);
					}
				}

				return false;
			}

			else if (height(temp->right) - height(temp->left) > 1)
			{
				if (temp->right != nullptr)
				{

					if (height(temp->right->right) >= height(temp->right->left))
					{
						LeftRotate(temp);
					}

					else
					{
						doubleRightLeftRotation(temp);
					}
				}

				return false;
			}

			temp->height = max(height(temp->left), height(temp->right)) + 1;
			return true;
		}
	}

	void rightRotation(AVLNode*& temp)
	{
		AVLNode* orphan = temp->left->right;
		AVLNode* parent = temp->left;

		parent->right = temp;
		temp->left = orphan;
		temp->height = height(temp);
		parent->height = height(parent);
		temp = parent;
	}

	void leftRotation(AVLNode*& temp)
	{
		AVLNode* orphan = temp->right->left;
		AVLNode* parent = temp->right;

		parent->left = temp;
		temp->right = orphan;
		temp->height = height(temp);
		parent->height = height(parent);
		temp = parent;
	}

	void doubleLeftRightRotation(AVLNode*& temp)
	{
		leftRotation(temp->left);
		rightRotation(temp);
	}

	void doubleRightLeftRotation(AVLNode*& temp)
	{
		rightRotation(temp->right);
		leftRotation(temp);
	}

	void print()
	{
		print(root);
	}

	void print(AVLNode* temp)
	{
		if (temp) 
		{
			print(temp->left);
			cout << temp->data << " ";
			print(temp->right);
		}
	}

	void postPrint()
	{
		postPrint(root);
	}

	void postPrint(AVLNode* temp)
	{
		if (temp)
		{
			postPrint(temp->left);
			postPrint(temp->right);
			cout << temp->data << " ";
		}
	}

	void prePrint()
	{
		prePrint(root);
	}

	void prePrint(AVLNode* temp)
	{
		if (temp)
		{
			cout << temp->data << " ";
			prePrint(temp->left);
			prePrint(temp->right);
		}
	}

	void del(T element)
	{
		del(element, root);
	}

	void del(T element, AVLNode*& temp)
	{
		if (temp) 
		{
			if (element < temp->data) 
			{
				del(element, temp->left);
			}

			else if (element > temp->data) 
			{
				del(element, temp->right);
			}

			else 
			{
				delnode(temp);
			}
		}

		balance(temp);
	}

	void delnode(AVLNode*& temp)
	{
		if (temp) 
		{
			AVLNode* a = temp;
			if (temp->left == NULL) 
			{
				temp = temp->right;
				delete a;
			}

			else if (temp->right == NULL) 
			{
				temp = temp->left;
				delete a;
			}

			else 
			{
				T d = predecessor(temp->left);
				temp->data = d;
				del(d, temp->left);
			}
		}
	}

	T predecessor(AVLNode* temp) 
	{
		while (temp->right != NULL) 
		{
			temp = temp->right;
		}

		return temp->data;
	}

	void search(T data)
	{
		search(data, root);
	}

	void search(T data, AVLNode* temp)
	{
		if (temp) 
		{
			if (data < temp->data) 
			{
				search(data, temp->left);
			}

			else if (data > temp->data) 
			{
				search(data, temp->right);
			}

			else 
			{
				cout << "Found!\n";
			}
		}

		else 
		{
			cout << "Not Found!\n";
		}
	}

	void copyTree(AVL& temp)
	{
		copyTree(root, temp.root);
	}

	void copyTree(AVLNode* temp, AVLNode*& copy)
	{
		if (temp) 
		{
			copy = new AVLNode;

			copy->data = temp->data;
			copyTree(temp->left, copy->left);
			copyTree(temp->right, copy->right);
		}
	}

	~AVL()
	{
		destruct(root);
	}

	void destruct(AVLNode*& temp)
	{
		if (temp) 
		{
			destruct(temp->left);
			destruct(temp->right);

			delete temp;
		}
		temp = nullptr;
	}

	//------------------- Question 2 -----------------------

	bool isAVL()
	{
		return isAVL(root);
	}

	bool isAVL(AVLNode* temp)
	{
		if (balance(temp)) 
		{
			cout << "\nIt is an AVL tree!\n";
			return true;
		}

		else 
		{
			cout << "\nNot AVL tree!\n";
			return false;
		}
	}

	void findMin()
	{
		findMin(root);
	}

	void findMin(AVLNode* temp)
	{
		if (temp) 
		{
			if (temp->left != NULL) 
			{
				findMin(temp->left);
			}

			else 
			{
				cout << "1st Minimum is: " << temp->data << endl;
			}
		}
	}

	void find2ndMin()
	{
		find2ndMin(root);
	}

	void find2ndMin(AVLNode* temp)
	{
		if (temp)
		{
			if (temp->left->left != NULL && temp->left->right != NULL)
			{
				find2ndMin(temp->left);
			}

			else if (temp->left->left == NULL && temp->left->right != NULL)
			{
				find2ndMin(temp->right);
			}

			else
			{
				cout << "2nd Minimum is: " << temp->data << endl;
			}
		}
	}

	void find3rdMin()
	{
		find3rdMin(root);
	}

	void find3rdMin(AVLNode* temp)
	{
		if (temp)
		{
			if (temp->left->left->left != NULL)
			{
				find3rdMin(temp->left);
			}

			else if (temp->left->left->left != NULL && temp->left->right->left != NULL)
			{
				find3rdMin(temp->right);
			}

			else
			{
				cout << "3rd Minimum is: " << temp->data << endl;
			}
		}
	}
	void itprint()
	{
		itprint(root);
	}

	void itprint(AVLNode* temp)
	{
		for (; temp != nullptr; temp = temp->left)
			cout << temp->data << " ";
	}
};


int main()
{
	AVL<int> tree1;
	tree1.insert(1);
	tree1.insert(5);
	tree1.insert(7);
	tree1.insert(10);
	tree1.insert(6);
	tree1.insert(2);
	tree1.insert(8);

	cout << "\nAVL tree1 is: \n";
	tree1.print();

	cout << "\nHeight is: \n" << tree1.height() << endl << endl;
	cout << "After Deleting 2: \n";
	tree1.del(2);
	tree1.print();
	cout << endl;

	cout << "\nSearching 9: \n";
	tree1.search(9);
	cout << endl;

	AVL<int> tree2;
	tree1.copyTree(tree2);

	cout << "Copying tree1 in tree2: ";
	tree2.print();

	cout << endl;
	cout << "\n\nInorder tree2 printing: \n";
	tree2.print();

	cout << endl;
	cout << "\n\nPreorder tree 2 printing: \n";
	tree2.prePrint();

	cout << endl;
	cout << "\n\npostorder tree 2 printing: \n";
	tree2.postPrint();

	cout << endl;
	cout << "\nAfter checking if tree1 is AVL OR Not :\n";

	tree1.isAVL();
	tree1.findMin();
	tree1.find2ndMin();
	tree1.find3rdMin();
	cout << endl;

	system("pause");
	return 0;

};
