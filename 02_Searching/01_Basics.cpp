//   *****LINEAR SEARCH****

// Time Complexity --> O(n)
//  #include<iostream>
//  using namespace std;

//  bool search(int arr[], int size, int key){
//     for(int i = 0; i< size; i++){

//         if( arr[i] == key) {
//             return 1;
//         }
//     }
//     return 0;
//  }
 
//  int main(){
 
//  int arr[10] = {5,7,-2,10,15,19,4,22,16,32};

//  cout << "Enter the element to search for " << endl;
//  int key;
//  cin >> key;

// bool found = search(arr, 10, key);
// if( found) {
//     cout << "Key is present "<< endl;
// } else {
//     cout << "Key is absent "<< endl;
// }
//  return 0;
//  }

//      **** BINARY SEARCH****

// Time Complexity --> O(log 2 n)

// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int size, int key)
// {
//     int start = 0;
//     int end = size - 1;

//     int mid = start + (end-start) / 2;

//     while (start <= end)
//     {
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         // go to right part
//         if (key > arr[mid])
//         {
//             start = mid + 1;
//         }
//         else
//         //go to left part
//         {
//             end = mid - 1;
//         }
//       mid = start + (end-start) / 2;
//     }
//     return -1;
// }
//     int main()
//     {

//         int evenarr[6] = {-2, 4, 5, 8, 15, 25};
//         int oddarr[5] = {7, 9, 13, 19, 22};

//         int index1 = binarySearch(evenarr, 6, 15);
//         int index2 = binarySearch(oddarr, 5, 9 );

//         cout << "Index of 15 is " << index1 << endl;
//         cout << "Index of 9 is " << index2 << endl;

//         return 0;
//    }