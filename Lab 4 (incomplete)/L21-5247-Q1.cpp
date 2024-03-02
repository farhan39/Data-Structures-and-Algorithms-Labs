// Muhammad Farhan Bukhari---------------BCS-3F------------------21L-5247

#include<iostream>
using namespace std;

template<class T>
class DLList{		//circular linked list with DLL node

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
	
	class ListIterator 
	{
		public:
				ListIterator(T value = 0)
				{ 
					iptr = new DLLNode(value);
				}

				ListIterator& operator++(const T)
				{
					if (iptr) iptr = iptr->next;
					return (*this);
				}

				bool operator==(const ListIterator & l)
				{
					return iptr == l.iptr;
				}

				bool operator!=(const ListIterator & l)
				{
					return iptr != l.iptr;
				}

				ListIterator::ListIterator(const ListIterator & myItr)
				{
					this->iptr = myItr.iptr;
					return *this;
				}

				T& operator* ()
				{
					return iptr->data;
				}
		private:
				friend class DLList;
				DLLNode* iptr;
	};

	DLLNode *tail;

public:
	typedef ListIterator Iterator;
	DLList() 
	{
		tail = 0;
	}

	void insertAfterTail(const T& element)
	{
		if (tail)
		{
			tail->previous->next = tail->next->previous = tail = new DLLNode(element, tail, tail->next);
		}
		else 
		{
			tail->next = tail->previous = tail = new DLLNode(element);
		}
	}

	void checkSum(DLList<T>& l1, Iterator current)
	{
		Iterator Itr1 = current;
		Iterator Itr2;
		T sum = 0;

		for (; Itr1.iptr->next != Itr1.iptr;)
		{
			for (Itr2 = Itr1; Itr2.iptr->next != Itr1.iptr; Itr2++)
			{
				sum += Itr2.iptr->data;
			}
			if (sum % 2 == 0)
			{
				DLLNode* temp = Itr1.iptr;
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				delete temp;

			}
			Itr1++;
		}
	}


	/*void deleteFromStart()
	{
		DLLNode* temp = head;
		temp->next->previous = nullptr;
		head = temp->next;
		delete temp;
	}*/

	/*void deleteFromEnd() 
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
	}*/

	~DLList()
	{
		if (tail)
		{
			DLLNode* temp = tail;
			while (temp != tail->previous)
			{
				tail->previous->next = tail->next;
				tail->next->previous = tail->previous;
				tail = tail->next;
				delete temp;
				temp = tail;
			}

			temp = tail;
			tail = nullptr;
			delete temp;
		}
	}


	void print()
	{
		if (!tail)
			return;

		if (tail->next == tail)
		{
				cout << tail->data << " ";
		}
		else
		{
			cout << tail->data << " ";
			for (DLLNode* temp = tail->next; temp != tail; temp = temp->next)
				cout << temp->data << " ";
		}
	}

	Iterator begin()
	{
		Iterator I(tail->data);
		return I;
	}

	Iterator specificElement(const T)
	{
		Iterator
	}

	Iterator end()
	{
		Iterator I(tail->previous);
		return I;
	}

};

int main ()
{
	DLList<int> myList;

	myList.insertAfterTail(5);
	myList.insertAfterTail(4);
	myList.insertAfterTail(3);
	myList.insertAfterTail(2);
	myList.insertAfterTail(1);
	myList.insertAfterTail(6);

	cout << "List after initialising :\n";
	myList.print();

	int currentValue = 5;
	DLList<int>::Iterator Itr1(currentValue);

	//myList.checkSum(myList, Itr1);

	myList.print();

	system("pause");
	return 0;
}


