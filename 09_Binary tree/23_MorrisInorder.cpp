// Morris Traversal is an efficient method for performing an traversal of a 
// binary tree without using recursion or an explicit stack. It achieves this 
// by modifying the tree structure temporarily.


// In-order Morris Traversal:
// 1.Base Case: If the left child is null, print the current node, then move to the right child.
// 2.Creating Thread: Before moving left, make the rightmost node of the left subtree point to the current node, then move to the left child.
// 3.Removing Thread: If the thread is already pointed to the current node, then remove the thread and print the current node, then move to the right child.

// Problem: Morris Traversal Inorder

#include<bits/stdc++.h>
using namespace std;

//           Tree
//             1
//          /    \
//         2      3
//       /  \
//      4    5
//            \
//             6

// Trick to Remember Inorder: Left Root Right

// Inorder: [4, 2, 5, 6, 1, 3]

// Time Complexity: O(3n) = O(n)

// Space Complexity: O(1)
// Reason: As we are using Threaded Binary Tree. So we are not using any Auxiliary Stack Space

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

vector<int> inOrder(Node* root) {
    vector<int> inorder;

    Node* cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            Node* temp = cur->left;
            while(temp->right && temp->right != cur) {
                temp = temp->right;
            }

            if(temp->right == NULL) {
                temp->right = cur;
                cur = cur->left;
            }
            else {
                temp->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return inorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> arr = inOrder(root);
    cout<<"Inorder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}