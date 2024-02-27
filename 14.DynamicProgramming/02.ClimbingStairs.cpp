
// Link: https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

// ** Understand A DP Problem **
// Count the total number of ways/ MAX or MIN Output


/* TIPS:
1. Try to represent the problem in terms of indices
2. Do all possible stuffs on that index according to the problem statement
3. If the question asks all the ways, sum up all the stuffs
   If the question asks for the minimum, take minimum of all the stuffs */

// to reach the nth stair, you find out the ways to reach the (n-1)th stair (from where you take 1 step to reach nth stair) 
// and the ways to reach the (n-2)th stair (from where you take 2 steps to reach the nth stair), and sum them to get total no. of ways

int solveR(int n) {
    if(n<=2) { 
        return n;
    }
    return solveR(n-1) + solveR(n-2);
}

// Approach: Memoization
// Time Complexity: O(n)
// Reason: Storing results in Dp Array 
// Space Complexity: O(n)
// Reason: Auxiliary Stack Space O(n) + Dp Array O(n)

int solveM(int n, vector<int> &dp) {
    if(n<=2) {
        return n;
    }
    if(dp[n]!= -1) {
        return dp[n];
    }
    return dp[n] = solveM(n-1,dp) + solveM(n-2,dp);
}


// Approach: Tabulation
// Time Complexity: O(n) & Space Complexity: O(n)
// Reason: Dp Array O(n)

int solveT(int n) {
    vector<int> t(n+1);  
    if(n<=2) {
        return n;
    }
    t[1] = 1;
    t[2] = 2;
    for(int i=3; i<=n; i++) {
        t[i] = t[i-1] + t[i-2];
    }
    return t[n];
}

// Approach: Space Optimized
// Time Complexity: O(n)
// Reason: Using variables to store previous 2 states 
// Space Complexity: O(1)


int solveS(int n) {
    if(n<=2) {
        return n;
    }
    int prev2 = 1;
    int prev = 2;
    for(int i=3; i<=n; i++) {
        int curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n = 45;
    vector<int> dp(n+1, -1); // For Memoization

    cout << solveR(10) << "\n";
    cout << solveM(n, dp) << "\n";
    cout << solveT(n) << "\n";
    cout << solveS(n) << "\n";

    return 0;
}