#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node*next;
};
struct Node*first=NULL;
struct Node*last=NULL;

void InsertLast( int x){
    struct Node *t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
void display(struct Node *p){
    while(p){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<endl;
}



int main(){
    InsertLast(3);    
    InsertLast(15);    
    InsertLast(18);
    InsertLast(29);
    display(first);
     
     return 0;
}