// Muhammad Farhan Bukhari---------------BCS-3F1---------------21L-5247
//
//#include<iostream>
//using namespace std;
//
//
//template<class T>
//class List
//{
//private:
//	struct Node
//	{
//		Node()
//		{
//			next = NULL;
//
//		}
//		Node(T info, Node* nxt = NULL)
//		{
//			data = info;
//			next = nxt;
//
//		}
//
//		T data;
//		Node* next;
//
//	};
//	class ListIterator {
//	public:
//		ListIterator(Node* ptr = NULL)
//		{
//			iptr = ptr;
//		}
//		T& operator*() {
//
//			return iptr->data;
//
//		}
//		bool operator==(const ListIterator& l) const
//		{
//
//			return iptr == l.iptr;
//
//		}
//		bool operator!=(const ListIterator& l) const {
//
//			return !(iptr == l.iptr);
//
//		}
//		ListIterator& operator++(int)
//		{
//			ListIterator a = *this;
//			++(*this);
//			return a;
//		}
//		ListIterator& operator++()
//		{
//			if (iptr) iptr = iptr->next;
//			return (*this);
//		}
//	private:
//
//		Node* iptr;
//
//	};
//	Node* tail;
//	Node* head;
//public:
//
//	typedef ListIterator Iterator;
//	Iterator begin()
//	{
//		Iterator I(head); return I;
//	}
//	Iterator end()
//	{
//		Iterator I(tail); return I;
//	}
//
//	List()
//	{
//		tail = NULL;
//		head = NULL;
//	}
//	~List() {}
//
//	bool isEmpty()
//	{
//		return (tail == NULL);
//	}
//
//	void addToTail(T el) {
//		if (isEmpty()) {
//			tail = new Node(el);
//			tail->next = tail;
//			head = tail;
//		}
//		else {
//			tail->next = new Node(el, tail);
//			tail = tail->next;
//			tail->next = head;
//		}
//	}
//
//	void print()
//	{
//		Iterator lit;
//		for (lit = begin();; lit++)
//		{
//			cout << *lit << "   ";
//			if (lit == end())
//			{
//				break;
//			}
//		}
//		cout << endl;
//	}
//
//	int CalculateSum()
//	{
//		Iterator l2;
//		int nextsum = 0;
//		for (l2 = begin();; l2++)
//		{
//			nextsum = nextsum + *l2;
//			if (l2 == end())
//			{
//				break;
//			}
//		}
//		return nextsum;
//	}
//
//	void initialiZeNodeToZero(T const& No)
//	{
//		Node* tmp;
//		for (tmp = tail->next;; tmp = tmp->next)
//		{
//			if (tmp->data == No)
//			{
//				tmp->data = 0;
//				break;
//			}
//			if (tmp == tail)
//			{
//				break;
//			}
//		}
//	}
//
//	void deleteZeros()
//	{
//			Node* temp;
//			for (temp = head; temp != tail; temp = temp->next)
//			{
//				while(temp->data == 0)
//				{
//					temp->next = temp->next->next;
//					temp = temp->next;
//				}
//			}
//
//	}
//
//	void Q1()
//	{
//		Iterator l1 = begin();
//		int sum = 0;
//		int count = 0;
//		for (;; l1++)
//		{
//			sum = CalculateSum();
//			sum = sum - *l1;
//
//			if (sum % 2 == 0)
//			{
//				initialiZeNodeToZero(*l1);
//			}
//			if (l1 == end())
//			{
//				break;
//			}
//		}
//
//	}
//};
//
//
//
//int main()
//{
//	List<int> myList;
//	myList.addToTail(5);
//	myList.addToTail(8);
//	myList.addToTail(2);
//	myList.addToTail(9);
//	myList.addToTail(1);
//	myList.addToTail(7);
//	myList.addToTail(6);
//	
//	cout << "Before performing Q1 my List is :\n";
//	myList.print();
//
//	cout << "Making all elements zero before they are deleted :\n";
//	myList.Q1();
//	myList.print();
//
//	myList.deleteZeros();
//	cout << "After performing Q1 my List :\n";
//	myList.print();
//	cout << endl;
//
//	system("pause");
//	return 0;
//}