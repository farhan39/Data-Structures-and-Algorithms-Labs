
// Muhammad Farhan Bukhari--------------BCS - 3F---------------21L-5247
#include<iostream>
using namespace std;

template<class T>
class Vector
{
	T* myArray;
	int mySize;

public:
	Vector()
	{
		myArray = nullptr;
		mySize = 0;
	}

	Vector(int size1)
	{
		if (size1 > 0)
		{
			mySize = size1;
			myArray = new int [mySize];

			for (int i = 0 ; i < mySize; ++i)
			{
				myArray[i] = 0;
			}
		}
		else myArray = nullptr;
	}

	Vector(T* array1, int size1)
	{
		mySize = size1;
		myArray = new int [size1];

		for (int i = 0; i < size1; ++i)
			myArray[i] = array1[i];
	}

	Vector(const Vector &obj)
	{
		mySize = obj.mySize;
		if (myArray)
			delete[] myArray;
		myArray = new T [mySize];
		for (int i = 0 ; i < mySize; ++i)
			myArray[i] = obj.myArray[i];
	}

	~Vector()
	{
		if (myArray)
		delete[] myArray;
	}

	bool findItem(int key)
	{
		for (int i = 0 ; i < mySize ; ++i)
		{
			if (myArray[i] == key)
				return true;
		}
		return false;
	}

	void sortArray()
	{
	  for (int i = 0 ; i < mySize-1 ; ++i)
	  for (int j = 0 ; j < mySize-1 ; ++j)
	  {
		  if (myArray[j] > myArray[j+1])
		{
			myArray[j] = myArray[j] + myArray[j+1];
			myArray[j+1] = myArray[j] - myArray[j+1];
			myArray[j] = myArray[j] - myArray[j+1];
		}
	  }
	}

	Vector operator = (const Vector &obj)
	{
		Vector finalVector;
		finalVector.mySize = obj.mySize;
		for (int i = 0 ; i < mySize ; ++i)
		{
			finalVector.myArray[i] = obj.myArray[i];
		}
		return finalVector;
	}

	T& operator [] (int n)
	{
		if (n <= mySize && n > 0)
		{
			return myArray[n];
		}
	}

	void display()
	{
		for (int i = 0; i < mySize; ++i)
			cout << myArray[i] << " ";
		cout << endl;
	}

};

int main ()
{
	int arr[5] = {16,5,8,11,21};

	Vector<int> vc1(arr, 5);
	Vector<int> vc2(6);

	cout << "vc 1 :\n";
	vc1.display();
	cout << "vc 2 :\n";
	vc2.display();

	cout << "\nvc1.findItem(3) :	" << vc1.findItem(3) << "\n";

	Vector<int> vc3;
	vc3 = vc1;

	cout << "\nvc3 = vc1 :	";
	vc3.display();

	cout << "vc3[3] = " << vc3[3] << endl;

	vc1.sortArray();

	cout << "\nvc1 after sorting :\n";
	vc1.display();

	system("pause");
	return 0;
}