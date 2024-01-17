//      ****** BUBBLE SORT *****

//      stable sort
// Time Complexity --> Worst case O(n^2)
//  Best case TC ---> O(n)
//  Space Complexity --> O(1)

// #include<iostream>
// using namespace std;

// int main(){

// int n; cin >> n;
// int arr[n];
// for (int i = 0; i < n ; i++) {
//     cin >> arr[i];
// }
// int round = 1;
// while(round < n) {
//    bool swapped = false;  //optimised
//     for( int j = 0; j < n - round; j++) {
// process element till n-round th index
//          if( arr[j] > arr[j+1]) {
//             swap(arr[j],arr[j+1]);
//            swappped = true;
//          }
//     }
// round ++;
//        if (swapped == false)
//     //  already Sorted
//        break;
//  }
// for ( int i = 0; i < n; i++) {
//     cout << arr[i] <<" ";
// }
// cout << endl;
// return 0;
// }
