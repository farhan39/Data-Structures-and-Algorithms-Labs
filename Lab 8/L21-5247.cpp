// Muhammad Farhan Bukhari--------------BCS - 3F----------------21L-5247
// Lab 8 (Other functions of BinaryTree)


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
			return true;
		}

		else insert(temp->left, data);
		return true;
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
			if (max < n)
				max = n;
			n++;
			height(temp->right, max, n);
			return max;
		}
	}

	int countLeaves(BNode* temp)
	{
		if (temp == nullptr)
			return 0;

		else if (temp->left == nullptr && temp->right == nullptr)
			return 1;

		else
		{
			return countLeaves(temp->left) + countLeaves(temp->right);
		}
	}

	int pathSums(BNode* temp, int*& myArray, int& i, int eachLeafSum)
	{
		if (temp == nullptr)
			return 0;

		else if (temp->left == nullptr && temp->right == nullptr)
		{
			int tempVar = eachLeafSum;
			eachLeafSum += temp->data;
			myArray[i] = eachLeafSum;
			i++;
			eachLeafSum = 0;
			return tempVar;
		}

		else
		{
			return pathSums(temp->left, myArray, i, eachLeafSum + temp->data) + pathSums(temp->right, myArray, i, eachLeafSum + temp->data);
		}
	}

	BNode* lowestCommonAncestor(BNode* temp, int n1, int n2)
	{
		if (temp == NULL)
			return NULL;
 
		// If both n1 and n2 are smaller
		// than root, then LCA lies in left
		if (temp->data > n1 && temp->data > n2)
			return lowestCommonAncestor(temp->left, n1, n2);
 
		// If both n1 and n2 are greater than
		// root, then LCA lies in right
		if (temp->data < n1 && temp->data < n2)
			return lowestCommonAncestor(temp->right, n1, n2);
 
		return temp;
	}

	void Trimlength(BNode *& temp, int& h, bool& check, int n)
	{
			if (temp)
			{
				Trimlength(temp->left, h, check, n);
				
				n++;

				if (h == n)
				{
					check = true;
				}

				if (check)
				{
					temp->data = 0;
				}
				Trimlength(temp->right, h, check, n);
			}
	}

	BNode* findAncestor(BNode* temp, T num)
	{
		if (num == root->data || temp == nullptr)
			return nullptr;

		else
		{
			if ((temp->left->data == num) || (temp->right->data == num))
				return temp;

			else 
			{
				if (temp->data < num)
					return findAncestor(temp->right, num);

				else return findAncestor(temp->left, num);
			}
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

	int height()	//wrapper
	{
		int max = 0;
		return height (root, max, 0);
	}

	int countLeaves()
	{
		return countLeaves(root);
	}

	int* pathSums()		//wrapper
	{
		int noOfLeaves = countLeaves();
		int* pathSumArray = new int [noOfLeaves];
		int index = 0;
		pathSums(root, pathSumArray, index, 0);
		return pathSumArray;
	}

	//bool operator==(const BinaryTree<T>& t2) const
	//{
	//	if((root == NULL) && (t2.root == NULL))
	//		return true; //two null trees are equal
	//	else if((root != NULL) && (t2.root != NULL))
	//	{
	//		return((root->data == t2.root->data) && (root->left == t2.root->left) && (root->right == t2.root->right));
	//	}
	//	else
	//		return false; //one tree is null the other is not
	//}

	int lowestCommonAncestor(int n1, int n2)	//wrapper
	{
		return lowestCommonAncestor(root, n1, n2)->data;
	}

	void TrimBelowK(int n)
	{
		if (n < 0)
			return;
		else
		{
			bool check = 0;
			int hght = this->height();
			bool c = 0;
			Trimlength(root,hght,c, n);
		}
	}

	int findAncestor(int n1)
	{
		int temp;
		if (findAncestor(root, n1) == nullptr)
			temp = 0;
		else temp = findAncestor(root, n1)->data;
		return temp;
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

	cout << "Total leaves in the tree are :\n";
	cout << b1.countLeaves() << endl;

	cout << "Path sums :\n";
	int* pathSums = b1.pathSums();
	int pathSumsSize = b1.countLeaves();
	for (int i = 0 ; i < pathSumsSize ; ++i)
		cout << pathSums[i] << " ";

	BinaryTree<int> b2;
	b2.insert(21);
	b2.insert(17);
	b2.insert(11);
	b2.insert(7);
	b2.insert(8);
	b2.insert(9);
	b2.insert(4);
	b2.insert(5);


	BinaryTree<int> b3;
	b3.insert(5);
	b3.insert(4);
	b3.insert(9);
	b3.insert(8);
	b3.insert(7);
	b3.insert(11);
	b3.insert(17);
	b3.insert(21);

	/*if (b1 == b2)
		cout << "\nb1 and b2 are equal.\n";

	if (b1 == b3)
		cout << "\nb1 and b2 are equal.\n";*/

	cout << "\nLowest Common Ancestor of B1 :\n";
	cout << b1.lowestCommonAncestor(7, 21) << endl;

	cout << "Ancestor of 4 is :	//0 returned if given element is root.\n";
	cout << b1.findAncestor(4) << endl;

	cout << "Ancestor of 8 is :	//0 returned if given element is root.\n";
	cout << b1.findAncestor(8) << endl;

	b1.TrimBelowK(1);

	cout << "After trimming below 1:\n";
	b1.inorderTraversal();

	system("pause");
	return 0;
}