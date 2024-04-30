// Problem: Ceil and Floor in a Binary Search Tree

//              BST
//               8
//             /   \
//           5       12
//         /  \    /   \
//        4   7   10   14
//          /          /
//         6         13

// Ceil means val>=key -> means aisi value chahiye jo key se >= ho
// Ceil(10) = 10
// Ceil(9) = 10

// Floor means val<=key -> means aisi value chahiye jo key se <= ho
// Floor(10) = 10
// Floor(9) = 8

// Same for both Ceil and Floor
// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Data Structure

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node() {
            data = 0;
            left = NULL;
            right = NULL;
        }

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

int ceilInBST(Node* root, int key) {
    int ceil = -1;
    while(root != NULL) {
        if(root->data == key) {
            ceil = root->data;
            break;
        }
        else if(root->data > key) {
            ceil = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return ceil;
}

int floorInBST(Node* root, int key) {
    int floor = -1;
    while(root) {
        if(root->data == key) {
            floor = root->data;
            break;
        }
        else if(key < root->data) {
            root = root->left;
        }
        else {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);

    int key = 10;
    cout << "Ceil of key " << key << " is " << ceilInBST(root, key) << endl;
    key = 9;
    cout << "Ceil of key " << key << " is " << ceilInBST(root, key) << endl;

    // Floor In BST
    cout << "Floor of key " << key << " is " << floorInBST(root, key) << endl;
    key = 9;
    cout << "Floor of key " << key << " is " << floorInBST(root, key) << endl;
    return 0;
}