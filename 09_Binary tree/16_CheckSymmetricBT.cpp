// Problem: Bottom View of Binary Tree

//   Tree1 (Symmetrical)
//           1
//       /      \
//      2        2
//    /  \     /  \ 
//   3    4   4    3

// Tree2 (Non Symmetrical)
//          1
//       /    \
//      2      2
//       \      \
//        3      3

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(h)
// Where h is height of Binary Tree

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

bool isSymmetricCheck(Node* node1, Node* node2){
    if(node1==NULL && node2 == NULL)  return true;
    else if(node1 == NULL || node2 == NULL) return false;
    else if(node1->data != node2->data) return false;

    return isSymmetricCheck(node1->left,node2->right) && isSymmetricCheck(node1->right,node2->left);
}

bool isSymmetrical(Node* root) {
    if(root == NULL) return true;
    // Call the function
    // to check symmetry of subtrees
    return isSymmetricCheck(root->left, root->right);    
}

int main(){
    // Tree1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right= new Node(4);
    root1->right->left = new Node(4);
    root1->right->right= new Node(3);

    // Tree2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(2);
    root2->left->right= new Node(3);
    root2->right->right = new Node(3);

    if(isSymmetrical(root1)) cout<<"Tree1 is Symmetrical Binary Tree"<<endl;
    else cout<<"Tree1 is Not a Symmetrical Binary Tree"<<endl;

    if(isSymmetrical(root2)) cout<<"Tree2 is Symmetrical Binary Tree"<<endl;
    else cout<<"Tree2 is Not a Symmetrical Binary Tree"<<endl;

    return 0;
}