/* Recursion-->The process in which a function calls itself directly or indirectly is called recursion 
 and the corresponding function is called a Recursive function. 
 Using a recursive algorithm, certain problems can be solved quite easily.*/

// //Print counting code

// #include<iostream>
// using namespace std;

// void print(int n){
//     //base case
//     if(n==0){
//         return;
//     }
//  //for printing N to 1
//     cout << n << " ";
//     print(n-1);
//  //for printing 1 to n -> ye backtracking se hoga 
//     cout << n << " ";
// }

// int main(){
// int n;
// cin >> n;
// print(n);

// return 0;
// }

// //Sum of first N numbers using functional Recursion

// #include<iostream>
// using namespace std;

// int sum(int n){
//  //base case
//  //If the base case is not reached or not defined, then the stack overflow problem may arise.
//     if(n==0) return 0; 
//     return n + sum(n-1);
// }

// int main(){
//     int n;
//     cin >> n;
//     cout << sum(n) << endl;
//  return 0;
// }

// //Sum of first N numbers using Parameterised Recursion

// #include<bits/stdc++.h>
// using namespace std;

// void func(int i, int sum){ 
//    // Base Condition.
//    if(i<1)
//    {
//        cout<<sum<<endl;
//        return;
//    }
//   // Function call to increment sum by i till i decrements to 1.
//    func(i-1,sum+i);
// }

// int main(){
//   int n = 3;
//   func(n,0);
//   return 0;
// }

// //Factorial no code using Functional Recursion

// #include<iostream>
// using namespace std;

// int factorial(int n){
//  //base case
//     if(n==0){
//          return 1;
//     } 
//     return n*factorial(n-1);
// }

//   int main(){
//     int n;
//     cin >> n;
//     int ans= factorial(n);
//     cout << ans << endl;
//  return 0;
// }

// //Factoriral Code Using Parameterised Recursion

// #include<iostream>
// using namespace std;
// void factorial(int i,int fact){

//      if(i == 0) {
//         cout<<fact;
//         return;
//      }    
//      factorial(i-1,fact*i);
// }

// int main(){
//     int i = 4;
//     factorial(i,1);
// return 0;   
// }

// //Power of two code

// #include<iostream>
// using namespace std;

// int power(int n){
//     //base case
//     if(n==0){
//         return 1;      
//     }
//     //recursive relation
//     return 2*power(n-1);
// }

// int main(){
//     int n;
//     cin >> n;

//     int ans=power(n);
//     cout << ans << endl;

// return 0;
// }

// // Reverse an Array using Recursion

// #include<iostream>
// using namespace std;

// void f(int i,int arr[],int n){
//     //base case
//     if(i>=n/2){
//         return;
//     }
//     swap(arr[i],arr[n-i-1]);
//     f(i+1, arr, n);
// }

// int main(){
// int n;
// cin >> n;
// int arr[n];
// for(int i=0;i<n;i++) cin >> arr[i];
// f(0, arr, n);
// for(int i=0;i<n;i++) cout << arr[i] << " ";
// return 0;
// }

// // Check if a String is Palindrome or not
// #include<iostream>
// using namespace std;

// bool f(int i, string &s){
//     //base case
//     if(i>=s.size()/2){
//         return true;
//     }
//     if(s[i] != s[s.size()-i-1]) return false;
//     return f(i+1,s);
// }

// int main(){
// string s;
// cin >> s;
// cout << f(0,s);
// return 0;
// }

// // Fibonacci code (Multiple Recursion Calls hongi isme)

// // Time Complexity -> T(2^N)
// // Space Complexity -> O(N)

// #include<iostream>
// using namespace std;

// int fib(int n){
//     //base case
//     if(n<=1)  return n;
//     return fib(n-1)+fib(n-2); 
// }

// int main(){
// int n;
// cin >> n;

// cout << fib(n) << endl;
// return 0;
// }


// // Very Important

// // *****Print all Subsequences*****
// // Subsequences -> a contigous/non-contigous sequence which follows the order.

// // Time Complexity -> T(2^N * N)
// // Space Complexity -> O(N)

// #include<bits/stdc++.h>
// using namespace std;

// void printF(int ind, vector<int> &ds, int arr[], int n){
//     // base case
//     if(ind == n){
//         for(auto it: ds){
//             cout << it << " ";
//         }
//      // to print null
//         if(ds.size()==0){
//             cout << "{}" ;
//         }
//         cout << endl;
//         return;
//     }
//     // take or pick the particular index into the subsequence
//     ds.push_back(arr[ind]);
//     printF(ind+1, ds, arr,  n);
//     ds.pop_back();

//    // not pick, or not take condition, this element is not added to your subsequence
//     printF(ind+1, ds, arr, n);
// }

// int main(){
//     int arr[] = {3,1,2};
//     int n = 3;
//     vector<int> ds;
//     printF(0, ds, arr, n);
// }