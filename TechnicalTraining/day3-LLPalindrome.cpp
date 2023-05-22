#include <iostream>
#include <string>

using namespace std;


struct ListNode {
    string val;
    ListNode* next;
    ListNode(string x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true;
    }
    
 
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
 
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = prev;
    
 
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p2) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
}

int main() {
    

    // LIST is:  anna bob anna

    ListNode* head = new ListNode("anna");
    head->next = new ListNode("bob");
    head->next->next = new ListNode("anna");
    


    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    
    return 0;
}
