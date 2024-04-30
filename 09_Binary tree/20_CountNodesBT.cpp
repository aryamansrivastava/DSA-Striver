// Problem: Count total Nodes in a Complete Binary Tree

// Method 1: Brute Force Approach (i.e Using Inorder Traversal)

// Definition of Complete Binary Tree
// 1. All levels except the last one are completely filled
// 2. Last level nodes are as left as possible.

//            Tree
//              1
//          /     \
//         2       3
//       /  \     / 
//      4    5   6

// Total Nodes in a Complete Binary Tree: 6

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(log(n)) or O(h)
// Where h = height of tree

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

void inOrder(Node* root, int& count) {
    if (root == NULL) return;

    count++;
    inOrder(root->left, count);
    inOrder(root->right, count);
}

// Method 2: Optimization Approach (i.e Using Height of Complete Binary Tree)

// Time Complexity: O(log(n) * log(n))
// Reason: The calculation of leftHeight and rightHeight takes O(log N) time.
// In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).

// Space Complexity: O(log(n)) or O(h)
// Where h = height of tree

int findHeightLeft(Node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->left; 
    }
    return hght; 
}

int findHeightRight(Node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->right; 
    }
    return hght; 
}

int countNodes(Node* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1; // (1<<lh) is basically (2^h)
    
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    
    return 1 + leftNodes + rightNodes; 
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int count = 0;

    // For Brute Force
    // inOrder(root, count);

    // For Optimised Approach
    count = countNodes(root);

    cout << "The total number of nodes in the given complete binary tree are: " << count << endl;
    return 0;
}