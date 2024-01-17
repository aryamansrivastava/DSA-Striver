// ******INSERTION SORT *****

//     stable sort
//  Time Complexity-- > Worst case O(n ^ 2)
//  Best case TC--->O(n)
//  Space Complexity-- > O(1)

// #include <iostream>
// using namespace std;

// int main()
// {

//      int n;
//      cin >> n;
//      int arr[n];
//      for (int i = 0; i < n; i++)
//      {
//           cin >> arr[i];
//      }

//      // for rounds 1st element ko sorted maan liya apne se
//      for (int i = 1; i < n; i++)
//      {
//           int temp = arr[i];
//           int j = i - 1;
//           while (arr[j] > temp && j >= 0)
//           {
//                arr[j + 1] = arr[j]; // shift
//                j--;
//           }
//           arr[j + 1] = temp;
//      }
//      for (int i = 0; i < n; i++)
//      {
//           cout << arr[i] << " ";
//      }
//      cout << endl;
//      return 0;
// }