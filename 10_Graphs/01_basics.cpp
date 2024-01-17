// // Graph Represenation in C++
// // Store -> Matrix and List way

// //Matrix way

// // Time Complexity -> O(n^2)
// // Space Complexity -> O(n^2)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // n -> nodes
    // m -> edges
	    ll n,m;
        cin >> n >> m;
        //graph here
        ll adj[n+1][m+1];
        for(int i=0;i<m;i++){
            ll u,v;    
            cin >>  u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
	}
	return 0;
 }

// // Adjacency List way

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // n -> nodes
    // m -> edges
	    ll n,m;
        cin >> n >> m;
        //graph here
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            ll u,v;    
            cin >>  u >> v;
            // for Undirected Graph
            // u --> v
            // v --> u
            // Time Complexity -> O(n+E)
            // Space Complexity -> O(2*E)
            adj[u].push_back(v);
            adj[v].push_back(u);

             // for Directed Graph
            // u --> v
            // Time Complexity -> O(n+2E)
            // Space Complexity -> O(E)
            //adj[u].push_back(v);
	}
	return 0;
 }


// //Breadth First Search(BFS) Code gfg

// // Time Complexity -> O(V+2E)
// // Space Complexity -> O(V)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // visited array initialized to 0
        int vis[V]={0};
        // starting node marked as 1
        vis[0]=1;
        queue<int> q;
        q.push(0);   //starting node 0 pushed into queue
        vector<int> bfs;
        while(!q.empty()){
            // get the topmost element in queue -> FIFO
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            //traverse for all its neighbours
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it); 
                }
            }
        }
        return bfs;
        
    }
};


// // Depth First Search(DFS) Code gfg

// // Time Complexity -> O(V+2E)
// // Space Complexity -> O(V)

class Solution {
  private:
  void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
      vis[node] = 1;
      ls.push_back(node);
      //traverse for all its neighbours
      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,ls);
          }
      }
  } 
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //code here
        int vis[V] = {0};
        int start = 0;
        // create a list to store dfs
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
};