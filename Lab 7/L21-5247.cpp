// Muhammad Farhan Bukhari--------------BCS - 3F----------------21L-5247

#include<iostream>
using namespace std;

template<class T>
class BinaryTree
{
	struct BNode
	{
	public :

		T data;
		BNode* left;
		BNode* right;

		BNode(T data1 = 0, BNode* left1 = 0, BNode* right1 = 0)
		{
			data = data1;
			left = left1;
			right = right1;
		}

	};

	BNode* root;

	bool insert(BNode*& temp, T data)
	{
		if (temp == nullptr)
		{
			temp = new BNode (data, 0, 0);
			return true;
		}

		else if (temp->data == data)
		{
			return false;
		}

		else if (temp->data < data)
		{
			insert(temp->right, data);
		}

		else insert(temp->left, data);
	}

	void inorderTraversal(BNode* temp)
	{
		if (temp)
		{
			inorderTraversal(temp->left);
			visit(temp);
			inorderTraversal(temp->right);
		}
	}

	void length(BNode* temp, int& l)
	{
		if (temp)
		{
			length(temp->left, l);
			l++;
			length(temp->right, l);
		}
	}

	BNode* search(BNode* temp, T d)
	{
		if (temp)
		{
			if (temp->data == d)
				return temp;

			else if (temp->data < d)
				return search(temp->right, d);

			else return search(temp->left, d);
		}
		return nullptr;
	}

	int height (BNode* temp, int& max, int n)
	{
		if (temp)
		{
			height(temp->left, max, n);
			n++;
			if (max < n)
				max = n;
			height(temp->right, max, n);
			return max;
		}
	}

public :

	BinaryTree()
	{
		root = 0;
	}

	void visit(BNode* temp)
	{
		cout << temp->data << endl;
	}

	void insert(T data)
	{
		insert(root, data);
	}

	void inorderTraversal()
	{
		inorderTraversal(root);
	}

	int length()
	{
		int length1 = 0;
		length(root, length1);
		return length1;
	}

	bool search(T d)
	{
		BNode* temp = search(root, d);
		if (temp)
			return true;
		return false;
	}

	int height()
	{
		int max = 0;
		return height (root, max, 0);
	}

};

int main ()
{
	BinaryTree<int> b1;

	b1.insert(5);
	b1.insert(4);
	b1.insert(9);
	b1.insert(8);
	b1.insert(7);
	b1.insert(11);
	b1.insert(17);
	b1.insert(21);

	cout << "Tree :\n";
	b1.inorderTraversal();

	cout << "Length :\n";
	cout << b1.length() << endl;

	cout << "After searching :\n";
	if (b1.search(11))
		cout << "Present.\n";
	else cout << "Not present.";

	cout << "\nHeight :\n";
	cout << b1.height() << endl;


	system("pause");
	return 0;
}