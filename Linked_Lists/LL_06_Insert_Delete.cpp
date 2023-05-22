/////          Inserting at Nth position and at end.

#include <iostream>
using namespace std;

struct  Node{
    int data;
    struct Node* next;
};
struct Node* head;

void display(){
    struct Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    printf("\n");

}

void Insert_Index(int x,int n){
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(n==1){
        temp->next=head;
        head=temp;
        return;
    }
    ///Going to (N-1)th Node 
    struct Node*p=head;
    for(int i=0;i<n-2;i++){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}

int delete_Node(int n){
    int x;
    Node* prev=NULL;
    Node* curr=head;
    prev=NULL;
    
    if(n==1){
        head=curr->next;
        x=curr->data;
        free(curr);
        return x;
    }
    curr=head;
    for (int i = 0; i < n; i++)
    {
       prev=curr;
       curr=curr->next; 
    }
   prev->next=curr->next;
   x=curr->data;
   free(curr);
   return x;
    
}



int main(){
    head=NULL;
    Insert_Index(1,1);
    Insert_Index(2,2);
    Insert_Index(3,3);
    Insert_Index(4,4);
    Insert_Index(5,5);
    Insert_Index(6,6);
    cout<<"Linked List After deletion : ";
    display();
    cout<<delete_Node(2)<<endl;
    cout<<"Linked List After deletion : ";
    display();
     return 0;
}