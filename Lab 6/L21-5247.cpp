// Muhammad Farhan Bukhari---------------BCS-3F--------------21L-5247

#include<iostream>
using namespace std;

int isMember(int arr[], int size, int key)
{
	if (size <= 0)
		return -1;

	if (arr[size] == key)
		return 0;
	else 
		return isMember(arr, size - 1, key);
}

int sum_digit(int num)
{
	int sum = 0;
	if (num < 10)
		return num;

	else
	{
		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}
		sum_digit(sum);
	}
}

void flipFloat(int start, int end, float arr[], int size)
{
	if (start == size/2)
		return;

	float temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	flipFloat(start + 1, end - 1, arr, size);
}

int stringCompare(char* arr1, char* arr2, int index)
{
	int index1 = index;

	int size1 = strlen(arr1);
	int size2 = strlen(arr2);

	if (index1 == size1 && arr1[index1] == arr2[index1])
		return 0;

	if (size1 != size2)
		return -1;

	if (arr1[index1] == arr2[index1])
		stringCompare(arr1, arr2, index1 + 1);
	else return -1;

}

int main ()
{
	int arr[] = {0, 1, 2, 3, 4 , 5, 6};
	cout << isMember(arr, 10, 7) << endl;	  //Q1

	cout << sum_digit(795) << endl;		//Q2

	float arr1[] = {0.01, 1.1, 2.56, 3.45, 4.9, 91.2, 6.5};

	cout << "Before flipFloat() :\n";
	for (int i = 0 ; i < 7 ; ++i)
		cout << arr1[i] << " ";

	flipFloat(0, 6, arr1, 7);     //Q3

	cout << "\nAfter flipFloat :\n";
	for (int i = 0 ; i < 7 ; ++i)
		cout << arr1[i] << " ";

	char array1[] = {"HEllo"};
	char array2[] = {"HEllo"};

	cout << endl << stringCompare(array1, array2, 0) << endl;	// ---------Q4--------passed 0 as dummy index for checking corresponding values at this index.

	system("pause");
	return 0;
}