// ****** ARRAY BASICS *******

// #include <iostream>
// using namespace std;

// int main()
// {

//    // declare
// int number[15];

//    // accessing an array
// cout << " Value at 15 index " << number[15] << endl;

//     //initialising an array
// int first[3] = {2, 5, 8};

//        //accessing an element
// cout << " Value at 1 index " << first[1] << endl;

// int second[15] = {3, 5};
// int n = 15;
// cout << "printing the array " << endl;
//      // print the array
// for (int i = 0; i < n; i++)
// {
//     cout << second[i] << " ";
// }
// cout << endl;

//    // initialising all locations with 0
//    //(only valid for 0)

// int third[10] = {0};
// n = 10;
// cout << "printing the array " << endl;
//      //print the array
// for (int i = 0; i < n; i++)
// {
//     cout << third[i] << " ";
// }
// cout << endl;

//    // Code for initializing the array with any required value
//     int arr[5];
//     fill_n(arr, 5, 23); // By this code all the values of the array will get initialized by 23
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << "  "; // By this the array will print the initialized value (i.e. 23) 5 times
//     }
//     cout << endl;
//     return 0;
// }

// Scopes in Array

// #include<iostream>
// using namespace std;
//  void update( int arr[], int n){

//  cout <<"Inside the function "<<endl;

//  //updating array's first element
//  arr[0] = 12;

// //printing the array
//  for(int i =0; i<3; i++){
//  cout << arr[i]<<" ";
// } cout << endl;

// cout << "Going back to main function "<<endl;
//  }

// int main(){

// int arr[3] = {4,2,7};

// update(arr,3);

// //printing the array
// cout <<"printing in main function "<<endl;
//  for(int i = 0;i<3; i++){
//  cout << arr[i]<<" ";
// }
// cout << endl;
// return 0;
// }
