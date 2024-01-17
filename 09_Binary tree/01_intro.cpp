#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
       int data;
       node* left;
       node* right;

    node(int d) {   // constructor
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;     
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
     queue<node*> q;
     q.push(root);
     q.push(NULL);  //seperator

     while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){  // queue still has some child nodes
                q.push(NULL);  //seperator
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
               q.push(temp -> left);
           }

           if(temp -> right) {
               q.push(temp -> right);
          }
       }
    }
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
/*
    buildFromLevelOrder(root);
    cout << endl;
    levelOrderTraversal(root);
*/

/*
    //creating a tree
    root = buildTree(root);

    //Tree data
    //  INPUT ---> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
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