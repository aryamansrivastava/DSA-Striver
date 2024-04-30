// Problem: LCA in Binary Search Tree

//          Tree
//           6
//       /      \
//      2        8
//    /  \     /  \ 
//   0    4   7   9
//       / \
//      3   5

// LCA(0, 5) = 2
// LCA(2, 5) = 2

// Recursive Approach
// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes

// Space Complexity: O(h)
// Reason: Auxiliary Stack space taken by Recursion
// Where h = height of BST

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

// using Recursive Approach

// In recursive algorithms like this, the value of root remains consistent 
// throughout the recursive calls. I overlooked the fact that root is passed 
// by value to each recursive call, and its value remains unchanged throughout the recursive process.

Node* lca(Node* root, int x, int y) {
    // If the root is null, or we've reached a leaf node, return null
    if(root == NULL) return NULL;

    // If both nodes lie on the right side of the current node
    if(root->data < x && root->data < y) {
        return lca(root->right, x, y);
    }

    // If both nodes lie on the left side of the current node
    if(root->data > x && root->data > y) {
        return lca(root->left, x, y);
    }
    
    // If the nodes are on different sides of the current node or one of the nodes is the current node itself
    return root;
}

// using Iterative Approach

// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Data Structure

// Node* lca(Node* root, int x, int y) {
//     Node* cur = root;
//     while(cur != NULL) {
//         if(cur->data < x && cur->data < y) cur = cur->right;
//         else if(cur->data > x && cur->data > y) cur = cur->left;
//         else break;
//     }
//     return cur;
// }

int main(){
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    int x = 0, y = 5;
    cout << "lca(" << x << ", "<< y << "): " << lca(root, x, y)->data << endl;
    return 0;
}