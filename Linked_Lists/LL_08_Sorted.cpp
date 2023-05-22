#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
struct Node*head;

void Sorted_Insert(int x){
    Node*temp=new Node();
    temp->data=x;
    temp->next=NULL;

    if(head && temp->data <x){
        temp->next=head;
        head=temp;
    }

    Node *temp2=NULL;
    while(temp && temp->data < x){
        temp2=temp;
        temp=temp->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}



int main(){
    head=NULL;
    int x;
    for (int i = 0; i < 4; i++)
    {
        cin>>x;

    }
    
    
     
     return 0;
}