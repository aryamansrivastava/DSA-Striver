// Graph Represenation in C++
// Store -> Matrix and List way

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // Graph is a finite set of vertices and edges
    // total degree of undirected graph=2*Total edges
    // for directed graph degree is represented in terms of indegree and outdegree
    // degree of a vertex is defined as the no of edges attached with it

    ll n,m;  // n -> nodes && m -> edges 
    cin >> n >> m;

    // for weighted graphs
    vector<vector<int>> adj(n+1,vector<int>(m+1,0)); // for matrix
    vector<pair<int,int>> adj_list[n + 1]; // for adjacency list
    for(int i=0;i<m;i++){
        ll u,v,wt;    
        cin >> u >> v >> wt;
        // Matrix way
        // Time Complexity -> O(n^2)
        // Space Complexity -> O(n^2)
        adj[u][v] = wt;
        adj[v][u] = wt; //remove this line for directed graph

        // Adjacency List Way

        // for Undirected Graph
        // u --> v
        // v --> u
        // Time Complexity -> O(n+2E)
        // Space Complexity -> O(2*E)
        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});

        // for Directed Graph
        // u --> v
        // Time Complexity -> O(n+E)
        // Space Complexity -> O(E)
        // adj_list[u].push_back({v,wt});
	}
    cout << "\nADJACENCY MATRIX REPRESENTATION : \n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n-------------------------------\n";

    cout << "\nADJACENCY LIST REPRESENTATION :\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout<<"("<<adj_list[i][j].first<<","<<adj_list[i][j].second<<")"<<" ";
        }
        cout << endl;
    }
    cout << endl;

	return 0;
 }