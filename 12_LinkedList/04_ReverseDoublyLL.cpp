#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *back;
    Node *next;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr) {

    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        // Move 'prev' to the newly created
        // node for the next iteration
        prev = temp;       
    }
    return head;  
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;         
    }
}

// Stack Brute Force Approach
// Time Complexity : O(2N) 
// Space Complexity : O(N) 
Node* reverseDLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    stack<int> st;

    Node* temp = head;
    
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    
    // Second iteration of the DLL to replace the values
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    } 

    return head;
}

// In-place link exchange method
// Time Complexity : O(N) 
// Space Complexity : O(1)

Node* reverseDoubleLinkedList(Node *head){
    if(head == NULL || head->next == NULL) // There are 0 or 1 node;
        return head;

    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        prev = curr->back;
        // Swap the previous and
        // next pointers
        curr->back = curr->next;
        // This step reverses the links
        curr->next = prev;
        // Move to the next node
        curr = curr->back;
    }
    return prev->back;
}

int main(){

    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    Node *newHead = reverseDoubleLinkedList(head);
    cout<<"NEW HEAD = "<<newHead->data<<endl;
    while(newHead!=NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    
    return 0;
}