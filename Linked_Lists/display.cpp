#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;    // is same as under

// struct node *first;   ca nalso be written like this

void create(int A[],int n){  ///creation
    int i;
    struct Node*t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

                        ///////// display function
void displayIterative(struct Node*p){  
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }  
    cout<<endl;
}

void displayRecurrsive(struct Node *p){
    if(p!=0){
        printf("%d\t",p->data);
        displayRecurrsive(p->next);
    }
}

void displayRecReverseOrder(struct Node *p){
    if(p!=0){
        displayRecReverseOrder(p->next);
        printf("%d\t",p->data);
    }
}

                    ///////  COUNT AND SUM FUNCTIONS-- //
int countIterative(struct Node *p){
    int count;
   while (p!=0)
   {
       p=p->next;
       count++;
   }
   return count; 
}

int countRecurisve(struct Node *p){
    int count;
    if(p==0)
        return 0;
    else
        return countRecurisve(p->next) + 1;
}

int sumRecursive(struct Node *p){
    int sum=0;
    if(p==0)
        return 0;
    else 
        return sumRecursive(p->next)+p->data;
}

int sumIteravtive(struct Node *p){
    int sum=0;
    while (p!=0)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;  
}

int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    displayIterative(first);
    
    displayRecurrsive(first);
    cout<<endl;
    displayRecReverseOrder(first);
    cout<<endl;
    cout<<"Lenght of the LL is : "<<countIterative(first)<<endl;
    cout<<countRecurisve(first)<<endl;
    cout<<sumIteravtive(first)<<endl;
    cout<<sumRecursive(first)<<endl;


     
     return 0;
}
