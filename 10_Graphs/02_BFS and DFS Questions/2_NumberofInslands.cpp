// 200. Number of Islands (Leetcode)

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    // in the visited grid, cell is marked as visited(1)
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

    // 4 dimensional hai (only horizontally or vertically ) -> diagnally nhi allowed hai 
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,-1,0,1};
        //traverse in the neighbours and marked them if it's a land
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
            {
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
      }

        // if 8 dimensional ho -> diagnally bhi land search karna allowed ho to(GFG wala code)
        //traverse in the neighbours and marked them if it's a land
        // for(int deltarow = -1;deltarow <= 1; deltarow++){
        //     for(int deltacol = -1; deltacol <= 1; deltacol++){
        //         int nrow = row + deltarow;
        //         int ncol = col + deltacol;
        //         if((abs(deltarow-deltacol)==1) && nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
        //             // if all the conditions are satisfied,then mark newrow/newcol as visited
        //             vis[nrow][ncol]=1;
        //             q.push({nrow,ncol});
        //         }
        //     }
        // }

    }
  }

public:
    int numIslands(vector<vector<char>>& grid) {
        // n -> row
        // m -> column 
        int n = grid.size();
        int m = grid[0].size();

        //visited create in the form of grid all the blocks are intitially marked 0
        vector<vector<int>> vis(n,vector<int>(m,0));
        int island = 0;
        for(int row = 0; row < n;row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    island++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return island;
    }
};

int main() {
    vector<vector<char>> grid {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Output: 2
    Solution ob;
    cout << ob.numIslands(grid) << endl;
    return 0;
}