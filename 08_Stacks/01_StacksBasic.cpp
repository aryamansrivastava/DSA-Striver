
// Cpp Reference Stack padhna hai -> padh lo

// #include<iostream>
// #include<stack>
// using namespace std;

// int main(){

//     // Creation
//     stack<int>st;

//     //Insertion
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);

//     //Remove -> Lifo -> 40 remove hoga
//     st.pop();

//     //Check element on top -> 30 aayega
//     cout << "Element on top is: " << st.top() << endl;

//     // size of stack
//     cout << "Size of Stack is: " << st.size() << endl;

//     if(st.empty()) cout << "Stack is empty" << endl;
//     else cout << "Stack is not empty" << endl;

//     // print stack elements -> always reverse me print hoga
//     cout << "Print Stack elements: ";
//     while(!st.empty()){
//         cout << st.top() << " ";
//         st.pop();
//     }
// }


// // Stack Implementation using Array

// #include<iostream>
// #include<stack>
// using namespace std;

// class Stack{
//     public: 
//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         arr = new int[size];
//         this->size = size;
//         top = -1;
//     }

//     // functions

//     void push(int data){
//         if(size-top>1){
//             //space available
//             //so insert
//             top++;
//             arr[top]=data;
//         }
//         else{
//             //space not available
//             cout << "Stack Overflow" << endl;
//         }
//     }

//     void pop(){
//         if(top==-1){
//             //Stack is empty
//             cout << "Stack Underflow,cant delete element" << endl;
//         }
//         else{
//             //Stack is not empty
//             top--;
//         }    
//     }

//     int getTop(){
//         if(top == -1){
//             cout << "there is no element in stack" << endl;
//         }
//         else{
//             return arr[top];
//         }    
//     }
    
//     //returns no of valid elements in stack
//     int getSize(){
//         return top + 1;
//     }

//     bool isEmpty(){
//         if(top==-1) return true;
//         else return false;
//     }
// };

// int main(){
//     Stack s(10);

//     //Insertion
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);

//     while(!s.isEmpty()){
//         cout << s.getTop() << " ";
//         s.pop();
//     }
//     cout << endl;

//     cout << "Size of stack: " << s.getSize() << endl;
//     s.pop();
//     return 0;
// }



// // 2 Stacks in 1 Array Implementation

// #include<iostream>
// #include<stack>
// using namespace std;

// class Stack{
//     public: 
//     int *arr;
//     int size;
//     int top1;
//     int top2;

//     Stack(int size){
//         arr = new int[size];
//         this->size = size;
//         top1 = -1;
//         int top2=size;
//     }

//     // functions

//     void push1(int data){
//         if(top2-top1==1){
//             //space not available
//             cout << "Overflow" << endl;
//         }
//         else{
//             //space available
//             top1++;
//             arr[top1]=data;
//         }
//     }

//     void pop1(){
//         if(top1==-1){
//             //Stack is empty
//             cout << "Stack1 Underflow,cant delete element" << endl;
//         }
//         else{
//             //Stack is not empty
//             top1--;
//         }    
//     }

//     void push2(int data){
//         if(top2-top1 == 1){
//             cout << "Overflow" << endl;
//         }
//         else{
//             top2--;
//             arr[top2]=data;
//         }    
//     }

//     void pop2(){
//         if(top2==size){
//             //Stack is empty
//             cout << "Stack2 Underflow,cant delete element" << endl;
//         }
//         else{
//             //Stack is not empty
//             top2++;
//         }  
//     }    
// };


// //Find the middle element of the stack

// #include<iostream>
// #include<stack>
// using namespace std;

// void printMiddle(stack<int> &st, int &totalSize){
//     if(st.size()==0){
//         cout << "There is no element in Stack" << endl;
//         return;
//     }
//      // base case
//     if(st.size() == totalSize/2 + 1){
//         cout << "Middle element is: "<< st.top() << endl;
//         return ;
//     }
//     int temp=st.top();
//     st.pop();

//     // recursive call
//     printMiddle(st,totalSize);

//     // backtrack
//     st.push(temp);
// }

// int main(){
//     stack<int> st;
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);
//     st.push(50);
//     st.push(60);
//     st.push(70);

//     int totalSize = st.size();
//     printMiddle(st,totalSize);
//     return 0;
// }