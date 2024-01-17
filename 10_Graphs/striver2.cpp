// Detect Cycle in an Undirected Graph using BFS

class Solution {
  private:
  bool detect(int src, vector<int> adj[], int vis[]){
      vis[src] = 1;
      queue<pair<int,int>> q;
      q.push({src, -1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjacentNode: adj[node]){
              if(!vis[adjacentNode]){
                  vis[adjacentNode] = 1;
                  q.push({adjacentNode, node});
              }
              else if(parent != adjacentNode){
                  return true;
              }
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i, adj, vis))  return true;
            }
        }
        return false;
    }
};

// Detect Cycle in an Undirected Graph using DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // Using DFS(DEPTH FIRST SEARCH)
  private:
  bool dfs(int node, int parent, int vis[], vector<int> adj[]){
      vis[node] = 1;
      for(auto adjacentNode: adj[node]){
          if(!vis[adjacentNode]){
              if(dfs(adjacentNode, node, vis, adj) == true)
              return true;
          }
          else if(adjacentNode != parent) return true;
      }
      return false;
  }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // for graph with connected components 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj) == true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends



// Distance of Nearest Cell having 1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    queue<pair<pair<int,int>, int>> q; 
	    
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 1
	            if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delRow[] = {-1,0,+1,0};
	    int delCol[] = {0,+1,0,-1};
	    
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dist[row][col] = steps;
	        // for all 4 neighbours
	        for(int i=0;i<4;i++){
	           int nrow = row + delRow[i];
	           int ncol = col + delCol[i];
	           if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	       }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends


//Bipartite Graph using BFS and DFS




// Detect Cycle in an Directed Graph using DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        //traverse for adjacent nodes
        for(auto it: adj[node]){
            // when the node is not visited
            if(!vis[it]){
               if(dfsCheck(it, adj, vis, pathVis) == true)
               return true;
            }
            // if the node has been previously visited 
            // but it has to be visited on the same path
            else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // if this yields a true that means there is a cycle
                if(dfsCheck(i, adj, vis, pathVis) == true)  return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends



// Topological sort using DFS

class Solution
{
    private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj) ;
            }
        }
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i, vis, st, adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};


// Kahn's Algorithm(Topological Sort Algorithm) using BFS

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Kahn's algorithm using updated version of BFS
	    
	    int inDegree[V] = {0};
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(inDegree[i] == 0){  
	        q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        // node is in your topo sort
	        // so remove it from the InDegree
	        
	        for(auto it: adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};


// Detect a Cycle in Directed Graph(Kahn's Alog)

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // kahn's algo code
        int inDegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        // if topoSize == V   -> means Directed Acyclic confirmed
        // if not -> means it has a cycle thus return true
        
        if(topo.size() == V) return false;
        else return true;
    }
};


// Eventual Safe States using BFS - Topological Sort

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int inDegree[V] = {0};
        for(int i=0;i<V;i++){
            // i -> it
            // it -> i
            // reversing the edges
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for(auto it: adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(safe.begin(),safe.end());
        return safe;
    }
};



// Shortest Path in Undirected Graph having Unit Distance

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto it: edges){
            // undirected graph ke liye
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int dist[N];
        // initializing the values of array with INT_MAX
        
        // fill_n(dist,N,INT_MAX);
        
              //OR
              
        for(int i=0;i<N;i++){
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i] != INT_MAX){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends



// Dijkstra's Algorithm using Priority Queue

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

// } Driver Code Ends



// Dijkstra's Algorithm using Sets

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //using Set
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);
        
        st.insert({0,S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if(dis + edgeWt < dist[adjNode]){
                    //erase if it existed
                    if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};



// Bellman Ford Algorithm(Distance of vertex from the source)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends



//Prim's Algorithm to find MST

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> vis(V,0);
        // {wt,node}
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            // add it to the MST
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]){
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
        
    }
};



// Disjoint Set CODE Snippet

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
    
    // now combined
    ds.unionBySize(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}


// Kruskal's Algorithm

// code nhi samajh aara bc

