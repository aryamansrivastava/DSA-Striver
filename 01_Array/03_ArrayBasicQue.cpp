// MAX MIN element in an array

// #include <bits/stdc++.h>
// using namespace std;

// int getMax(int num[],int n){

//     int max = INT_MIN;

//     for(int i = 0; i<n; i++){
//         if(num[i] > max){
//             max = num[i];
//         }
//     }//returning max value
//     return max;
// }

// int getMin(int num[],int n){

//     int mini = INT_MAX;

//     for(int i = 0; i<n; i++){

//         mini = min(mini, num[i]);

//             OR

//         if(num[i] < min){
//             min = num[i];
//         }
//     }
//     //returning min value
//     return mini;
// }
// int main()
// {
//     int size;
//     cout << "enter size of array "<<endl;
//     cin >> size;
//     int num[100]; //-->int num[size] not good practice
    
//     //taking input of elements in array
//     cout << "enter elements of array "<<endl;
//     for(int i=0; i<size; i++){
//         cin >> num[i];
//     }
//     cout << "Maximum value is "<< getMax(num,size)<<endl;
//     cout << "Minimum value is "<< getMin(num,size)<<endl;
//     return 0;
// }

// REVERSE AN ARRAY

// #include<iostream>
// using namespace std;

// void reverse(int arr[], int n){
//    int start = 0;
//    int end = n-1;

//    while(start<=end){
//       swap(arr[start],arr[end]);
//       start++;
//       end--;
//    }
// }

// void printArray(int arr[],int n){

//    for(int i=0; i < n; i++){
//       cout << arr[i] << " ";
//    }
//    cout << endl;
// }

// int main(){

// int arr[6] = {1,4,2,8,5,-3};
// int brr[5] = {41,5,7,1,9};

// reverse(arr,6);
// reverse(brr,5);

// printArray(arr,6);
// printArray(brr,5);

// return 0;
// }

//   Swap Alternate elements in array

// #include<iostream>
// using namespace std;

// void printArray(int arr[], int n) {

//      for (int i=0; i<n; i++){
//       cout << arr[i] <<" ";
//      } cout << endl;
// }
// void swapAlternate(int arr[], int size) {
//   for(int i=0; i<size; i+=2 ){
//     if (i+1 < size) {
//       swap(arr[i], arr[i+1]);   OR   // temp = arr[1]
// arr[1] = arr[0]
// arr[0] = temp
//     }
//   }
// }

// int main(){

// int evenarr[6]={4,8,1,23,9,17};
// int oddarr[5]= {3,6,12,98,5};

// swapAlternate(evenarr,6) ;
// printArray(evenarr,6) ;

// cout << endl;

// swapAlternate(oddarr,5) ;
// printArray(oddarr,5) ;

// return 0;
// }