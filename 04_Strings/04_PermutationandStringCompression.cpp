// ******Permutation in String*****
// WARNING **********
// **********question galat h abhi ye run nhi hua h

// #include<iostream>
// using namespace std;

// bool checkEqual (int a[26], int b[26])
// {
//     for(int i =0; i<26;i++){
//         if(a[i] != b[i])
//         return 0;
//     }
// }

// bool checkInclusion(string s1, string s2) {
//    //character count array
//     int count1[26] = {0};

//     for(int i=0; i<s1.length(); i++) {
//         int index = s1[i] - 'a';
//         count1[index]++;
//     }

//     //traverse s2 string in window of size s1 length and compare

//     int i = 0;
//     int windowsize = s1.length();
//     int count2[26] = {0};

//     //ruuning for first window
//     while(i < windowsize && i<s2.length()) {
//         int index = s2[i] - 'a';
//         count2[index]++;
//         i++;
//     }
// }

// if( checkEqual(count1, count2))
// return 1;

// //aage window process karo
// while(i<s2.length()) {
//     char newChar = s2[i];
//     int index = newChar - 'a';
//     count2[index]++;
    
//     char oldChar = s2[i - windowsize];
//     int index = oldChar - 'a';
//     count2[index]-- ;
//     i++;

//     if(checkEqual(count1, count2))
//     return 1;
// }

// int main(){
//     cout << checkInclusion(s1,s2);
// return 0;
// }

// SUN LE BSDKKKKKK
// ********KUCH QUESTIONS BACHE H ABHI STRING ME

// ****** String Compression ********

// only code is here

// {
// int i = 0;
// int ansIndex = 0;
// int n = chars.size();

// while(i<n)
// {
//     int j = i+1;
//     while(j<n && chars[i] = chars[j])
//     {
//         j++;
//     }
//     // yaha kab aaoge
//     // ya to vector poora traverse kardia
//     // ya fir new/Different character encounter kia hai

//     //oldChar store karlo
//     chars[ansIndex++] = chars[i];

//     int count = j-i;
//     //converting counting into single digit and saving in answer
//     string cnt = to_string(count);
//     for(char ch: cnt)
//     {
//         chars[ansIndex++] = ch;
//     }
// }
// //moving to new/Different Character
// i = j;
// }
// return ansIndex;