#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL; 

void create(int A[],int n){  ///creation
    int i;
    struct Node*t,*last;
    first=new Node;
    first->data=A[0 ];
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
void displayIterative(struct Node*p){  
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }  
    cout<<endl;
}
int max(struct Node *p){
    int max=INT_MIN;
    while(p){
        if(p->data>max)
            max=p->data;
        p=p->next; 
    }
    return max;
}
int maxReccur(struct Node *p){
    int x=INT_MIN;
    if(p==0)
        return x;
    else{
        x=maxReccur(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}

struct Node* lsearch(struct Node*p,int key){
    while(p){
        if(key==p->data){
            return p;
        } 
        p=p->next;
    }
    return NULL;
}

struct Node* lsearchRecurr(struct Node*p, int key){
    if(p==NULL)
        return NULL;
    if(p->data==key)
        return p;
     
    return lsearchRecurr(p->next,key);
}

//move to front function
struct Node*lsearchImproved2(struct Node*p,int key){
    struct Node*q=NULL;
    while(p){
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

/// INSERTION IN A LL , BEORE 1ST NODE , MIDDLE AND AT END;--

void insert(struct Node*p,int POS,int x){
    struct Node* t;
    t=new Node;
    t->data=x;
    
    if(POS==0){
        
        t->next=first;
        first=t;
    }
    else{
        p=first;
        for (int i = 0; i < POS-1 && p; i++) // && is used here to check two values ie i<POS-1 and also p not equal to ZERO
        {
            p=p->next;
        }
        if(p){
        t=new Node;
        t->data=x;    
        t->next=p->next;
        p->next=t;
        }
    }

}

int main(){
    int A[]={8,3,7,12,9,25};
    create(A,6);
    displayIterative(first);
    printf("MAX value Ierative func is %d\n",max(first));
    printf("MAX value using Reccurfunc is %d\n",maxReccur(first));
    
    struct Node*temp,*temp2,*temp3;
    temp=lsearch(first ,9);
    if(temp)
        printf("KEY FOUND ,Equals to : %d\n", temp->data);
    else
        printf("KEY NOT FOUND\n");
   
    temp2=lsearchRecurr(first ,25);
    if(temp2)
         printf("KEY FOUND at %d\n", temp->data);
    else
    printf("KEY NOT FOUND\n");
    
    
    temp3=lsearchImproved2(first,12);
    if(temp3)
         printf("KEY FOUND at %d\n", temp->data);
    else
    printf("KEY NOT FOUND\n");

    displayIterative(first);
    insert(first,4,20);
    insert(first,0,10);
    displayIterative(first);

    return 0;
}