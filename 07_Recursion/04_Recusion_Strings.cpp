// //REVERSING A STRING using Recursion

// #include<iostream>
// using namespace std;

// void reverse(string& str,int i, int j){ //pass by refernce 

//    cout << "Call received for " << str << endl;

//   //base case
//     if(i>j)
//     return;

//     swap(str[i],str[j]);
//     i++;
//     j--;

//     //Recursive call
//     reverse(str,i,j);
// }

// int main(){
//     string name = "Virat";
//     reverse(name,0,name.length()-1);
//     cout << name << endl;

// return 0;
// }

// //CHECK PALINDROME using Recursion

// #include<iostream>
// using namespace std;

// bool checkPalindrome(string str,int i,int j){
//     //base case
//     if(i>j)
//     return true;

//     if(str[i] != str[j])
//     return false;
//     else{
//         //Recursive call
//         return checkPalindrome(str,i+1,j-1);
//     }
// }

// int main(){

//    string name = "AryaayrA" ;
   
//    bool isPalindrome = checkPalindrome(name,0,name.length()-1);

//    if(isPalindrome){
//    cout << "It is a Palidrome " << endl;
//    }
//    else{
//     cout << "Its not a Palindrome " << endl;
//    }

// return 0;
// }

// //Calculating POWER using Recursion

// #include<iostream>
// using namespace std;
// int power(int a,int b){

//     //base case
//     if(b==0)
//     return 1;

//     if(b==1)
//     return a;

//     //Recursive call
 
//     int ans = power(a,b/2);
//     if(b%2 == 0){   //b even
//         return ans * ans;
//     }
//     else{     // b odd
//         return a * ans * ans;
//     }
// }

// int main(){

//     int a,b;
//     cin >> a >> b;

//     int ans = power(a,b);
//     cout << "Answer is " << ans << endl;

// return 0;
// } 