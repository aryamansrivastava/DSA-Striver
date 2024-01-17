// //Example:4
// //Search in a Rotatated and Sorted Array
// //code here only

// int getPivot(int arr[], int n) {

//     int s=0;
//     int e = n-1;
//     int mid = s + (e-s)/2;

//     while(s<e) {
//         if(arr[mid] >= arr[0]){
//             s = mid + 1;
//         } else {
//             e = mid;
//         }
//       mid = s + (e-s)/2;
//     }
//     return s;
// }

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
// int findPosition(int arr[], int n, int key)
// {
//     int pivot = getPivot(arr,n);
//     if(key > arr[pivot] && key <= arr[n-1])
//     {
//         return binarySearch(arr, pivot, n-1, key);
//     }
//     else 
//     {
//         return binarySearch(arr, 0, pivot -1, key);
//     }
