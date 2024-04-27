#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[101];
    int size;

    Heap(){
        size=0;
    }

    void insert(int value){
        // value insert karo end me
        size=size+1;
        int index = size;
        arr[index]=value;

        // is value ko place karna hai at correct position
        while(index>1){
            int parentInd=index/2;
            if(arr[index]>arr[parentInd]){
                swap(arr[index],arr[parentInd]);
                index=parentInd;
            }
            else{
                break;
            }
        }
    }
};


int main(){
    Heap h;
    // h.insert(-);
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
    // h.size=6;

    cout << "printing the heap" << endl;
    for(int i=0;i<=h.size;i++){
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // h.insert(110);
    // cout << "printing the heap" << endl;
    // for(int i=0;i<=h.size;i++){
    //     cout << h.arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}