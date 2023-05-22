#include <iostream>
using namespace std;

#define INT_MIN 0

class Node{
public:
	int val;
	Node *next;

	Node(){
		this->val = INT_MIN;
		this->next = NULL;
	}
	
	Node(int x){
		val = x;
		this->next = NULL;
	}
};


class LL{
	Node *head;

public:
	LL(){
		this->head = NULL;
	}

	void insertAtBegin(int x){
		Node *n1 = new Node(x);
		n1->next = head;
		head = n1;
	}
	

	void insertAtEnd(int x){
		Node *n1 = new Node(x);
		if(head==NULL){
			head=n1;
			return ;
		}
		Node *temp = head;

		while(temp->next){
			temp = temp->next;
		}
		temp->next = n1;
	}

	void deleteAtBegin(){
		if(!head){
			cout<<"Underflow: No data to delete.";
			return ;
		}
		head = head->next;
	}

	void delet_Value(int x){
		if(!head){
			cout<<"Underflow: No data to delete.";
			return ;
		}
		Node *prev=NULL , *curr=head;
		bool flag=true;

		while(curr){
			if(curr->val == x){
				flag=false;
				Node *temp = curr;
				prev->next = curr->next;
				curr->next = prev;
				// delete(curr);
				// delete(temp);
			}
			prev = curr;
			curr = curr->next;
		}

		if(flag){
			cout<<"There exist no element which is asked to delete.\n";
		}else{
			cout<<"Deleted\n";
		}
		
	}
	
	void deleteAtEnd(){
		if(!head){
			cout<<"Underflow: No data to delete.";
			return ;
		}
		Node *temp = head;

		while(temp->next->next){
			temp = temp->next;
		}
		temp->next = NULL;
	}
	
	void printList(){
		if(!head){
			cout<<"Underflow: No data to print.";
			return ;
		}
		Node *temp = head;

		while(temp){
			cout<<temp->val<<"->";
			temp = temp->next;
		}
        cout << endl;

	}
	
	Node* getHead(){return this->head;}
	
	int getSize(){
	    if(!head)return 0;
	    if(!head->next)return 1;
	
	    Node *curr = head;
	    int ans=0;
	
	    while(curr){
	        curr  = curr->next;
	        ans++;
	    }
	    return ans;
	}

    
	void sorting(){
	    Node *temp1 = head, *temp2 = head;
	    while(temp1->next){
	        temp2 = temp1->next;
	        while(temp2){
	            if(temp2->val < temp1->val){
	                int temp = temp2->val;
	                temp2->val = temp1->val;
	                temp1->val = temp;
	            }
	            temp2 = temp2->next;
	        }
	        temp1 = temp1->next;
	    }
	
	}

};

int main(){

	LL linkedList;
	linkedList.insertAtEnd(5);			    // 
	linkedList.insertAtEnd(6);				// 
	linkedList.insertAtEnd(7);				// 
	linkedList.insertAtEnd(8);				// 
	cout << "Linked List : ";
    linkedList.printList();
    cout << "Delete at end : ";
    linkedList.deleteAtEnd();
    linkedList.printList();

    linkedList.delet_Value(6);
    cout << "Delete  Value :";
	linkedList.printList();

    cout << "Insert at begin : ";
    linkedList.insertAtBegin(99);
    linkedList.printList();
	return 0; 
}