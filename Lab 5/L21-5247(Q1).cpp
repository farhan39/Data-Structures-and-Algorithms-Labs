// Muhammad Farhan Bukhari---------------BCS - 3F1-----------------21L-5247
// Lab 5(Stack)

#include<iostream>
#include<string>

using namespace std;

const int size = 10;

template<class T>
class Stack
{
	T myArray[size];
	int count;

public:
	Stack()
	{
		count = 0;
	}

	void push(T element)
	{
		if (count < size)
		{
			myArray[count] = element;
			++count;
		}
		else cout << "Space not available.\n";
	}

	bool isFull()
	{
		return count == size;
	}

	int sizeOfStack()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	bool top(T&)
	{
		return myArray[count];
	}

	void pop()
	{
		if (count != 0)
		count--;
	}

	bool isBalanced(string exp)
	{
		int expLen = exp.length();

		if (exp[0] != '\0')
		{
			Stack myStack;
			for (int i = 0 ; i < expLen; ++i)
			{
				switch(exp[i])
				{
					case '[':
					case '{':
					case '(':
						myStack.push(exp[i]);
						break;
			
					case ']':
					case '}':
					case ')':
						myStack.pop();
						break;
				}
			}
			if (myStack.isEmpty())
			return true;
		}
		return false;
	}
};

int main ()
{
	Stack<int> st1;
	
	for (int i = 0; i < 5; ++i)
		st1.push(i);

	string str = "[]{}([])";
	bool temp = st1.isBalanced(str);

	if (temp)
	cout << "String is balanced.";

	system("pause");
	return 0;
}