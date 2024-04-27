// Singly Linked List

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int n){
        data = n;
        next = NULL;
    }

    Node(int n, Node* ptr){
        data = n;
        next = ptr;
    }
};

int lengthOfLL(Node *head){
    Node *current = head;
    int len = 0;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

void printLL(Node* head){
    Node* current = head;
    while(current!= NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

Node* convertArray2LL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]); // Creating a new node
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;
    while (temp != nullptr) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found
        // Move to the next node
        temp = temp->next;
    }
    return 0; 
}

int main(){
    vector<int> arr = {12,4,6,2};
    Node *head = convertArray2LL(arr);
    printLL(head);
    cout<<lengthOfLL(head)<<endl;
    int val = 7;
    cout << checkifPresent(head,val) << endl;
    return 0;
}