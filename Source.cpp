#include<iostream>
using namespace std;
template <class T>
class Node
{
public:
	Node<T>* prev;
	T info;
	Node* next;
	Node()
	{
		prev = nullptr;
		info = 0;
		next = nullptr;
	}
	Node(int val)
	{
		prev = nullptr;
		info= val;
		next = nullptr;

	}

};
template <class T>
class DoublyLinkedList
{
	Node<T>* head;
public:
	DoublyLinkedList()
	{
		head = nullptr;
	}
	void insert(int val)
	{
		
		if (!head)
		{
			Node<T>* temp;
			head = new Node<T>(val);
			
		}
		else
		{
			Node<T>* temp = head;
			Node<T>* beforeToBefore = temp;
			while (temp->next!=nullptr)
			{
				beforeToBefore = temp;
				temp = temp->next;

			}
			temp->next = new Node<T>(val);
			temp->prev = beforeToBefore;
			
		}
	}
	void addAtHead(int val)
	{
		if (!head)
		{
			head = new Node<T>(val);
			
		}
		else
		{
			Node<T>* temp = head;
			Node<T>* newnode = new Node<T>(val);
			newnode->next = head;
			newnode->prev = nullptr;
			head->prev = newnode;
			head = newnode;
			
			
			
		}
	}
	void insertAtTail(int val)
	{
		Node<T>* temp = head;

		while (temp->next != nullptr)
		{
			
			temp = temp->next;
		}
		Node<T>*n = new Node<T>(val);
		temp->next = n;
		n->prev = temp;
		
	}
	void addBefore(int targetValue, int newValue)
	{
		Node<T>* temp1 = head;
		Node<T>* newnode = new Node<T>(newValue);
		while (temp1->data!=targetValue)
		{
			temp1 = temp1->next;
		}
		Node<T>* temp2;
		temp2 = temp1->prev;
		temp1->prev = newnode;
		temp1->prev = nullptr;
		temp2->next = nullptr;
		temp2->next = newnode;
		newnode->next = temp1;
		newnode->prev = temp2;



	}
	void addAfter(int targetValue, int newValue)
	{

		Node<T>* temp = head;
		Node<T>* newnode = new Node<T>(newValue);
		while (temp->data != targetValue)
		{
			temp = temp->next;
		}
		
		newnode->next = temp->next;
		if (temp->next!=nullptr)
		{
			temp->next->prev = newnode;
		}
		temp->next = nullptr;
		temp->next = newnode;
		newnode->prev = temp;
	}
	void deleteAtHead()
	{
		if (!head)
		{

			exit(0);
		}
		else
		{
			Node<T>* temp = head->next;
			temp->next->prev = nullptr;
			delete head;
			head = temp;
		}
	}
	void deleteAtTail()
	{
		Node<T>* temp = head;
		Node<T>* prev = temp;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		delete temp;
		temp = nullptr;
		prev->next = nullptr;
	}
	void deleteAfter(int targetValue)
	{
		Node* temp = head;
		
		while (temp->data!=targetValue)
		{

			temp = temp->next;
		}
		if (temp->next->next==nullptr)
		{
			Node<T>* prev = temp;
			prev->next = nullptr;
			temp = temp->next;
			delete temp;
			temp = nullptr;

		}
		else
		{
			Node<T>* prev = temp;
			Node<T>* after = temp->next->next;
			temp = temp->next;
			delete temp;
			temp = nullptr;
			prev->next = after;
			after->prev = prev;
		}
		
	

	}
	void display()
	{
		if (!head)
		{
			exit(0);
		}
		else
		{
			Node<T>* temp = head;
			while (temp != nullptr)
			{
		    	cout << temp->info;
				temp = temp->next;
				
				
			}
			
			
		}

	}
	~DoublyLinkedList()
	{

		if (head == nullptr)
		{

			return;
		}
		else
		{

			Node<T>* temp=head;
			while (head->next != nullptr)
			{
				temp = head->next;
				delete head;
				head = temp;


			}
			delete head;
			head = nullptr;
			cout << "Doubly Linked list destroyed!\n";
		}

	}
	int getLength()
	{
		Node<T>* temp = head; int length = 0;
		while (temp!=nullptr)
		{
			temp = temp->next;
			length++;
		}
		return length;
	}
	DoublyLinkedList(const DoublyLinkedList<T>& other)
	{
		head = nullptr;
		if (!other.head)
			return;

		Node<T>* temp = other.head;
		while (temp != nullptr)
		{
			insertAtTail(temp->info);
			temp = temp->next;
		}
	}

	Node<T>* search(T x)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == x)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	// Insert at specific position (1-based index)
	void insertAtPosition(int pos, T val)
	{
		if (pos <= 0)
		{
			cout << "Invalid position!" << endl;
			return;
		}

		if (pos == 1)
		{
			addAtHead(val);
			return;
		}

		Node<T>* temp = head;
		int count = 1;
		while (temp->next != nullptr && count < pos - 1)
		{
			temp = temp->next;
			count++;
		}

		if (count == pos - 1)
		{
			Node<T>* newNode = new Node<T>(val);
			newNode->next = temp->next;
			if (temp->next != nullptr)
			{
				temp->next->prev = newNode;
			}
			newNode->prev = temp;
			temp->next = newNode;
		}
		else
		{
			cout << "Position out of bounds!" << endl;
		}
	}

	// Delete at specific position (1-based index)
	void deleteAtPosition(int pos)
	{
		if (!head || pos <= 0)
		{
			cout << "Invalid position!" << endl;
			return;
		}

		if (pos == 1)
		{
			deleteAtHead();
			return;
		}

		Node<T>* temp = head;
		int count = 1;
		while (temp != nullptr && count < pos)
		{
			temp = temp->next;
			count++;
		}

		if (temp != nullptr)
		{
			if (temp->prev != nullptr)
			{
				temp->prev->next = temp->next;
			}
			if (temp->next != nullptr)
			{
				temp->next->prev = temp->prev;
			}
			delete temp;
		}
		else
		{
			cout << "Position out of bounds!" << endl;
		}
	}

	// Delete node before the node with targetValue
	void deleteBefore(int targetValue)
	{
		if (!head || head->info == targetValue)
		{
			cout << "No node exists before the target value!" << endl;
			return;
		}

		Node<T>* temp = head;
		while (temp != nullptr && temp->info != targetValue)
		{
			temp = temp->next;
		}

		if (temp == nullptr || temp->prev == nullptr)
		{
			cout << "No node exists before the target value!" << endl;
			return;
		}

		Node<T>* nodeToDelete = temp->prev;
		if (nodeToDelete->prev != nullptr)
		{
			nodeToDelete->prev->next = temp;
		}
		else
		{
			head = temp;
		}
		temp->prev = nodeToDelete->prev;
		delete nodeToDelete;
	}

};
int main()
{
	DoublyLinkedList<int> dll;
	dll.addAtHead(3);
	dll.addAtHead(2);
	dll.addAtHead(1);
	dll.display();
	
	
}