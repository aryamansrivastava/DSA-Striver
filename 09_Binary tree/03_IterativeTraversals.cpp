// Problem: Iterative Inorder, preorder and Postorder Traversal in Binary Tree

// Trick to Remember Inorder: Left Root Right
// Trick to Remember Preorder: Root Left Right
// Trick to Remember Postorder: Left Right Root

//       Tree
//        1
//      /  \
//     2    3
//   /  \
//  4    5
//     /  \
//    6    7

// Inorder: [4, 2, 6, 5, 7, 1, 3]
// Preorder: [1, 2, 3, 4, 5, 6, 7]
// Postorder: [4, 6, 7, 5, 2, 3, 1]

// Time Complexity of Inorder and preorder: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity of Inorder and preorder: O(h), where h = height of tree
// Reason: Space taken by user defined stack which store at most nodes equal to height of tree.

// Postorder using 1 Stack
// Time Complexity: O(2*n)
// Reason: O(n) for going into the depth i.e using Outer 'while' loop and O(n) while backtracking from stack 'st' i.e using Inner 'while' loop.

// Space Complexity: O(n)
// Reason: Space taken by stack to store all the nodes of tree.

// Postorder using 2 Stacks
// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(2*n)
// Reason: Space taken by stack 'st1' as O(n) and stack 'st2' as O(n) to store.

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

vector<int> iterativePreOrder(Node* root) {
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        preOrder.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return preOrder;
}

vector<int> iterativeInOrder(Node* root) {
    vector<int> inOrder;
    if(root == NULL) return inOrder;

    stack<Node *> st;
    while(1) {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            if(st.empty()) break;
            root = st.top();
            st.pop();
            inOrder.push_back(root->data);
            root = root->right;
        }
    }
    return inOrder;
}

// using 1 Stack
vector<int> iterativePostOrder(Node* root) {
    vector<int> postOrder;
    if(root == NULL) return postOrder;

    Node *cur = root, *temp;
    stack<Node *> st;
    while(cur != NULL or !st.empty()) {
        if(cur != NULL) {
            st.push(cur); 
            cur = cur->left;
        }
        else {
            temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty() and temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else {
                cur = temp;
            }
        }
    }
    return postOrder;
}

// Using 2 Stacks
// vector<int> iterativePostOrder(Node* root) {
//     vector<int> postOrder;
//     if(root == NULL) return postOrder;

//     stack<Node *> st1, st2;
//     st1.push(root);
//     while(st1.size()) {
//         root = st1.top();
//         st1.pop();
//         st2.push(root);
//         if(root->left != NULL) st1.push(root->left);
//         if(root->right != NULL) st1.push(root->right);
//     }

//     while(st2.size()) {
//         postOrder.push_back(st2.top()->data);
//         st2.pop();
//     }
//     return postOrder;
// }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    // PreOrder Traversal
    // vector<int> arr = iterativePreOrder(root);
    // cout<<"IterativePreOrder : [ ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"]"<<endl;

    // Inorder Traversal
    // vector<int> arr = iterativeInOrder(root);
    // cout<<"IterativeInOrder : [ ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"]"<<endl;

    // PostOrder Traversal
    vector<int> arr = iterativePostOrder(root);
    cout<<"IterativePostOrder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}