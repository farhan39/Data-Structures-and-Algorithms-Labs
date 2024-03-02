// Muhammad Farhan Bukhari-----------BCS - 3F1----------21L-5247
// Lab 5 (Queue)

#include<iostream>
using namespace std;

template<class T>
class Queue
{
private :

	struct Node
	{
	public:

		Node(T val = 0, Node* nptr = nullptr)
		{
			data = val;
			next = nptr;
		}

		~Node()
		{
		}

		T data;
		Node* next;
		// no destructor as head and tail are pointers to list elements.
	};
	
	Node* head;
	Node* tail;
	int size;
public :

	Queue()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	Queue<T>& operator = (const Queue<T>& obj)
	{
		if (obj.size != 0)
		{
			Node* temp = obj.head;

			while (temp != nullptr)
				this->enqueue(temp->data);
		}

		return this;
	}

	void enqueue(T element)
	{
		if (size == 0)
		{
			head = tail = new Node(element);
			++size;
			return;
		}

		head = new Node(element, head);
		++size;
	}

	int sizeOfQueue()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int front()
	{
		return head->data;
	}

	int rear()
	{
		return tail->data;
	}

	void print()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	bool checkConsecutiveTriples()
	{
		if (size == 1 || size == 0)
			return true;

		Node* start = head;
		Node* temp = head->next;

		int count = 0;

		if (size == 2)
		{
			if (temp->data - 1 == start->data)
				return true;
		}

		if (size == 3)
		{
			for (int i = 0; i < 3; ++i)
			{
				if (temp->data - 1 ==  start->data)
					++count;
			}

			if (count == size)
				return true;
		}

		count = 0;

		while (temp != nullptr)
		{
			for(int i = 0; i < 3; ++i)
				if (temp->next != nullptr && (temp->data - 1 == start->data))
				{
					start = temp;
					temp = temp->next;
					++count;
				}

			if(count == 3)
			{
				for (int i = 0 ; i < 2 ; ++i)
				{
					start = temp;
					if (temp->next != nullptr)
					temp = temp->next;
					else 
					{
						temp = nullptr;
						break;
					}
				}
			}
				
			else return false;
		}
		return true;
	}

	~Queue()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void alternateArrangementQueue(Queue<T>& src, Queue<T>& dest)
	{
		if (size % 2 == 0 && size >= 4)
		{
			Node* start = src.head;
			Node* temp = src.head;

			for (int i = 0 ; i < size/2; ++i)
				temp = temp->next;

			for (int i = 0 ; i < size ; ++i)
			{
				dest.enqueue(start->data);
				dest.enqueue(temp->data);
				start = start->next;
				
				if (temp->next != nullptr)
				temp = temp->next;

				else return;
			}
		}
	}
};

int main ()
{
	Queue<int> q1;

	for (int i = 5; i > 0; --i)
		q1.enqueue(i);


	Queue<int> q2;

	q2.enqueue(15);
	q2.enqueue(13);
	q2.enqueue(12);
	q2.enqueue(11);
	q2.enqueue(5);
	q2.enqueue(4);
	q2.enqueue(3);
	q2.enqueue(2);
	q2.enqueue(1);


	cout << "\nThe queue 1 after being initialized :\n";
	q1.print();

	cout << "\nThe queue 2 after being initialized :\n";
	q2.print();

	cout << "\nAfter checking q2 checkConsecutiveTriples :\n";
	cout << q2.checkConsecutiveTriples();

	Queue<int> q3;
	q3.enqueue(1);
	q3.enqueue(2);
	q3.enqueue(3);
	q3.enqueue(4);
	q3.enqueue(5);
	q3.enqueue(6);

	Queue<int> finalQueue;

	q3.alternateArrangementQueue(q3, finalQueue);

	cout << "\nQueue 3 after alternate arrangement :\n";
	finalQueue.print();

	cout << endl;
	system("pause");
	return 0;
}