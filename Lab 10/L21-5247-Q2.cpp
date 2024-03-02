// Muhammad Farhan Bukhari-------------BCS - 3F-------------21L-5247
// Lab 10 (Hashing) Q2

#include<iostream>
#include<assert.h>
#include<list>
#include<iterator>

using namespace std;

template<class T>
class Hash
{
	list<T>* queue;
	bool* status;
	int capacity;
	int* listIndex;

public:

	Hash()
	{
		size = 10;
		status = new bool[capacity];

		for (int i = 0; i < capacity; ++i)
			status[i] = false;

		queue = new list<T>[capacity];

		listIndex = new int[capacity];

		for (int i = 0; i < capacity; ++i)
			listIndex[i] = 0;
	}

	Hash(int const capacity1)
	{
		if (capacity1 > 1)
		{
			capacity = capacity1;
			queue = new list<T>[capacity];
			for (int i = 0; i < capacity; i++)
			{
				list <T> l1;
				queue[i] = l1;
			}

			status = new bool[capacity];

			for (int i = 0; i < capacity; i++)
				status[i] = false;

			listIndex = new int[capacity];
			for (int i = 0; i < capacity; ++i)
			listIndex[i] = 0;

		}
		else
		{
			cout << "Size is less than -1\n";
			capacity = -1;
		}

	}

	//Hash(int const capacity1)
	//{
	//	assert(capacity1 > 1);

	//	capacity = capacity1;

	//	queue = new list<T> [capacity];
	//	for (int i = 0; i < capacity; ++i)
	//	{
	//		list<T> l1;
	//		queue[i] = l1;
	//	}

	//	status = new bool[capacity];
	//	for (int i = 0; i < capacity; ++i)
	//		status[i] = false;

	//	//listIndex = new int[capacity];
	//}

	bool deleteKey(T const key)
	{
		for (int i = 0; i < capacity; i++)
		{
			list<T>::iterator it;
			list<T> l = queue[i];
			it = l.begin();
			for (; it != l.end(); ++it)
			{
				if (*it == key)
				{
					*it = 0;
				}
			}
		}
	}

	void insert(T const key)		//Q2
	{
		if (capacity > 1)
		{
			int n = key % capacity;
			int index = listIndex[n];

			list<int>::iterator it;
			it = queue[n].begin();
			queue[n].insert(it, key);

			status[n] = true;
			listIndex[n]++;
		}
	}

	void printHashArray()
	{
		for (int i = 0; i < capacity; i++)
		{
			list<T>::iterator it;
			list<T> l = queue[i];

			it = l.begin();

			int count = 0;

			for (; it != l.end(); ++it)
			{
				cout << '\t' << *it;
				count = 1;
			}

			if (count != 1)
				cout << "\tFalse";

			cout << "\n";
		}
	}

	~Hash()
	{
		if (queue)
			delete[] queue;

		if (status)
			delete[] status;
	}

};


int main()
{
	//--------Q2-------------

	cout << "Hash Array h2 :\n\n";
	Hash<int> h2(7);

	h2.insert(50);
	h2.insert(700);
	h2.insert(76);
	h2.insert(85);
	h2.insert(92);
	h2.insert(73);
	h2.insert(101);

	h2.printHashArray();

	system("pause");
	return 0;
}