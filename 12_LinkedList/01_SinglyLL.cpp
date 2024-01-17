// Singly Linked List

#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        // Constructor to create a Node

        Node() { 
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }

        //TO DO: Write a destructor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << " deleted" << endl;
        }
};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1: create a node
                Node* newNode = new Node(data);
                //step2: connect with head node
                newNode -> next = head;
                //step3: update head as head is always the first node
                head = newNode;
        }
}

//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head, Node* &tail, int data) {
        if(tail == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: create a node
        Node* newNode = new Node(data);
        //step2: connect with tail node
        tail->next = newNode;
        //step3: update tail because tail should always be the last node;
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

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
    //Check empty LL
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
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Step 1: find the position of: previous and current pointer

    int i = 1;
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    // Step 2: Create a node 
    Node* newNode = new Node(data);

    // Step 3: 
    newNode -> next = curr;

    // Step 4:
    prev -> next = newNode;

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

int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail, 20);
        insertAtHead(head, tail, 50);
        insertAtHead(head, tail, 60);
        insertAtHead(head, tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail -> data << endl;

        insertAtPosition(101, 5 , head, tail);

        cout << "After Insertion at some position: ";

        print(head);
        cout << endl; 
        // cout << "Updated head: " << head -> data << endl;
        // cout << "Updated tail: " << tail -> data << endl;

        deleteNode(5, head, tail);
        cout << "After Deletion of Node: ";
        print(head);

        return 0;
}