// **** STRING--> one dimensional character Arrays

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//  string str1 = "Hemllo";
//  cout<< str1<< endl;
//  string str2 ;
//  cout << "Enter second string ";
//  cin >> str2 ;
//  cout << str2 << endl;
// string result = str1 + str2 ;
// cout << result << endl;
// if (str1 == str2) {
//     cout << "Equal " << endl;
// } else {
//     cout << "Not equal "<< endl;
// }
// cout << str1.size() <<endl;
// for(int i =0;i < str1.size(); ++i ){
//     cout << str1[i] <<endl;
// }
// return 0;
//  }

//  *************REVERSING STRING ****************

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//  string str;
//   cin >> str;

//  string str_rev;
//  for (int i = str.size()-1; i>=0; --i){
// str_rev = str_rev + str[i];
/*  upar wala not a good approach bcz we are adding
 str and char and bcz of time complexity*/

//   str_rev.push_back(str[i]);
//  }
//  cout << str_rev <<endl;
//  return 0;
//  }

// ***** PALINDROME STRING *****

//  if( str == str_rev){        //METHOD 1
//     cout <<"YES";
//  } else{
//     cout << "NO";
//  }

//      //METHOD 2

// for(int i=0; i<= (s.size()/2); i++)
// 	{
// 		if(s[i]!=s[(s.size()-1)-i]){
// 			cout<<"NO";
// 			return 0;
// 		}
// 	}	
// 	cout<<"YES";
// 	return 0;
// }

// ******Valid Palindrome********

// *******question galat h ye run nhi ho paya h

// #include<iostream>
// using namespace std;
// int main () {
//     string a;
//     cin >> a;
// bool valid(char ch) {
//     if( (ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
//         return 1;
//     }
//     return 0;
// }
// char toLowerCase(char ch){
//     if (ch >= 'a' && ch <= 'z')
//     return ch;
//     else {
//         char temp = ch - 'A' +'a' ;
//         return temp;
//     }
// }
// bool isPalindrome(string s) {
//     // faltu character hatado
//     string temp = "" ;
//     for(int j=0; j<s.length(); j++) {
//         if(valid(s[j])) {
//             temp.push_back(s[j]);
//         }
//     }
//     //lowercase me kardo
//     for(int j=0; j<temp.length(); j++) {
//         temp[j] = toLowerCase(temp[j]);
//     }
// }
// bool checkPalindrome(string a) {
//     int s = 0;
//     int e = a.length()-1;

//     while(s <= e) {
//         if(a[s] != a[e]) {
//             return 0;
//         } else {
//             s++;
//             e--;
//         }
//     }
//     return 1;
// }
// return checkPalindrome(temp);
// }