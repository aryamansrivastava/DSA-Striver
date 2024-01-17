// **** Wave print problem ***
// Time Complexity --> O(nm) -->bcoz har element ko traverse kiya h bas

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
// {
//    vector<int> ans;
//    for(int col=0; col<=mCols-1; col++) {
//        if(col&1) {
//            //odd index -> bottom to top
//            for(int row=nRows-1;row>=0; row--){
//               ans.push_back(arr[row][col]);
//            }
//        }
//        else  {
//            //even index ->top to bottom
//        for(int row=0; row<=nRows-1; row++){
//          ans.push_back(arr[row][col]);
//        }
//       }
//    }
//     return ans;
// }
