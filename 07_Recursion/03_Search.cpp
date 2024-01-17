// // isSorted Array
 
//  #include<iostream>
//  using namespace std;

//  bool isSorted(int arr[],int size){
//     //base case
//     if(size==0 || size==1){
//         return true;
//     }
//     if(arr[0]>arr[1]){
//     return false;
//     }
//     else{
//         bool remainingPart = isSorted(arr+1,size-1);
//         return remainingPart;
//     }
//  }

//  int main(){
//     int  arr[5] = {2,4,6,8,9};
//     int size = 5;

//     bool ans = isSorted(arr,size);
//     if(ans){
//         cout << "Array is Sorted" << endl;
//     }
//     else {
//         cout << "Array is not Sorted" << endl;
//     }
//  return 0;
//  }

//  // getSum Code

//  #include<iostream>
//  using namespace std;

//  int getSum(int arr[],int size){
//     //base case
//     if(size==0) return 0;
//     else if(size==1) return arr[0];
     
//     int remainingPart = getSum(arr+1,size-1);
//     int sum = arr[0]+ remainingPart;
//     return sum;
//  }
 
//  int main(){

//     int arr[5]={2,4,9,9,6};
//     int size=5;

//     int sum=getSum(arr,size);
//     cout << "Sum is " << sum << endl;
 
//  return 0;
//  }

// // Linear Search

//  #include<iostream>
//  using namespace std;

//  void print(int arr[],int size){
//     cout << "Size of array is " << size << endl;
//     for(int i=0;i<size;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//  }

//  bool linearSearch(int arr[],int size,int k){
//     print(arr,size);
//     //base case
//     if(size==0)
//     return false;

//     if(arr[0]==k){
//          return true;
//     }
//     else{
//         bool remainingPart = linearSearch(arr+1,size-1,k);
//         return remainingPart;
//     }
//  }
 
//  int main(){

//     int arr[5]={3,5,1,2,6};
//     int size=5;
//     int key=2;

//     bool ans=linearSearch(arr,size,key);
    
//     if(ans){
//         cout << "Present" << endl;
//     }
//     else{
//         cout << "absent" << endl;
//     }
 
//  return 0;
//  }

// // Binary Search

//  #include<iostream>
//  using namespace std;

//  void print(int arr[],int s,int e){
//     for(int i=s;i<=e;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//  }

//  bool binarySearch(int arr[],int s,int e,int k){
//     print(arr,s,e);

//     //base case
//     //element not found
//     if(s>e)
//     return false;

//     int mid = s+(e-s)/2;
//     cout << "value of arr mid is " << arr[mid] << endl;
//     //element found
//     if(arr[mid]==k){
//         return true;
//     }
//     //recursive realtion
//     if(arr[mid]<k){
//         return binarySearch(arr,mid+1,e,k);
//     }
//     else{
//         return binarySearch(arr,s,mid-1,k);
//     }
//  }
 
//  int main(){
//     int arr[6]={2,4,5,10,14,16};
//     int size=6;
//     int key=16;

//     cout << "Present or not " << endl << binarySearch(arr,0,size-1,key) << endl;
 
//  return 0;
//  }