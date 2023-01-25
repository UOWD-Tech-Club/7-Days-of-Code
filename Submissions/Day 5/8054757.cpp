#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
public:
	Node(int input)
	{
		data = input;
		next = NULL;
	}
	void setNext(Node* inputNext)
	{
		next = inputNext;
	}
	Node* getNext()
	{
		return next;
	}
	~Node()
	{
		data = NULL;
		next = NULL;
	}
	int getData()
	{
		return data;
	}
};

class List
{
private:
	Node* head;
	Node* tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	void pushBack(int data)
	{
		Node* node = new Node(data);
		if (!tail)
		{
			tail = node;
			head = node;
			return;
		}
		tail->setNext(node);
		tail = node;
	}
	void pushFront(int data)
	{
		Node* node = new Node(data);
		if (!head)
		{
			tail = node;
			head = node;
			return;
		}
		node->setNext(head);
		head = node;
	}
	unsigned length()
	{
		if (!head) return 0;
		Node* curr=head;
		unsigned count=0;
		while (curr)
		{
			curr = curr->getNext();
			count++;
		}
		return count;
	}
	int getData(unsigned pos)
	{
		try {
			if (!head) throw(string("List empty"));
			Node* curr = head;
			for (int i = 0; i != pos&&curr; ++i)
			{
				curr = curr->getNext();
			}
			if (curr)
			{
				return curr->getData();
			}
			throw(string("Out of range"));
		}
		catch (string err) { cout << err << endl; exit(1); }
	}
	void pop()
	{
		try
		{
			if (!head) throw(string("List empty"));
			Node* trash = head;
			head = head->getNext();
			if (!head) tail = NULL;
			delete trash;
		}
		catch (string err) { cout << err << endl; exit(1); }
	}
	void pop(unsigned pos)
	{
		try
		{
			if (!head) throw(string("List empty"));
			if (pos == 0)
			{
				pop();
				return;
			}

			Node* curr = head;
			for (int i = 1; i != pos && curr->getNext(); ++i)
			{
				curr = curr->getNext();
			}
			if (curr->getNext())
			{
				Node* trash = curr->getNext();
				curr->setNext(trash->getNext());
				delete trash;
				return;
			}
			throw(string("Out of range"));
		}
		catch (string err) { cout << err << endl; exit(1); }
	}
	void printList()
	{
		if (!head)
		{
			cout << "[]" << endl;
			return;
		}
		Node* curr = head->getNext();
		cout << "[ " << head->getData();
		while (curr)
		{
			cout<<", "<< curr->getData();
			curr=curr->getNext();
		}
		cout << " ]" << endl;
	}
	
	~List()
	{
		if (!head) return;
		while (head)
		{
			pop();
		}
	}
};

int main()
{
	List list;
	list.pushBack(4);
	list.pushBack(5);
	list.pushFront(3);
	int a=list.getData(2);
	list.printList();
	cout <<"list[2] = "<< a << endl;
	list.pop();
	cout << "After pop: ";
	list.printList();
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(8);
	list.printList();
	cout << "After pop 4th element: ";
	list.pop(4);
	list.printList();
	cout << "List length: " << list.length() << endl;
	cout << "try to pop 10th element " << endl;
	list.pop(10);
	return 0;
}