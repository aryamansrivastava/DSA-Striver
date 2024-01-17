// ****Spiral Print Problem****
// // Time Complexity --> O(nm) -->bcoz har element ko traverse kiya h bas

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> spiralOrder(vector<vector<int>> &matrix)
// {

//     vector<int> ans;

//     int row = matrix.size();
//     int col = matrix[0].size();

//     int count = 0;
//     int total = row * col;

//     // index initialization
//     int startingRow = 0;
//     int endingCol = col - 1;
//     int endingRow = row - 1;
//     int startingCol = 0;

//     while (count < total)
//     {
//         // printing starting row
//         for (int index = startingCol; count < total && index <= endingCol; index++)
//         {
//             ans.push_back(matrix[startingRow][index]);
//             count++;
//         }
//         startingRow++;

//         // printing endingCol
//         for (int index = startingRow; count < total && index <= endingRow; index++)
//         {
//             ans.push_back(matrix[index][endingCol]);
//             count++;
//         }
//         endingCol--;

//         // printing endingRow
//         for (int index = endingCol; count < total && index >= startingCol; index--)
//         {
//             ans.push_back(matrix[endingRow][index]);
//             count++;
//         }
//         endingRow--;

//         // printing startingCol
//         for (int index = endingRow; count < total && index >= startingRow; index--)
//         {
//             ans.push_back(matrix[index][startingCol]);
//             count++;
//         }
//         startingCol++;
//     }
//     return ans;
// };