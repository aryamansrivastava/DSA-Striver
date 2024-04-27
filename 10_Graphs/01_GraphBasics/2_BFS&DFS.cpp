// // Traversal Techniques -> BFS & DFS
// // Breadth First Search (BFS) Code gfg

// // Time Complexity -> O(V+2E)
// // Space Complexity -> O(3V) -> O(V) approx


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     public:
//     // Function to return Breadth First Traversal of given graph.
//     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
//         // visited array initialized to 0
//         int vis[V]={0};
//         // starting node marked as 1
//         vis[0]=1;
//         // Queue follows FIFO, and will always contain the starting.
//         queue<int> q;
//         q.push(0); //starting node 0 pushed into queue

//         vector<int> bfs;
//         while(!q.empty()){
//             // get the topmost element in queue -> FIFO
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);
//             //traverse for all its neighbours
//             for(auto it: adj[node]){
//                 if(!vis[it]){
//                     vis[it] = 1;
//                     q.push(it); 
//                 }
//             }
//         }
//         return bfs;
//     }
// };

// void addEdge(vector <int> adj[], int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printAns(vector <int> &ans) {
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
// }

// int main() 
// {
//     vector <int> adj[6];
    
//     addEdge(adj, 0, 1);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 1, 3);
//     addEdge(adj, 0, 4);

//     Solution obj;
//     vector <int> ans = obj.bfsOfGraph(5, adj);
//     printAns(ans);

//     return 0;
// }


// // Depth First Search(DFS) Code gfg

// // Time Complexity -> O(V+2E)
// // Space Complexity -> O(3V) -> O(V) approx

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     private: 
//       void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
//       vis[node] = 1;
//       ls.push_back(node);
//       //traverse for all its neighbours
//       for(auto it: adj[node]){
//         //if the neighbour is not visited, call the recursive dfs func
//           if(!vis[it]){
//               dfs(it,adj,vis,ls);
//           }
//       }
//   } 
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//     int vis[V] = {0};
//     int start = 0; // the graph having starting node as 0
//     // create a list to store dfs
//     vector<int> ls;
//     dfs(start,adj,vis,ls);
//     return ls;
//     }
// };

// void addEdge(vector <int> adj[], int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printAns(vector <int> &ans) {
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//     }
// }

// int main() 
// {
//     vector <int> adj[5];
    
//     addEdge(adj, 0, 2);
//     addEdge(adj, 2, 4);
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 3);

//     Solution obj;
//     vector <int> ans = obj.dfsOfGraph(5, adj);
//     printAns(ans);

//     return 0;
// }