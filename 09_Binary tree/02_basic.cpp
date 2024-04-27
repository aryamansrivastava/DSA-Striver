#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
       int data;
       node* left;
       node* right;

    node(int val) {   // constructor
        data = val;
        left = NULL;
        right = NULL;     
    }
};

node* buildTree(node* root){

    cout << "Enter the data : " << endl; 
    int data;
    cin >> data;
    root = new node(data);
    
    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right =  buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root){
    
    // Striver's approach
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* nod=q.front();
            q.pop();
            if(nod->left != NULL) q.push(nod->left);
            if(nod->right != NULL) q.push(nod->right);
            cout << nod->data << " "; // print the node data
        }
        cout << endl; // Move to the next level after printing all nodes of the current level
    }

    // Codehelp's approach

    // queue<node*> q;
    // q.push(root);
    // q.push(NULL);  //seperator

    // while(!q.empty()){
    // node* temp = q.front();
    // q.pop();

    // if(temp == NULL) { //purana level complete traverse ho chuka hai
    //     cout << endl;
    //     if(!q.empty()){  // queue still has some child nodes
    //         q.push(NULL);  //seperator
    //     }
    // }
    // else{
    //     cout << temp -> data << " ";
    //     if(temp -> left){
    //         q.push(temp -> left);
    //     }

    //     if(temp -> right) {
    //         q.push(temp -> right);
    //     }
    // }
    // }
}

void InOrder(node* root){
    // base case
    if(root == NULL) {
        return;
    }
    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}

void PreOrder(node* root){
    // base case
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

void PostOrder(node* root){
    // base case
    if(root == NULL) {
        return;
    }
    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter the data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }  
 
        cout << "Enter right node for: " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        } 
    }
}

int main(){

    node* root = NULL;
 
    // Creating a tree
    // Method 1
    // 1
    // 3 5
    // 7 11 17
    // buildFromLevelOrder(root);
    // cout << endl;
    cout << "printing the Level Order Traversal:" << endl;
    // levelOrderTraversal(root);

    // Method 2
    root = buildTree(root);
    cout << "printing the Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    // Tree data
    //      Tree
    //       1
    //     /    \
    //    3      9
    //   / \    / \
    //  4  5   6   7

    // INPUT ---> 1 3 4 -1 -1 5 -1 -1 9 6 -1 -1 7 -1 -1 

    // printing the level order -> OUTPUT
        // 1
        // 3 9
        // 4 5 6 7

/*
    // Traversals for BT
    // level order
    cout << "Printing the Level order Traversal output " << endl;
    levelOrderTraversal(root);

    // Inorder Traversal
    cout << "Inorder Traversal is : " ;
    InOrder(root);
    cout << endl;

    // Preorder Traversal
    cout << "Preorder Traversal is : " ;
    PreOrder(root);
    cout << endl;

    // Postorder Traversal
    cout << endl << "Postorder Traversal is : ";
    PostOrder(root);
*/
return 0;
}


// Count Leaf Nodes Question

/*
    Following is the Binary Tree Node class structure:
    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
*/

// void inorder(BinaryTreeNode<int> * root, int &count) {
//     //base case
//     if(root == NULL) {
//         return ;
//     }

//     inorder(root->left, count);

//     //leaf node
//     if(root->left == NULL && root->right == NULL) {
//         count++;
//     }

//     inorder(root->right, count);

// }

// int noOfLeafNodes(BinaryTreeNode<int> *root){
// int cnt = 0;
// inorder(root, cnt);
// return cnt;
// }
