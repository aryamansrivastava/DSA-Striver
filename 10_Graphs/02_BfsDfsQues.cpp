


// // 733. Flood Fill Algorithm (Leetcode)

// class Solution {
// public:
//      void dfs(int row, int col, vector<vector<int>>&ans,
//      vector<vector<int>>& image, int color, int delRow[], int delCol[], int iniColor){
//         // color with new color
//         ans[row][col] = color;
//         //traverse for all its neighbours in all 4 directions
//         int n = image.size();
//         int m = image[0].size();
//         for(int i=0;i<4;i++){
//             int nrow = row + delRow[i];
//             int ncol = col + delCol[i];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
//             image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
//                 dfs(nrow, ncol, ans, image, color, delRow, delCol, iniColor);
//             }
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         //store the initial color of the starting cell
//         int iniColor = image[sr][sc];
//         // copy the image in ans as we have to flood fill it and retur it
//         vector<vector<int>> ans = image;
//         // as we have to check for adjacent neighbours in 4 directions
//         int delRow[] = {-1, 0, +1, 0};
//         int delCol[] = {0, +1, 0, -1};
//         dfs(sr, sc, ans, image, color, delRow, delCol, iniColor); 
//         return ans;    
//     }
// };


// // 994. Rotting Oranges (Leetcode/GFG)
// Tuf ka article is solution ko nhi samjha raha h sahi se

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {

//     int n = grid.size();
//     int m = grid[0].size();

//     queue<pair<pair<int, int>, int>> q;

//     // creating a visited grid
//     int vis[n][m];
//     int cntfresh = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             // if cell contains rotten orange
//             if (grid[i][j] == 2)
//             {
//                 q.push({{i, j}, 0});
//                 // mark as visited (rotten) in visited array
//                 vis[i][j] = 2;
//             }
//             // if not rotten
//             else
//             {
//                 vis[i][j] = 0;
//             }
//             if (grid[i][j] == 1)
//                 cntfresh++;
//         }
//     }

//     int time = 0;
//     int drow[] = {-1, 0, 1, 0};
//     int dcol[] = {0, 1, 0, -1};
//     int cnt = 0;

//     // bfs traversal (until the queue becomes empty)
//     while (!q.empty())
//     {
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int t = q.front().second;
//         time = max(time, t);
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];

//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
//             {
//                 // push in queue with timer increased
//                 q.push({{nrow, ncol}, t + 1});
//                 // mark as rotten
//                 vis[nrow][ncol] = 2;
//                 cnt++;
//             }
//         }
//     }
//     // if all oranges are not rotten
//     if (cnt != cntfresh){
//         return -1;
//     }
//      return time;
        
//     }
// };


// Detect a Cycle in an Undirected Graph using BFS and DFS from 
// TAKE YOU FORWARD SITE
