#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
void deletion(node *head, int data)
{
    node *temp = head;
    while (temp->next->data != data)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void reverse(node *&head)
{
    node *current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int digit(node *&head)
{
    int d = 0;
    node *curr_ptr = head;
    for (int i = 2; i >= 0; i--)
    {
        d += pow(10, i) * curr_ptr->data;
        curr_ptr = curr_ptr->next;
    }

    return d;
}

void mod1(node *&head, int sum)
{
    int d;
    while (sum != 0)
    {
        d = sum % 10;
        sum = sum / 10;
        insert(head, d);
    }
}

int main()
{
    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;

    cout << "First Linked List: ";
    insert(head, 7); // First list
    insert(head, 1);
    insert(head, 5);
    display(head);

    cout << endl;

    cout << "Second Linked List: ";
    insert(head1, 5); // Second List
    insert(head1, 9);
    insert(head1, 2);
    display(head1);
    cout << endl
         << endl;

    cout << "Reversed First Linked List: ";
    reverse(head);
    display(head);
    int val1 = digit(head);

    cout << endl;

    cout << "Reversed Second Linked List: ";
    reverse(head1);
    display(head1);
    int val2 = digit(head1);

    cout << endl
         << endl;

    int sum = val1 + val2;
    cout << "Sum of reversed Linked List: " << sum;
    cout << endl;

    mod1(head2, sum);
    cout << "Reversed Linked of Sum: ";
    display(head2);

    return 0;
}