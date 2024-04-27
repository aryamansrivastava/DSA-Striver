// 994. Rotting Oranges (Leetcode/GFG)
// Tuf ka article is solution ko nhi samjha raha h sahi se

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
                fresh++;
            }
        }
        int time = 0;
        int cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int i = 0;i<4;i++){
                    int nrow = row+drow[i];
                    int ncol = col + dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                        cnt++;
                    }
                }
        }
        // if all oranges are not rotten
     if (cnt != fresh){
         return -1;
     }
     return time;
        
    }
};