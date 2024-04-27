// Problem: Print Root to Node Path in Binary Tree

//      Tree
//       1
//     /  \
//    2    3
//   / \
//  4  5
//    / \
//   6   7

// Path to Node 7 : [1, 2, 5, 7]

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h)
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

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

// Striver's Approach

bool getPath(Node* root, int x, vector<int> &path) {
    if(!root) return false;

    path.push_back(root->data);

    if(root->data == x) return true;

    // Recursively search for the target value
    // 'x' in the left and right subtrees
    // if any of this root->left or root->right gives true call function and put node in path
    if(getPath(root->left, x, path) || getPath(root->right, x, path)) {
        return true;
    }
    // If the target value 'x' is not found
    // in the current path, backtrack and pop from path
    path.pop_back();
    return false;
}

// My Approach

// bool getPath(Node* root, int x, vector<int> &path) {
//     if(root == NULL) return 0;

//     if(root->data == x) {
//         path.push_back(root->data);
//         return 1;
//     }
//     bool left = getPath(root->left, x, path);
//     bool right = getPath(root->right, x, path);

//     if(left || right) {
//         path.push_back(root->data);
//         return 1;
//     }
//     return 0;
// }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    int x = 7;
    vector<int> path;
    if(getPath(root, x, path)) {
        // Uncomment below line if using My Approach
        // reverse(path.begin(), path.end());
        cout<<"Path to "<<x<<" : [ ";
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"]"<<endl;
    }
    else cout<<"Node "<<x<<" don't exist in Tree"<<endl;
    return 0;
}