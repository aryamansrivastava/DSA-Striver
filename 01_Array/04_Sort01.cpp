//        SORT 0 1

// #include <iostream>
// using namespace std;
//  // 2 pointer approach se hoga --> jisme ek hi array me i j dono lage
// void printArray(int arr[], int n){
//   for(int i=0; i<n; i++){
//     cout << arr[i] << " " ;
//   }
//   cout << endl;
// }

// void sortone(int arr[], int n)
// {

//   int left = 0, right = n - 1;

//   while (left < right)
//   {
//     while (arr[left] == 0)
//     {
//       left++;
//     }
//     while (arr[right] == 1)
//     {
//       right--;
//     }

//     /*agar yaha pahoch gye ho matlab
//       arr[i]==0 and arr[j]==1 */

//      if(left < right) {
//     swap(arr[left], arr[right]);
//     left++ ;
//     right-- ;
//     }
//   }
// }
// int main()
// {

//   int arr[8] = {1, 1, 0, 1, 0, 1, 0, 0};

//   sortone(arr, 8);
//   printArray(arr, 8);

//   return 0;
// }