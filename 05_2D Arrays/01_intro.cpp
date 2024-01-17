// #include<iostream>
// #include <climits>
// using namespace std;

// // Linear Search ka function h ye
// // Time Complexity --> O(row*col)
// bool isPresent(int arr[][4],int target,int row,int col) {   //column no likhna zaroori hai
// for(int row=0; row<3; row++) {
//     for(int col=0; col<4; col++) {
//        if(arr[row][col] == target) {
//         return 1;
//           }
//        }
//      }
//   return 0;
// }

// //to print row wise sum -->function h ye
// void printSum(int arr[][4], int row, int col) {
//   cout << "prining Row wise sum " << endl;
//   for(int row=0; row<3; row++) {
//      int sum = 0;
//     for(int col=0; col<4; col++) {
//         sum += arr[row][col];
//     }
//        cout << sum << " ";
//   }
//   cout << endl;
// }

// //Largest Row sum function
// int largestRowSum(int arr[][4],int row, int col) {

//     int maxi = INT_MIN;
//     int rowIndex = -1;

//     for(int row=0; row<3; row++) {
//      int sum = 0;
//     for(int col=0; col<4; col++) {
//         sum += arr[row][col];
//     }
//     if(sum > maxi ) {
//         maxi = sum;
//         rowIndex = row;
//     }
//   }
//   cout << "the maximum sum is " << maxi << endl;
//   return rowIndex;
// }

//  int main(){

// //  Create 2D Array
// // int arr [3][4];

// // ****Initiliazing 2D Array --> Row wise
// // int arr[3][4] = {1,5,9,12,15,69,11,19,23,86,-12,45};
// // int arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

// cout <<"Enter the elements "<< endl;
// //taking input -> row wise input
// for(int row=0; row<3; row++) {
//     for(int col=0; col<4; col++) {
//         cin >> arr[row][col];
//     }
// }

//   //  OR

// // //taking input -> column wise input
// //  for(int col=0; col<4; col++) {
// //     for(int row=0; row<3; row++) {
// //         cin >> arr[row][col];
// //     }
// // }

// //  print
// cout <<"Printing the Array "<<endl;
// for(int row =0; row<3; row++) {
//     for(int col=0; col<4; col++) {
//         cout << arr[row][col] << " ";
//      }
//     cout << endl;
//    }

// //Searching an element in 2D array
// cout << "Enter the element to search " << endl;
// int target;
// cin >> target;

// if(isPresent(arr,target,3,4)) {
//     cout << "Element found " << endl;
// }
// else {
//     cout << "Not found " << endl ;
// }

// //row wise print sum --> function call
// printSum(arr,3,4);

// //largest row sum --> function call
// int ansIndex = largestRowSum(arr,3,4);
// cout <<"Max row is at Index " << ansIndex;

// return 0;
// }