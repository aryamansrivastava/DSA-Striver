// Problem: Inorder Predecessor in BST


//              BST
//               5
//            /      \
//          2         7
//       /    \     /   \
//      1     4     6     9
//           /           /  \
//         3            8    10

// inorderPredecessor(8) = 7
// inorderPredecessor(3) = 2

// inorderSuccessor(8) = 9
// inorderSuccessor(3) = 4

// Brute Force Approach -> 
// To store the InOrder traversal of BST in a vector then easily 
// find successor and predecessor
// TC -> O(N) For traversing nodes(Iterative or Recursive Traversal) in Traversal and O(N) for iterating to find the final ans
// SC -> O(N) For storing the Inorder in a vector or a List

// ** If we perform Morris Traversal then Space Complexity ~ O(1)


// This is the Optimal approach ->

// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Space

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

Node* inorderPredecessor(Node* root, int val) {
    Node* predecessor = NULL;

    while(root) {
        // If the value at the current node is greater than or equal to the target value,
        // move to the left subtree to find a smaller value
        if(root->data >= val) {
            root = root->left;
        }
        // If the value at the current node is less than the target value,
        // update the predecessor and move to the right subtree to potentially find a larger value
        else {
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}

Node* inorderSuccessor(Node* root, int val) {
    Node* successor = NULL;

    while(root != NULL) {
        // If the value at the current node is less than or equal to the target value,
        // move to the right subtree to find a larger value
        if(root->data <= val) {
            root = root->right;
        }
        // If the value at the current node is greater than the target value,
        // update the successor and move to the left subtree to potentially find a smaller value
        else {
            successor = root;
            root = root->left;
        }
    }
    
    return successor;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    int val1 = 8;
    cout << "Inorder Predecessor of " << val1 << " is: " << inorderPredecessor(root, val1)->data << endl;
    val1 = 3;
    cout << "Inorder Predecessor of " << val1 << " is: " << inorderPredecessor(root, val1)->data << endl;

    int val2 = 6;
    cout << "Inorder Successor of " << val2 << " is: " << inorderSuccessor(root, val2)->data << endl;
    val2 = 7;
    cout << "Inorder Successor of " << val2 << " is: " << inorderSuccessor(root, val2)->data << endl;
    return 0;
}