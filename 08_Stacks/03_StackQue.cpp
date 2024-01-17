
// //Next Smaller element

// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

// int main(){
//     vector<int> v;
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(4);
//     v.push_back(3);

//     stack<int> st;
//     st.push(-1);
//     int n = v.size();
//     vector<int> ans(n);
//     // Iterate from right to left to solve que in O(N)
//     for(int i=n-1;i>=0;i--){
//         int curr = v[i];
//         while(st.top()>=curr){
//             st.pop();
//         }
//         //chhotta element mil chuka hai -> ans store
//         ans[i] = st.top();

//         //push current element
//         st.push(curr);
//     }
//     for(int i=0;i<n;i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }


// // 84.Largest Rectangle in Histogram

// class Solution {
// public:
//     vector<int> prevSmaller(vector<int>& heights){
//         stack<int> st;
//         st.push(-1);
//         vector<int> ans(heights.size());
//         for(int i=0;i<heights.size();i++){
//             int curr = heights[i];
//             while(st.top() != -1 && heights[st.top()] >= curr){
//                 st.pop();
//             }
//             ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
//     vector<int> nextSmaller(vector<int>& heights){
//         stack<int> st;
//         st.push(-1);
//         vector<int> ans(heights.size());
//         for(int i=heights.size()-1;i>=0;i--){
//             int curr = heights[i];
//             while(st.top() != -1 && heights[st.top()] >= curr){
//                 st.pop();
//             }
//             ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         // prevSmaller Output
//         vector<int> prev = prevSmaller(heights);
//         //NextSmaller Output
//         vector<int> next = nextSmaller(heights);

//         int maxArea = INT_MIN;
//         int size = heights.size();
//         vector<int> area(size);
//         for(int i=0;i<heights.size();i++){
//             if(next[i] == -1){
//                 next[i] = size;
//             }
//             int length = heights[i];
//             int width = next[i]-prev[i]-1;
//             area[i] = length*width;
//             maxArea = max(maxArea,area[i]);
//         }
//         return maxArea;
//     }
// };