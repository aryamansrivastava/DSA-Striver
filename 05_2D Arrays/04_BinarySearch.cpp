// Search a 2D Matrix I(Binary Search)
//Is Ques me matrix sorted hai Ascending order me
// Time Complexity --> O(log(row*col))

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
        
//         int start = 0;
//         int end = row*col-1;
//         int mid = start + (end-start)/2;
//         while(start<=end){
//             int element = matrix[mid/col][mid%col];
            
//             if(element == target){
//                 return 1;
//             }
//             else if(element < target) {
//                 start = mid+1;
//             }
//             else {
//                 end = mid-1;
//             }
//              mid = start + (end-start)/2;
//         }
//         return 0;
//     }
// };

// Search a 2D Matrix II(Binary Search)
//Is Ques me matrix sorted hai row and column wise both
// Time Complexity --> O(log(row*col))

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row = matrix.size();
//         int col = matrix[0].size();
        
//         int rowIndex = 0;
//         int colIndex = col-1;
        
//         while(rowIndex<row && colIndex>=0){
//             int element = matrix[rowIndex][colIndex];
            
//             if(element == target){
//                 return 1;
//             }
//             else if(element < target){
//                 rowIndex++;
//             }
//             else{
//                 colIndex--;
//             }
//         }
//     return 0;
//     }
// };