// Problem: Check if a tree is a BST or BT Or Validate a BST

//               BST
//               13 
//            /        \
//         10           15
//      /     \      /    \
//     7      12    14    17
//      \                /
//      9              16
//     /
//    8

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(h), where h = height of tree
// Reason: Space taken by user defined stack which store at most nodes equal to height of tree.

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

// Striver code
// bool isValidBST(Node* root, int minVal, int maxVal) {
//     // Base Case
//     if(root == NULL) return 1;
 
//     // Recursive Case
//     if(root->data <= minVal || root->data >= maxVal) return 0;
//     return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
// }

// My code
bool isValidBST(Node* root, int minVal, int maxVal) {
    // Base Case
    if(root == NULL) return true;

    // Recursive Case
    bool inRange = (minVal < root->data && root->data < maxVal);
    if(inRange == false) return false;
    bool l = isValidBST(root->left, minVal, root->data);
    if(l == false) return false;
    bool r = isValidBST(root->right, root->data, maxVal);
    if(r == false) return false;
    return true;  // return true when both l and r return true
}

int main(){
    Node* root = new Node(13);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(14);
    root->right->right = new Node(17);
    root->left->left->right = new Node(9);
    root->right->right->left = new Node(16);
    root->left->left->right->left = new Node(8);

    cout << "Given BT is " << (isValidBST(root, INT_MIN, INT_MAX) ? "" : "not ") << "a BST " << endl;
    return 0;
}