// Problem: Bottom View of Binary Tree


//        Tree
//           1
//       /      \
//      2        3
//    /  \     /  \ 
//   4    5   6    7
//       / \
//      8   9

// BottomView: [4, 8, 6, 9, 7]

// Time Complexity: O(n*log(n))
// Reason: As we traverse all the node of tree it takes O(n) and With in it we are using map ds[x] i.e updating value which takes O(log(n))

// Space Complexity: O(2*n)
// Reason: In Worst Case O(n) for map 'ds' and O(n) for queue 'q'

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

// Approach:
// We assign a Vertical Line Number to Every Node; Like node(line) where line = vertical line number
// 1. For root of Tree; root(line) = (0)
// 2. For left child of any node; leftChild(line) = parentNode(line-1)
// 3. For right child of any node; rightChild(line) = parentNode(line+1)

// We can Assign this above coordinates using Levelorder traversal.

// Example

//        Tree
//           1
//       /      \
//      2        3
//    /  \     /  \ 
//   4    5   6    7
//       / \
//      8   9

//                 Coordinates
//                 1(0)
//              /       \
//          2(-1)       3(1)
//        /     \       /   \ 
//    4(-2)     5(0)  6(0)    7(2)
//             /   \
//          8(-1)  9(1)


vector<int> bottomView(Node *root) {
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mp[line] = node->data;
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> ans = bottomView(root);
    cout<<"BottomView : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}