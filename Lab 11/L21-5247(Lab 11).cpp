// Muhammad Farhan Bukhari------21L-5247------BCS-3F1
// Lab 11 (Heaps)

#include <iostream>
using namespace std;

template<class T>
class MaxHeap
{
	T* heapPtr;
	int totalCapacity;
	int sizeOfHeap;

public:

	MaxHeap()
	{
		heapPtr = nullptr;
		totalCapacity = sizeOfHeap = 0;
	}

	MaxHeap(int n)
	{
		totalCapacity = n;
		heapPtr = new T[totalCapacity];
		sizeOfHeap = 0;
	}

	void Insert(T element)
	{
		if (sizeOfHeap == totalCapacity)
		{
			T* temparr = new T[sizeOfHeap];
			for (int i = 0; i < sizeOfHeap; i++)
				temparr[i] = heapPtr[i];

			delete[] heapPtr;

			totalCapacity = totalCapacity * 2;
			heapPtr = new T[totalCapacity];

			for (int i = 0; i < sizeOfHeap; i++)
			{
				heapPtr[i] = temparr[i];
			}

			delete[] temparr;
			heapPtr[sizeOfHeap] = element;
			sizeOfHeap++;	
			
			buildHeapFromArray(heapPtr);
		}

		else
		{
			heapPtr[sizeOfHeap] = element;
			sizeOfHeap++;
			
			buildHeapFromArray(heapPtr);
		}
	}

	bool checkMaxHeap(MaxHeap& obj)
	{
		return isMaxHeap(obj.heapPtr, 0, 1, 0);
	}

	bool isMaxHeap(T* heapPtr, int i,int j,int k)
	{
		if (i == sizeOfHeap / 2 || j>=sizeOfHeap)
			return true;

		if (heapPtr[i] < heapPtr[j])
			return false;
			
		j++;
		k++;

		if (k == 2)
		{
			k = 0;
			i++;
		}
		
		return isMaxHeap(heapPtr, i, j, k);
	}

	void buildHeap(T*& heapPtr, int sizeOfPtr)
	{
		// Index of last non-leaf node
		int startIdx = (sizeOfPtr / 2) - 1;

		// Perform reverse level order traversal
		// from last non-leaf node and heapify
		// each node
		for (int i = startIdx; i >= 0; i--)
		{
			heapify(heapPtr, sizeOfPtr, i);
		}
	}

	void heapify(T*& heapPtr, int sizeOfPtr, int i)
	{
		int largest = i; // Initialize largest as root
		int l = 2 * i + 1; // left = 2*i + 1
		int r = 2 * i + 2; // right = 2*i + 2

		// If left child is larger than root
		if (l < sizeOfPtr && heapPtr[l] > heapPtr[largest])
			largest = l;

		// If right child is larger than largest so far
		if (r < sizeOfPtr && heapPtr[r] > heapPtr[largest])
			largest = r;

		// If largest is not root
		if (largest != i)
		{
			T temp = heapPtr[i];
			heapPtr[i] = heapPtr[largest];
			heapPtr[largest] = temp;

			// Recursively heapify the affected sub-tree
			heapify(heapPtr, sizeOfPtr, largest);
		}
	}

	void buildHeapFromArray(T* heapPtr)
	{
		buildHeap(heapPtr, sizeOfHeap);
	}

	void Print()
	{
		for (int i = 0; i < sizeOfHeap; i++)
			cout << heapPtr[i] << "\t";
		cout << endl;
	}

	T& GetMax()
	{
		return heapPtr[0];
	}

	T getkth(int k)
	{
		int n = 0;
		T el = heapPtr[0];

		T* arr1 = new T[sizeOfHeap];
		for (int i = 0; i < sizeOfHeap; i++)
			arr1[i] = heapPtr[i];

		sort(heapPtr);
		return heapPtr[k - 1];
	}


	void sort(T* heapPtr) //w
	{
		for (int i = 0; i < sizeOfHeap; i++)
		{
			for (int j = i + 1; j < sizeOfHeap; j++)
			{
				if (heapPtr[i] < heapPtr[j])
				{
					T b = heapPtr[i];
					heapPtr[i] = heapPtr[j];
					heapPtr[j] = b;
				}
			}
		}
	}

	void MergeHeaps(MaxHeap& obj1,MaxHeap& obj2)
	{
		T* arr1 = obj1.heapPtr;
		T* arr2 = obj2.heapPtr;

		int newSize = obj1.sizeOfHeap + obj2.sizeOfHeap;
		this->totalCapacity = this->sizeOfHeap = newSize;

		this->heapPtr = new T [this->totalCapacity];

		for (int i = 0; i < obj1.sizeOfHeap; i++)
			this->heapPtr[i] = arr1[i];

		int j = 0;
		for (int i = obj1.sizeOfHeap; j < obj2.sizeOfHeap; i++,j++)
			this->heapPtr[i] = arr2[j];

		buildHeapFromArray(this->heapPtr);
	}

	~MaxHeap()
	{
		if (heapPtr)
			delete[] heapPtr;

		heapPtr = nullptr;
	}
};

int main()
{
	MaxHeap<int> mh1(5);
	mh1.Insert(100);
	mh1.Insert(50);
	mh1.Insert(15);
	mh1.Insert(200);
	mh1.Insert(12);

	cout << "\nMax heap mh1 is : ";
	mh1.Print();

	MaxHeap<int> mh2(9);
	mh2.Insert(5);
	mh2.Insert(10);
	mh2.Insert(4);
	mh2.Insert(100);
	mh2.Insert(95);
	mh2.Insert(107);
	mh2.Insert(94);
	mh2.Insert(93);
	mh2.Insert(12);

	cout << "\n\nMax heap mh2 is : ";
	mh2.Print();

	MaxHeap<int> mh3;
	mh3.MergeHeaps(mh1, mh2);

	cout << "\n\nMh1 and Mh2 after merging : ";
	mh3.Print();

	cout << "\nValidating checkMaxHeap function, passing mh1 as parameter : \n";
	if (mh1.checkMaxHeap(mh1))
		cout << "True\n";
	else cout << "False\n";

	cout << "\nValidating heapify function for array1 declared in main :\n";
	
	int* myarray1 = new int [10];
	myarray1[0] = 1;
	myarray1[1] = 4;
	myarray1[2] = 100;
	myarray1[3] = 45;
	myarray1[4] = 3;
	myarray1[5] = 76;
	myarray1[6] = 69;
	myarray1[7] = 34;
	myarray1[8] = 31;
	myarray1[9] = 11;

	cout << "\nBefore converting array1 into maxheap :\n";
	for (int i = 0; i < 10; ++i)
		cout << myarray1[i] << " ";

	mh3.heapify(myarray1, 10, 0);

	cout << "\n\nAfter converting array1 into maxheap :\n";
	for (int i = 0; i < 10; ++i)
		cout << myarray1[i] << " ";

	delete[] myarray1;
	myarray1 = nullptr;

	cout << "\n\nGetMax function testing for mh1 : " << mh1.GetMax();

	cout << "\n\nValidating 2nd largest from mh1 : " << mh1.getkth(2); 
	cout << "\nValidating 3rd largest from mh1 : " << mh1.getkth(3); 
	cout << "\nValidating 5th largest from mh2 : " << mh2.getkth(5); 
	cout << "\nValidating 6th largest from mh2 : " << mh2.getkth(6); 
	cout << "\nValidating 4th largest from mh3 : " << mh3.getkth(4); 
	cout << "\nValidating 5th largest from mh3 : " << mh3.getkth(5) << endl << endl; 

	system("pause");
	return 0;
}