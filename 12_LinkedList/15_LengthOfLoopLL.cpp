#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    
    Node(int n){
        data = n;
        next = NULL;
    }
};

// Using Tortoise and Hare Algorithm (fast and slow pointers)
int lengthOfLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return findLength(slow,fast);
        }
    }
    return 0;
}

int findLength(Node* slow, Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int main(){
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    cout << "Length of Loop in LL is: " << lengthOfLL(head) << endl;

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}