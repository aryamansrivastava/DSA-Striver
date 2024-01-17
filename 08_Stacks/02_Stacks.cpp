
// Insert top element at the bottom of the stack

// #include<iostream>
// #include<stack>
// using namespace std;

// void insertAtBottom(stack<int> &st, int target){
//     //base case
//     if(st.empty()){
//         st.push(target);
//         return;
//     }

//     int topElement = st.top();
//     st.pop();
//     // recursive call
//     insertAtBottom(st,target);
//     // backtrack
//     st.push(topElement);
// }

// int main(){
//     stack<int> st;
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);
//     st.push(50);
//     st.push(60);

//     if(st.empty()){
//         cout << "Stack is empty,cant insert at bottom" << endl;
//     }
//     int target=st.top();
//     st.pop();

//     insertAtBottom(st,target);

//     cout << "Printing: ";
//     while(!st.empty()){
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;
//     return 0;
// }


// Reversing a Stack using Recursion

// #include<iostream>
// #include<stack>
// using namespace std;

// void insertAtBottom(stack<int> &st, int target){
//     //base case
//     if(st.empty()){
//         st.push(target);
//         return;
//     }

//     int topElement = st.top();
//     st.pop();
//     // recursive call
//     insertAtBottom(st,target);
//     // backtrack
//     st.push(topElement);
// }

// void reverseStack(stack<int> &st){
//     //base case
//     if(st.empty()){ 
//         return;
//     }
//     int target = st.top();
//     st.pop();
//     //reverse stack
//     reverseStack(st);
//     //insert at bottom target ko
//     insertAtBottom(st,target);
// }

// int main(){
//     stack<int> st;
//     st.push(10);
//     st.push(20);  
//     st.push(30);
//     st.push(40);
//     st.push(50);

//     reverseStack(st);

//     cout << "Printing: ";
//     while(!st.empty()){
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;
//     return 0;
// }


// Sort the Stack

#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st, int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    if(st.top() >= target){
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertSorted(st,target);

    //Backtrack
    st.push(topElement);
}

void sortStack(stack<int> &st){
    //base case
    if(st.empty()){ 
        return;
    }
    int topElement = st.top();
    st.pop();
    
    sortStack(st);

    insertSorted(st,topElement);
}

int main(){
    stack<int>st;
    st.push(14);
    st.push(11);  
    st.push(30);
    st.push(15);
    st.push(19);

    sortStack(st);

    cout << "Printing: ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}