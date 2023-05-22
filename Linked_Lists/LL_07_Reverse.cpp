#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
struct Node* head;

void reverse(){
    struct Node* back=NULL;
    struct Node* curr=head;
    struct Node* front;

    while(curr!=NULL){

        front=curr->next;
        
        //changing LINKS :--
        curr->next=back;

        // Moving the pointers :--
        back=curr;
        curr=front;

        //Case of 1st Node :--
        if(back==head){
        back->next=NULL;
        }
        head=back; // move head;
    }
}

void InsertAtBeginnig(int x){
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(head != NULL){  //implies not empty list
        temp->next=head;
    }     
    head=temp;    //head pointing at new FIRST NODE.
}
void display(){
    struct Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    printf("\n");

}

int main(){
    head=NULL;
    int x;
    cout<<"Enter the Numbers :\n";
    for (int i = 0; i < 4; i++)
    {
        cin>>x;
        InsertAtBeginnig(x);
    }
    display();
    reverse();
    cout<<"Reversed Linked is :-"<<endl;
    display();
     
     return 0;
}