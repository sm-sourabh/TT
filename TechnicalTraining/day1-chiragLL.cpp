#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{
	Node *head,*tail;
	int size;
	
	public:
	
	LinkedList()
	{
		head = tail = NULL;
		size = 0;
	}
	
	void insert(int data)
	{
		if(head==NULL)
		{
			head = tail = new Node(data);
		}
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
		}
		size++;
	}
	
	void print()
	{
		Node *current = head;
		
		while(current!=NULL)
		{
			cout<<current->data<<" ";
			current = current->next;
		}
		cout<<endl;
		return;
		
	}
	
	void deleteNode(int k)
	{
		if(k>size)
		  return;
		 
		if(k==1)
		{
			head = head->next;
			size--;
			
			if(size==0)
			  tail = NULL;
			return;
		}
		  
		int p = 2;
		Node *prev = head;
		Node *current = head->next;
		
		while(true)
		{
			if(p==k)
			{
		      	prev->next = current->next;
		      	size--;
		      	if(current->next==NULL)
		      	{
		      		tail = prev;
				}
				break;
			}
			prev = current;
			p++;
			current = current->next;
		}
		
	}
	
};


int main()
{
	LinkedList L;
	L.insert(67);
	L.insert(56);
	L.insert(34);
	L.print();
	L.insert(33);
	L.print();
	L.insert(67);
	L.insert(456);
	L.insert(12);
	L.print();
	L.deleteNode(2);
	L.print();
	L.deleteNode(1);
	L.print();
	L.deleteNode(4);
	L.print();
	
	return 0;
}