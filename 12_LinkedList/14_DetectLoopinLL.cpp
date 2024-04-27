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

/*
Intution for fast and slow pointers:

- If there would be cycle, then for sure "FAST" and "SLOW" will always meet inside the cycle
Why?
- Lets say they have distance "d".
- After each iteration fast moves 2 steps towards slow, and slow moves 1 step away from fast.
- So now the distance between them would be "d-1";
...
...
...
After some iterations, these "d" will be 0 and both fast and slow will meet at a common node.
*/

bool detectCycle(Node *head) {
    bool cycleFound = false;
    Node* slow = head;
    Node* fast = head;

   while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycleFound = true;
            break;
        }
    }
    return cycleFound;
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

    // Check if there is a loop 
    // n the linked list
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}