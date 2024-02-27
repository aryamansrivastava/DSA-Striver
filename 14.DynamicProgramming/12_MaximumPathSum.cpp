
// Problem: Minimum Path Sum in the Matrix
// Link: https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
using namespace std;

// Approach: Recursive
// Time Complexity: O(3^(m*n))
// Reason: Performing up, diagonally left and right at every cell
// Space Complexity: O(Length of the longest path with maximum sum)
// Reason: That many calls will be made
int solveR(int x, int y, vector<vector<int>> &m) {
    if(y<0 or y>=m[x].size()) {
        return 1e9;
    }
    if(x==0) {
        return m[x][y];
    }
    int up = solveR(x-1, y, m);
    int dl = solveR(x-1, y-1, m);
    int dr = solveR(x-1, y+1, m);
    return m[x][y] + min(up, min(dl, dr));
}

// Approach: Memoization
// Time Complexity: O(m*n)
// Reason: One time computation only, after that value is being reused
// Space Complexity: O(Length of the longest path with maximum sum)
// Reason: That many calls will be made
int solveM(int x, int y, vector<vector<int>> &m, vector<vector<int>> &dp) {
    if(y<0 or y>=m[x].size()) {
        return 1e9;
    }
    if(x==0) {
        return m[x][y];
    }
    if(dp[x][y]!=-1) {
        return dp[x][y];
    }
    int up = solveM(x-1, y, m, dp);
    int dl = solveM(x-1, y-1, m, dp);
    int dr = solveM(x-1, y+1, m, dp);
    return dp[x][y] = m[x][y] + min(up, min(dl, dr));
}

// Approach: Tabulation
// Time Complexity: O(m*n)
// Reason: Taking up value from the previous state, two loops
// Space Complexity: O(m*n)
// Reason: Dp array O(m*n)
int solveT(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[m-1].size();
    vector<vector<int>> dp(m, vector<int> (n));
    for(int j=0; j<n; j++) {
        dp[0][j] = matrix[0][j];
    }
    for(int x=1; x<m; x++) {
        for(int y=0; y<n; y++) {
        int up = dp[x-1][y] + matrix[x][y];
            int dg1 = matrix[x][y];
            if(y-1>=0) {
                dg1+=dp[x-1][y-1];
            }
            else{
                dg1+=1e9;
            }
            int dg2 = matrix[x][y];
            if(y+1<m) {  
                dg2+=dp[x-1][y+1];
            }
            else{
                dg2+=1e9;
            }
            dp[x][y] = min(up,min(dg1,dg2));
        }
    }
    return *min_element(dp[m-1].begin(), dp[m-1].end());
}

// Approach: Space Optimized
// Time Complexity: O(m*n)
// Reason: Taking up value from the previous state, two loops
// Space Complexity: O(n)
// Reason: Using row size vector to store the states
int solveS(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[m-1].size();
    vector<int> prev(n);
    for(int j=0; j<n; j++) {
        prev[j] = matrix[0][j];
    }
    for(int x=1; x<m; x++) {
        vector<int> curr(n);
        for(int y=0; y<n; y++) {
            int up = INT_MAX;
            int dl = INT_MAX;
            int dr = INT_MAX;
            up = prev[y];
            if(y>0) {
                dl = prev[y-1];                
            }
            if(y<n-1) {
                dr = prev[y+1];
            }
            curr[y] = matrix[x][y] + min(up, min(dl, dr));
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}

int main() {
    vector<vector<int>> matrix {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (n, -1)); // For Memoization
    
    int res = INT_MAX;
    for(int j=0; j<n; j++) {
        res = max(res, solveR(m-1, j, matrix));
    }
    cout << res << "\n";
    res = INT_MAX;
    for(int j=0; j<n; j++) {
        res = max(res, solveM(m-1, j, matrix, dp));
    }
    cout << res << "\n";
    res = INT_MAX;
    cout << solveT(matrix) << "\n";
    cout << solveS(matrix);
    
    return 0;
}