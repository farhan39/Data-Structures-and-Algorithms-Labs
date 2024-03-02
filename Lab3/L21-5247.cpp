#include<iostream>
using namespace std;

template<class T>

class DLList{

public:
	DLList() 
	{
		head = tail = 0;
	}

	void insertAtHead(const T& element)
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				DLLNode* ptr = new DLLNode(element, 0, head);
				head = ptr;
			}
			else 
			{
				DLLNode* ptr = head;
				ptr->previous = new DLLNode(element, nullptr, ptr);
				head = ptr->previous;
			}
		}
		else
		{
			DLLNode* ptr = new DLLNode(element, nullptr, nullptr);
			head = tail = ptr;
		}
	}

	void insertAtTail(const T& element) 
	{
		if (tail != 0) 
		{
			DLLNode * newnode = new DLLNode(element,tail, 0);
			tail->next = newnode;
			tail = newnode;
		}
		else
		{
			head = tail = new DLLNode(element);
		}
	}

	void deleteFromStart()
	{
		DLLNode* temp = head;
		temp->next->previous = nullptr;
		head = temp->next;
		delete temp;
	}

	void deleteFromEnd() 
	{
		if (head != NULL) 
		{
			if (head == tail) 
			{
				delete head;
				head = tail = 0;
			}

			else 
			{
				tail = tail->previous;
				delete tail->next;
				tail->next = nullptr;
			}
		}
	}

	/*~DLList()
	{
		if (head)
		{
			DLLNode* temp = head;
			while (temp != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
		}
	}*/


	void print()
	{
		for (DLLNode* temp = head; temp != nullptr; temp = temp->next)
			cout << temp->data << " ";
	}

	void insertSorted(const T& element)
	{
		DLLNode* temp1 = head;
		for (; temp1->data < element || temp1->data == element; temp1 = temp1->next);
		
		if (temp1 != nullptr)
		{
			DLLNode* temp2 = new DLLNode(element, temp1->previous, temp1);
			temp2->next->previous = temp2;
			temp2->previous->next = temp2;
		}
		else 
		{
			DLLNode* temp = new DLLNode(element, tail, 0);
			tail->next = temp;
			tail = temp;
		}

	}

	void swapNodes(int n)
	{
		DLLNode* temp1 = head;
		DLLNode* temp2 = tail;
		int i = 0, j = 0;
		for (; i < n ; temp1 = temp1->next,++i);
		for (; j < n ; temp2 = temp2->previous,++j);

		int var = temp1->data;
		temp1->data = temp2->data;
		temp2->data = var;
		
	}

	void Union(DLList& A, DLList B)
	{
		DLLNode* temp = B.head;
		for (; temp != nullptr; temp = temp->next)
			A.insertAtTail(temp->data);
	}


	void deleteDuplicates()
	{
		
	}

private:
	struct DLLNode
	{

	public:
		DLLNode() 
		{
			next = prev = 0;
		}

		DLLNode(const T & el, DLLNode *p = 0, DLLNode *n = 0) 
		{
			data = el; previous = p; next = n; 
		}

		T data;
		DLLNode *previous, *next;
	};
	
	DLLNode *head, *tail;
};

int main()
{
//----------------Q1-------------------

	DLList<int> myList;
	myList.insertAtHead(4);
	myList.insertAtHead(3);
	myList.insertAtHead(2);
	
	myList.print();
	cout << endl;
	myList.insertAtTail(5);
	myList.insertAtTail(6);
	myList.insertAtTail(7);
	myList.insertAtTail(8);
	myList.insertAtTail(9);
	
	myList.print();
	
	myList.deleteFromStart();
	myList.deleteFromStart();
	myList.deleteFromEnd();
	myList.deleteFromEnd();

	cout << "\nAfter deleting two elements from start and two from end\n";
	myList.print();
//-----------------------------Q2---------------------

	cout << endl;
	myList.insertSorted(5);

	myList.print();

	myList.insertAtTail(6);
	myList.insertAtTail(7);
	myList.insertAtTail(8);
	myList.insertAtTail(9);

	cout << "\nBefore swapping :\n";
	myList.print();
	cout << endl;

	cout << "After swapping :\n";
	myList.swapNodes(2);
	myList.print();
	cout << endl;

	DLList<int> myList1;

	myList1.insertAtTail(11);
	myList1.insertAtTail(12);
	myList1.insertAtTail(13);
	myList1.insertAtTail(14);
	myList1.insertAtTail(15);

	//myList.deleteDuplicates();

	cout << "myList1 :\n";
	myList1.print();
	cout << "\nUnion of myList and myList1 is :\n";
	myList.Union(myList, myList1);
	myList.print();

	system("pause");
	return 0;
}