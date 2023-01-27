// 21.01.2023 - 8054757 - Matvei Maslov
// Question 1
#include <iostream>
#include <vector>
using namespace std;

class Node
{
	friend class HashTable;
private:
	Node* next;
	string data;
	string key;
public:
	Node(string key,string data)
	{
		this->key = key;
		this->data = data;
		next = NULL;
	}
};
class HashTable
{
private:
	vector<Node*>* table;
	unsigned size;
	unsigned step = 3;//set so small to show reorganization
	unsigned countBusy;
	unsigned hash(string data)
	{
		unsigned hash = 0;
		for (int i = 0; i < data.size(); ++i)
		{
			hash += hash * 37 + (int)data[i];
		}
		return hash%size;
	}
	void add(Node* node)
	{
		int pos = hash(node->key);
		node->next = NULL;
		if (table->data()[pos])
		{
			Node* curr = table->data()[pos];
			while (curr->next) curr = curr->next;
			curr->next = node;
			return;
		}
		table->data()[pos] = node;
		countBusy++;
	}
	Node* findNode(string key)
	{
		int pos = hash(key);
		Node* curr = table->data()[pos];
		while (curr)
		{
			if (curr->key == key) return curr;
			curr = curr->next;
		}
		return NULL;
	}
public:
	HashTable()
	{
		table = new vector<Node*>(step);
		size = step;
		countBusy = 0;
	}
	HashTable(unsigned size)
	{
		step = size;
		table = new vector<Node*>(step);
		this->size = size;
		countBusy = 0;
	}
	void add(string key,string data)
	{
		if (countBusy == size)
		{
			countBusy = 0;
			size += step;
			vector<Node*>* tmp = table;
			table = new vector<Node*>(size);
			for (int i=0;i<size-step;++i)
			{
				Node* curr = tmp->data()[i];
				while (curr)
				{
					Node* prev = curr;
					curr = curr->next;
					add(prev);
				}
			}
			delete tmp;
		}
		Node* node = new Node(key,data);
		int pos = hash(key);
		if (table->data()[pos])
		{
			Node* curr = table->data()[pos];
			while (curr->next) curr = curr->next;
			curr->next = node;
			return;
		}
		table->data()[pos] = node;
		countBusy++;
	}

	string find(string key)
	{
		if (countBusy == 0)
		{
			throw(string("Nothing in table!"));
			return NULL;
		}
		Node* node = findNode(key);
		if (!node)
		{
			throw(string("Not Found!"));
			return NULL;
		}
		return node->data;
	}
	unsigned getSize()
	{
		return size;
	}
	unsigned getNumBusy()
	{
		return countBusy;
	}
	void remove(string key)
	{
		if (countBusy == 0)
		{
			throw(string("Nothing in table!"));
			return;
		}
		int pos = hash(key);
		Node* curr = table->data()[pos];
		if (!curr) throw(string("Not Found!"));
		if (curr->key == key)
		{
			table->data()[pos] = curr->next;
			delete curr;
			return;
		}
		while (curr->next)
		{
			if (curr->next->key == key)
			{
				Node* trash = curr->next;
				curr->next = curr->next->next;
				delete trash;
				return;
			}
			curr = curr->next;
		}
		throw(string("Not Found!"));
	}

	void print()
	{
		if (countBusy == 0) return;
		for (int i = 0; i < size; ++i)
		{
			cout << i << ". ";
			Node* curr = table->data()[i];
			while (curr)
			{
				cout <<curr->key<<':'<< curr->data << "->";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	HashTable table;
	table.add("1a2", "21");
	table.add("23", "32");
	table.add("3c4", "43");
	table.add("45", "54");
	table.add("5e6", "65");
	table.add("6f7", "76");
	cout << "Size table: " << table.getSize() << endl;
	cout << "Busy positions: " << table.getNumBusy() << endl << endl;
	table.print();
	cout <<endl<< "Try to remove key 45" << endl;
	try {
		table.remove("45");
	}
	catch (string err) { cout << err << endl; }
	table.print();
	cout << endl << "Try to remove key 77" << endl;
	try {
		table.remove("77");
	}
	catch (string err) { cout << err << endl; }
	table.print();
	cout << endl<<"Show data from key 6f7: ";
	try
	{
		cout << table.find("6f7") << endl;
	}
	catch (string err) { cout << err << endl; }
}