#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<int>> dp;

// Recursive DP
int gridPath(int i,int j, vector<string> &grid){
    //base case
    int n = grid.size();
    if(i >= n || j >= n) return 0;

    if(grid[i][j] == '*') return 0;

    // if(grid[0][0] == '*') return 0;

    if(i == n-1 && j == n-1) return 1;

    // dp[i][j] => number of ways to reach coordinate (i,j)

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int op1 = gridPath(i,j+1,grid);
    int op2 = gridPath(i+1,j,grid);

    return (dp[i][j] = (op1 + op2) % mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
    cin >> n;
    dp.resize(n,vector<int>(n,-1));
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }
    cout << gridPath(0,0,grid);
        
	return 0;
}
