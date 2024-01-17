// BUBBLE SORT using Recursion

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    //base case---> already sorted
    if(n==0 || n==1){
        return;
    }

    //Recursive call

    //1 case solve kar liya--->largest element ko end me rakh dega
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    bubbleSort(arr,n-1);
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}

int main(){

    int arr[5]={6,13,7,8,10};
   
    bubbleSort(arr,5);
    cout << "Sorted Array : ";
    printArray(arr,5);

return 0;
}

// SELECTION SORT using Recursion
// INSERTION SORT using Recursion

// MERGE SORT using Recursion
#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];
}

void mergeSort(int arr[],int s,int e){
    //base case
    if(s>e){
        return;
    }

    int mid=s+(e-s)/2;

    //left part sort karna hai
    mergeSort(arr,s,mid);

    //right part sort karna hai
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);
    
}

int main(){
    int arr[5] = {2,5,1,6,9};
    int n=5;
    mergeSort(arr,0,n-1);

return 0;
}