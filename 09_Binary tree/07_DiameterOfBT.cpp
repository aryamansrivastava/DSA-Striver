// Problem: Diameter of Binary Tree

// Method 1: Brute Force Approach

// Definition of Diameter of Binary Tree
// 1. Longest path between 2 nodes
// 2. In a Path Every node appears only once
// 3. Path may or may not pass from the root

//          Tree1
//            1
//          /  \
//         2    3
//       /  \
//      4    5

// Diameter of Tree1: 3

//          Tree2
//            1
//          /  \
//         2    3
//            /  \
//           4    6
//          /      \
//         5        7
//        /          \
//       9            8

// Diameter of Tree2: 6

// Time Complexity: O(n^2)
// Reason: As check() traverse all the nodes takes O(n) and For every node height() takes O(n). So it is O(n*n) ~ O(n^2)

// Space Complexity: O(2*h)
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

int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameter;

int findDiameter(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    diameter = max(diameter, leftHeight+rightHeight);
    findDiameter(root->left);
    findDiameter(root->right);
    return diameter;
}

// Method 2: Optimization Approach (i.e Optimizing Height function)
// Time Complexity: O(n)
// Reason: As height() using only O(n) i.e Traversing all the nodes

// Space Complexity: O(h)
// Where h = height of tree

// Approach 
// 1. In height() add parameter let say diameter as Pass by reference
// 2. Calculate leftHeight and rightHeight and set diameter = max(diameter, leftHeight+rightHeight)

int heightOptimised(Node* root, int& diameter) {
    if(root == NULL) return 0;

    int leftHeight = heightOptimised(root->left, diameter);
    int rightHeight = heightOptimised(root->right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);
    return 1 + max(leftHeight, rightHeight);
}


int main(){
    // Tree1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right= new Node(5);

    // Tree2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->right = new Node(6);
    root2->right->left->left = new Node(5);
    root2->right->left->left->left = new Node(9);
    root2->right->right->right = new Node(7);
    root2->right->right->right->right = new Node(8);

    diameter = 0;
    // For Bruteforce Approach
    // findDiameter(root1);
    // cout<<"Diameter of Tree1: "<<diameter<<endl;

    // diameter = 0;
    // findDiameter(root2);
    // cout<<"Diameter of Tree2: "<<diameter<<endl;

    // For Optimised Approach
    heightOptimised(root1, diameter);
    cout<<"Diameter of Tree1: "<<diameter<<endl;

    diameter = 0;
    heightOptimised(root2, diameter);
    cout<<"Diameter of Tree2: "<<diameter<<endl;
    return 0;
}