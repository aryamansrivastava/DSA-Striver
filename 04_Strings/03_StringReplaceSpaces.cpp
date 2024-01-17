// ***** String replace spaces***** 

// input--> Aryaman is bad boy
// output---> Aryaman@40is@40bad@40boy

// Time Compexity---> O(n)
// Space Compexity---> O(n)

//  #include<bits/stdc++.h>
//   using namespace std;
 
// string replaceSpaces(string str){
//     string temp = "" ;
// 	// Write your code here.
//     for(int i=0; i<str.length(); i++){
//         if(str[i]== ' '){
//             temp.push_back('@');
//             temp.push_back('4');
//             temp.push_back('0');
//         }
//         else {
//             temp.push_back(str[i]);
//         }
//     }
//     return temp;
// }
// int main() {
//     string str;
//     cin >> str;
//     cout <<  replaceSpaces(str) << endl;
//  return 0;
//  } 