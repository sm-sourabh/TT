#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
//struct Node* head;  Global variable can be accessed anywhere

Node* InsertAtBeginnig(Node *head,int x){ // this head is different from the head in main ()
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(head != NULL){  //implies not empty list
        temp->next=head;
    }     
    head=temp;    //head pointing at new FIRST NODE.
    return head;
}
void Display(Node * head){   // this head is different from the head in main ()
    //struct Node *temp=head;  //local variable because we do not want to change the refernce of head \. Thus we copy head's value in temporary variable and modify that.
    cout<<"List is: "<<endl;
    while(head !=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    printf("\n");
}



int main(){
    Node *head=NULL;  // head as local variable
    int x;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter the Number :\n";
        cin>>x;
        head=InsertAtBeginnig(head,x);
        Display(head);

    }
    
     return 0;
}