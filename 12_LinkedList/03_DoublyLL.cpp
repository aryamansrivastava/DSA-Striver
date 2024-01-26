// Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

class Node {
        public:
        int data;
        Node* next;
        Node* back;

        // Constructor to create a Node
        public:
        Node(int data1, Node* next1, Node* back1) { 
                data = data1;
                next = next1;
                back = back1;
        }
        public:
        Node(int data1) {
                data = data1;
                next = NULL;
                back = NULL;
        }

        //TO DO: Write a destructor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << " deleted" << endl;
        }
};

Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]); 
    Node* prev = head;             
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;    
        prev = temp;         
     }
    return head;  
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

Node* deleteHead(Node* head){
        // LL is empty or just have Single node
        if(head==nullptr || head->next==NULL){
                return NULL;
        }
        Node* prev = head;
        head = head->next;

        head->back = nullptr;
        prev->next = nullptr;

        delete prev;
        return head;
}

Node* deleteTail(Node* head){
        // LL is empty or just have Single node
        if(head==nullptr || head->next==NULL){
                return NULL;
        }
        Node* tail = head;
        while(tail->next!=NULL){
                tail=tail->next;
        }
        Node* newTail = tail->back;
        newTail->next = nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
}

Node* deleteFromPos(Node* head, int position) {
        int length = findLength(head);
        if(position>length){
                cout << "Enter a valid Position " << endl;
        }
        if(head == NULL) {
                cout << "Linked list is empty";
        }
        int cnt=0;
        Node* kNode = head = head;
        while(kNode != NULL){
                cnt++;
                if(cnt==position) break;
                kNode = kNode->next;
        }
        Node* prev = kNode->back;
        Node* front = kNode->next;

        if(prev == NULL && front == NULL){
                return NULL;
        }
        else if(prev == NULL){
                return deleteHead(head);
        }
        else if(front==NULL){
                return deleteTail(head);
        }
        prev->next = front;
        front->back = prev;

        kNode->next=nullptr;
        kNode->back=nullptr;
        delete kNode;
        return head;
}

void deleteNode(Node* temp) {
        Node* prev = temp->back;
        Node* front = temp->next;

        if(front==NULL){
                prev->next = nullptr;
                temp->back = nullptr;
                free(temp);
                return;
        }
        prev->next = front;
        front->back = prev;

        temp->next = temp->back = nullptr;
        free(temp);
}

//I want to insert a node right before the head of Doubly Linked List
Node* insertBeforeHead(Node* &head, int data) {
        Node* newHead;
        // empty DLL pe kaam nhi kar raha
        //check for Empty LL
        if(head == NULL) {
            newHead = new Node(data);
            head = newHead;
        }
        else {
        // LL is Non Empty
        // created a new head with next pointing to head and back pointing to null
            newHead = new Node(data,head,nullptr);
            head->back = newHead;
        }
        return newHead;
}

//I want to insert a node right before the end of Doubly LINKED LIST
Node* insertBeforeTail(Node* head, int data) {
        if(head == NULL) {
            // LL is Empty
            Node* newNode = new Node(data);
            head = newNode;
        }
        // contains single node
        if(head->next==NULL){
                return insertBeforeHead(head,data);
        }
        //else
        Node* tail=head;
        while(tail->next!=NULL){
                tail=tail->next;
        }
        Node* prev = tail->back;
        Node* newNode = new Node(data,tail,prev);
        prev->next = newNode;
        tail->back = newNode;
        return head;
}

Node* insertAfterTail(Node* head, int data){
        if(head==NULL){
                return new Node(data);
        }
        Node* tail = head;
        while(tail->next!=NULL){
                tail=tail->next;
        }
        Node* prev = tail;
        Node* newNode = new Node(data,nullptr,prev);
        prev->next = newNode;
        tail->next = newNode;
        return head;
}

Node* insertBeforeKthElement(Node* head, int data, int k) {
        int length = findLength(head);
        if(k==1){
                return insertBeforeHead(head, data);
        }
        else if(k>length){
                return insertAfterTail(head, data);
        }
        Node* temp = head;
        int cnt=0;
        while(temp!=NULL){
                cnt++;
                if(cnt==k) break;
                temp = temp->next;
        }
        Node* prev = temp->back;
        Node* newNode = new Node(data,temp,prev);
        prev->next = newNode;
        temp->back = newNode;
        return head;    
} 

void insertBeforeNode(Node* node, int data){
        Node* prev = node->back;
        Node* newNode = new Node(data, node, prev);
        prev->next = newNode;
        node->back = newNode;
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

        vector<int> arr = {12,5,8,6,18};
        Node* head = convertArr2DLL(arr);
        Node* tail = new Node(arr[4]);

        // head = deleteHead(head);
        // head = deleteTail(head);
        // head = deleteFromPos(head,4);
        // deleteNode(head->next->next->next->next);
        // head = insertBeforeHead(head,15);
        // head = insertBeforeTail(head,10);
        // head = insertAfterTail(head,10);
        // head = insertBeforeKthElement(head,15,6);
        insertBeforeNode(head->next->next,100);
        print(head);

    return 0;
}