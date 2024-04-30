// Problem: Lowest Common Ancestor in Binary Tree

// Method 1: Brute Force Approach 
// (i.e By Finding the path of Both Nodes and then lca is last common node in the both the path)

// Definition of Lowest Common Ancestor(LCA):
// The Ancestor that exist at Deepest Level

// Note:
// A Node can be a Ancestor of itself.
// So, LCA(x, y) can be either x, y or Ancestor exist at Deepest Level


//      Tree
//         1
//     /      \
//    2        3
//   / \      / \
//  4   5    8   9
//     / \
//    6   7


// LCA(4, 7) = 2
// LCA(5, 9) = 1
// LCA(2, 6) = 2

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h) + O(2k)
// Reason: 
// O(h) for Auxiliary Stack space taken by Recursion, Where h = height of tree
// O(2k) for storing root to node Path of both Nodes

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

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

bool getPath(Node* root, int x, vector<int> &path) {
    if(root == NULL) return 0;

    path.push_back(root->data);

    if(root->data == x) return 1;

    if(getPath(root->left, x, path) || getPath(root->right, x, path)) {
        return 1;
    }

    path.pop_back();
    return 0;
}

// Method 2: Optimization Approach
// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h)
// Where h = height of tree

Node* lca(Node* root, int x, int y) {
    if(root == NULL || root->data == x || root->data == y) return root;

    Node* left = lca(root->left, x, y);
    Node* right = lca(root->right, x, y);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;  // Return the root if both left and right are not NULL
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    int x = 4, y = 7;

    // For Brute Force Approach
    // vector<int> path1, path2;
    // getPath(root, x, path1);
    // getPath(root, y, path2);

    // int lca;  // In leetcode we have to return node so there lca is treated as node
    // for (int i = 0; i < min(path1.size(), path2.size()); i++)
    // {
    //     if(path1[i] == path2[i]) lca = path1[i];
    //     else break;
    // }
    // cout << "lca(" << x << ", "<< y << "): " << lca << endl;

    // For Optimised Approach
    cout << "lca(" << x << ", "<< y << "): " << lca(root, x, y)->data << endl;
    return 0;
}