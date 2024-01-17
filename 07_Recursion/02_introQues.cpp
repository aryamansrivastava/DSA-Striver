// //Climb Stairs code(codestudio)

// #include <bits/stdc++.h>
// int countDistinctWays(int nStairs) {
//     //base case
//     if(nStairs<0){
//         return 0;
//     }
//     if(nStairs==0){
//         return 1;
//     }
//     //Recursive call
//     int ans=countDistinctWayToClimbStair(nStairs-1)
//     +countDistinctWayToClimbStair(nStairs-2);
//     return ans;
// }

// // Say Digits

// #include<iostream>
// using namespace std;

// void sayDigit(int n,string arr[]){
//     //base case
//     if(n==0)
//     return;

//     //processing
//     int digit=n%10;
//     n=n/10;

//     //recursive call
//     sayDigit(n,arr);
//     cout << arr[digit] << " ";
// }
// int main(){
//     string arr[10]={"zero","one","two","three","four","five",
//     "six","seven","eight","nine"};

// int n;
// cin >> n;

// sayDigit(n,arr);

// return 0;
// } 