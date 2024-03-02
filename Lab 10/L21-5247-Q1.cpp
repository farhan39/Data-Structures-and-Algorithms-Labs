// Muhammad Farhan Bukhari-------------BCS - 3F-------------21L-5247
// Lab 10 (Hashing)---Q1

#include<iostream>
#include<assert.h>

using namespace std;

template<class T>
class Hash
{
	T* hashArray;
	bool* status;
	int capacity;

public :
		Hash()
		{
			size = 10;
			hashArray = new T [capacity];
			status = new bool [capacity];
		}

		Hash(int const capacity1)
		{
			assert(capacity1 > 1);

			capacity = capacity1;

			hashArray = new T [capacity];
			status = new bool[capacity];
		}

		void insert(T const key)  //without chaning (Q1)
		{
			hashArray[key % capacity] = key;
			status[key % capacity] = true;
		}

		bool deleteKey(T const key)
		{
			for (int i = 0; i < capacity; ++i)
			{
				if (status[i] == true)
				{
					hashArray[i] == key;
					hashArray[i] = 1;
					return true;
				}
			}
			return false;
		}

		void printHashArray()
		{
			for (int i = 0; i < capacity; ++i)
				if (status[i] == true)
					cout << hashArray[i] << "\n";
				else cout << "false\n";
			cout << endl;
		}

		~Hash()
		{
			if (hashArray)
				delete hashArray;
			if (status)
				delete status;
		}

};


int main()
{
	Hash<int> h1(15);

//--------Q1-------------
	cout << "Hash Array h1 :\n\n";
	h1.insert(10);
	h1.insert(7);
	h1.insert(18);
	h1.insert(51);

	h1.printHashArray();

	system("pause");
	return 0;
}