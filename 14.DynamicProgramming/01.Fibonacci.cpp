// Link: https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

//Step 1
//brute force - Recursion approach - O(2^n) & O(n)
int fib(int n){
	if (n <= 1){
		return n;
	}

	return fib(n-1) + fib(n-2);
}

int main(){
	int n = 6;
	cout<<fib(n);
}


//------------------------------------------------------------------------------------------------------->

//Step 2
//Memoization Approach -> TC and SC => O(n) & O(2*n) -> problem is solved in the direction of the main problem to the base cases.

int fib(int n, vector<int>&dp){
    //base case
	if (n <= 1){
		return n;
	}
    //memoization condition
	if (dp[n] != -1){
		return dp[n];
	}
	return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main(){
	int n = 10;
	vector<int>dp(n+1, -1);
	cout<<fib(n, dp);
}


//-------------------------------------------------------------------------------------------------------->

//Step 3
//Tabulation Approach - O(n) & O(n) -> Base case to main problem

int fib(int n, vector<int>&dp){
	
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i){ 
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){
	int n = 10;
	vector<int>dp(n+1, -1);
	cout<<fib(n, dp);
}


//-------------------------------------------------------------------------

//Step 4
//Space Optimized - O(n) & O(1)


int fib(int n){
	
	int prev2 = 0;
	int prev = 1;

	for (int i = 2; i <= n; ++i){
		int curr = prev2 + prev;
		prev2 = prev;
		prev = curr;
	}

	return prev;
}

int main(){
	int n = 6;
	cout<<fib(n);
}