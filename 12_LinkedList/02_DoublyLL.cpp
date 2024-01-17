// Doubly Linked List

#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;
        Node* prev;

        // Constructor to create a Node

        Node() { 
                this->data = 0;
                this->prev = NULL;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->prev = NULL;
                this->next = NULL;
        }

        //TO DO: Write a destructor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << " deleted" << endl;
        }
};

//I want to insert a node right at the head of Doubly Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else {
            // LL is Non Empty
            //step1: create a node
            Node* newNode = new Node(data);
            //step2:
            newNode -> next = head;
            //step3:
            head->prev = newNode;
            //step3: update head
            head = newNode;
        }
}

//I want to insert a node right at the end of Doubly LINKED LIST
void insertAtTail(Node* &head, Node* &tail, int data) {
        if(tail == NULL) {
            // LL is Empty
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        // LL is Not Empty
        //step1: create a node
        Node* newNode = new Node(data);
        //step2: 
        tail->next = newNode;
        //step3:
        newNode -> prev = tail;
        //step4: update tail
        tail = newNode;
}

void print(Node* head) {
 
        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    // Check empty LL
    if(head == NULL && tail==NULL){
        Node* newNode = new Node(data);  
        head  = newNode;
        tail = newNode;
        return;
    }

    // Edge cases handle kiya hai ye (jab (zeroth) ya (>=length of LL) position par insertion hoga)
    if(position == 0) {
        insertAtHead(head, tail , data);
        return;
    }

    int len = findLength(head);     
    if(position > len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Insertion in Middle
    // Step 1: find the position of: previous and current pointer

    int i = 1;
    Node* prevNode = head;
    while(i < position - 1){
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode -> next;

    // Step 2: Create a node 
    Node* newNode = new Node(data);

    // Step 3: 
    prevNode -> next = newNode;
    newNode -> prev = prevNode;
    curr -> prev = newNode;
    newNode -> next = curr;

}

void deleteNode(int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                cout << "Cannot delete, LL is empty";
                return;
        }

        // deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }

        int len  = findLength(head);

        // Deleting last node

        if(position == len) {
                // find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                // step2:
                Node* temp = tail;

                // step3:
                prev->next = NULL;

                // step4:
                tail = prev;

                // step5:
                delete temp;
                return;
        }

        // Deleting middle node

        // Step 1 : find prev and curr
        int i = 1;
        Node* prev = head;
        while( i < position-1) {
                prev = prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        // Step2:
        prev -> next = curr -> next;

        // Step3:
        curr -> next = NULL;

        // Step4:
        delete curr;
}

void deleteFromPos(Node* &head, Node* &tail, int position) {
        if(head == NULL) {
                cout << "Linked list is empty";
                return;
        }
        if(head -> next == NULL) {
                //single node
                Node* temp = head;
                head = NULL;
                tail = NULL;
                delete temp;
                return;
        }
        int len = findLength(head);
        if(position > len) {
                cout << "please enter a valid position " << endl;
                return;
        }

        if(position == 1) {
                //want to delete the first node
                Node* temp = head;
                head = head ->next;
                head -> prev = NULL;
                temp ->next = NULL;
                delete temp;
                return;
        }
        
        if(position == len) {
                //delete last node
                Node* temp = tail;
                tail = tail -> prev;
                temp -> prev = NULL;
                tail ->next = NULL;
                delete temp;
                return;
        }

        //delete from middle of linked list

        //step1: find left, curr, right
        int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;

}

// Node* reverse(Node* prev, Node* &curr) {
//         //base case
//         if(curr == NULL) {
//                 //LL reverse ho chuki
//                 return prev;
//         }
        
//         //1 case solve then recursion will take care
//         Node* forward = curr -> next;
//         curr -> next = prev;

//         reverse(curr, forward);
// }

// Node* reverseusingLoop(Node* head ) {
//         Node* prev = NULL;
//         Node* curr = head;

//         while(curr != NULL ) {
//                 Node* temp = curr ->next;
//                 curr ->next = prev;
//                 prev = curr;
//                 curr = temp;
//         }
//         return prev;
// }

// Node* reverseusingRecursion(Node* prev, Node* curr) {
//         //base case
//         if(curr == NULL) 
//                 return prev;

//         Node* temp = curr ->next;
//         curr ->next = prev;
//         prev = curr;
//         curr = temp;

//         //recursion sambhal lega
//         return reverseusingRecursion(prev, curr);
// }

int main() {

        Node* first = new Node(10);
        Node* second = new Node(20);
        Node* third = new Node(30);
        Node* head = first;
        Node* tail = third;
        
        //Creation of a doubly Linked List
        first -> next = second;
        second -> prev = first;

        second ->next = third;
        third->prev = second;

        // print(first);
        // cout << endl;

        insertAtHead(head,tail, 101);

        print(head);
        cout << endl;

        insertAtTail(head,tail, 50);

        print(head);
        cout << endl;

        insertAtPosition(head,tail, 401, 5);

        print(head);
        cout << endl;
  
        // deleteFromPos(head, tail, 10);

        // cout << endl;
        // print(head);
        // cout << endl;

    return 0;
}