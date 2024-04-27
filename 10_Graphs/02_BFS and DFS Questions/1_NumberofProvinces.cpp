// 547. Number of Provinces (Leetcode)

// Time Complexity: O(V + 2E)
// Reason: Time complexity of dfs traversal of undirected graph

// Space Complexity: O(3V) ~ O(V), Space for queue data structure visited array and an adjacency list.
// Reason: Space taken 'vis' vector.

// Notes:
// 1. This problem can be solved using both DFS and BFS.
// 2. In this code we used DFS.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
private: 
    // DFS traversal function 
    void dfs(int node,vector<int> adj[], vector<int> &vis){
        // mark node as visited
        vis[node] = 1;
        //traverse for its neighbours
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis); 
            }
        }
    }
    //BFS traversal function
    void bfs(int node, vector<int>adj[], vector<int> &vis){
        queue<int>q;
        q.push(node);
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
    }
public:
    int numProvinces(vector<vector<int>>& isConnected) {
        // number of nodes
        int V = isConnected.size();
        //create an adjacency list
        vector<int> adj[V]; 
        // visited vector initialized to 0
        vector<int> vis(V,0);
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        // // For DFS
        // for(int i=0;i<V;i++){
        //    // if node is not visited , call the dfs function for it 
        //    // and increase province
        //    if(!vis[i]){
        //        provinces++;
        //        dfs(i,adj,vis);
        //    }
        // }

        // For Bfs
        for(int i=0;i<V;i++){
            if(!vis[i]){
                provinces++;
                bfs(i,adj,vis);
            }
        }

        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Output: 2
    Solution ob;
    cout << ob.numProvinces(isConnected) << endl;
    return 0;
}