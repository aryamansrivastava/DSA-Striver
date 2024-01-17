//    **** Selection Sort****

// unstable sort
// Time Complexity --> O(n^2)
// Space Complexity --> O(1)

// #include<iostream>
// using namespace std;

// int main () {
// cout << " Enter no of elements and elements : "<< endl;
//     int n ; cin >> n;
//     int arr[n];
//     for(int i = 0; i<n; i++) {
//         cin >> arr[i];
//     }

//   // less than (n-1) tak chalega bcoz arr[n-1]
//   //ke aage koi bhi min element nhi bachega
//     for( int i=0; i < n-1; i++) {
//         for (int j=i+1; j < n; j++) {
//             if(arr[j] < arr[i]) {
//                     swap(arr[j],arr[i]);

//                     // OR

//               /*      int temp = arr[j];
//                     arr[j] = arr[i];
//                     arr[i] = temp;   */
//                 }
//             }
//         }
//         //printing sorted Array
//         for(int i=0; i<n; i++) {
//             cout << arr[i]<< " ";
//         }
//          cout << endl;
//          return 0;
//     }