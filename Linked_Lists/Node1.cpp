#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node* head;  //Global variable can be accessed anywhere

void InsertAtBeginnig(int x){
    struct Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(head != NULL){  //implies not empty list
        temp->next=head;
    }     
    head=temp;    //head pointing at new FIRST NODE.
}
void Display(){
    struct Node *temp=head;  //local variable because we do not want to change the refernce of head \. Thus we copy head's value in temporary variable and modify that.
    cout<<"List is: "<<endl;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    printf("\n");
}



int main(){
    head=NULL;  // Empty List
    int x;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter the Number :\n";
        cin>>x;
        InsertAtBeginnig(x);
        Display();

    }
    
     return 0;
}