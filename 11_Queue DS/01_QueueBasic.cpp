
// CPP Reference Queue padhna hai -> google se

// #include <iostream>
// #include<queue>
// using namespace std;

// int main() {
//   //creation
//   queue<int> q;

//   //insertion
//   q.push(5);
//   q.push(15);
//   q.push(25);
//   q.push(55);

//   //size
//   cout << "Size of queue is:  "<< q.size() << endl;

//   //removal
//   q.pop();

//   cout << "Size of queue is:  "<< q.size() << endl;

//   if(q.empty()) {
//           cout << "Q is empty" << endl;
//   }
//   else {
//           cout << "Q is not empty " << endl;
//   }

//   cout << "Front element is: "<< q.front() << endl;



//   return 0;
// }


// // Queue implementation using Array
// #include <iostream>
// using namespace std;

// class Queue {
//         public:
//         int *arr;
//         int size;
//         int front;
//         int rear;

//         Queue(int size) {
//                 this->size = size;
//                 arr = new int[size];
//                 front = 0;
//                 rear = 0;
//         }

//         void push(int data) {
//                 if(rear == size) {
//                         cout << "Q is full " << endl;
//                 }
//                 else {
//                         arr[rear] = data;
//                         rear++;
//                 }
//         }

//         void pop() {
//                 if(front == rear) {
//                         cout << "Q is empty" << endl;
//                 }
//                 else{
//                         arr[front] = -1;
//                         front++;
//                         if(front == rear) {
//                                 front = 0;
//                                 rear = 0;
//                         }
//                 }
//         }

//         int getFront() {
//                 if(front == rear) {
//                         cout << "Q is empty"<< endl;
//                         return -1;
//                 }
//                 else {
//                         return arr[front];
//                 }
//         }

//         bool isEmpty() {
//                 if(front == rear) {
//                         return true;
//                 }
//                 else {
//                         return false;
//                 }
//         }
//         int getSize() {
//                 return rear - front;
//         }
// };

// int main() {
//   Queue q(10);

//   q.push(5);
//   q.push(15);
//   q.push(25);
//   q.push(55);

//    cout << "Size of queue is: " << q.getSize() << endl;

//    q.pop();

//    cout << "Size of queue is: " << q.getSize() << endl;

//    cout << "Front element is: " << q.getFront() << endl;

//    if(q.isEmpty()) {
//            cout << "Q is empty" << endl;
//    }
//    else{
//            cout << "Q is not empty" << endl;
//    }
//   return 0;
// }

// // Circular Queue implementaion using Array

// #include <iostream>
// using namespace std;

// class CirQueue{
//         public:
//         int size;
//         int *arr;
//         int front;
//         int rear;

//         CirQueue(int size) {
//                 this->size = size;
//                 arr = new int[size];
//                 front = -1;
//                 rear = -1;
//         }

//         void push(int data) {
//                 //Queue Full
//                 //single element case - > first element
//                 //circular nature
//                 //normal flow
//                 //TODO: add one more condition in the QUEUE FULL if block
//                 if((front == 0 && rear == size-1)) {
//                         cout << "Q is fulll, cannot insert" << endl;
//                 }
//                 else if(front == -1) {
//                         front = rear = 0;
//                         arr[rear] = data;
//                 }
//                 else if(rear == size-1 && front != 0 ) {
//                         rear = 0;
//                         arr[rear] = data;
//                 }
//                 else{
//                         rear++;
//                         arr[rear]= data;
//                 } 
//         }

//         void pop() {
//                 //empty check
//                 //single element
//                 //circular nature
//                 //normal flow
//                 if(front == -1) {
//                         cout << "Q is empty , cannot pop" << endl;
//                 }
//                 else if (front == rear) {
//                         arr[front] = -1;
//                         front = -1;
//                         rear = -1;  
//                 }
//                 else if(front == size-1) {
//                         front = 0;
//                 }
//                 else {
//                         front++;
//                 }
//         }
// };

// int main() {
//   CirQueue q(5);

//   q.push(5);
//   q.push(15);
//   q.push(25);
//   q.push(55);
//   q.pop();
//   q.push(17);
//   q.push(12);
//   return 0;
// }


// // Doubly Ended Queue(Deque) using STL

// #include <iostream>
// #include<deque>
// using namespace std;

// int main() {
//   //creation
//   deque<int> dq;

//   dq.push_front(5);
//   dq.push_front(10);
//   dq.push_back(20);
//   dq.push_back(30);

//   cout << "Size: " << dq.size() << endl;
//   dq.pop_front();
//   cout << "Size: " << dq.size() << endl;
//   dq.pop_back();
//   cout << "Size: " << dq.size() << endl;

//   cout << "Front:  " << dq.front() << endl;
//   cout << "back: " << dq.back() << endl;

//   if(dq.empty() ) {
//           cout << "DQ is empty" << endl;
//   }
//   else{
//           cout << "DQ is not empty" << endl;
//   }
//   return 0;
// }


// // Doubly Ended Queue (Deque) Implementaion using Array

// #include <iostream>
// using namespace std;

// class Deque{
//         public:
//         int *arr;
//         int size;
//         int front;
//         int rear;

//         Deque(int size) {
//                 this->size = size;
//                 arr = new int[size];
//                 front= -1;
//                 rear = -1;
//         }

//         void pushRear(int data) {
//                  //TODO: add one more condition in the QUEUE FULL if block
//                 if((front == 0 && rear == size-1)) {
//                         cout << "Q is fulll, cannot insert" << endl;
//                         return;
//                 }
//                 else if(front == -1) {
//                         front = rear = 0;
                        
//                 }
//                 else if(rear == size-1 && front != 0 ) {
//                         rear = 0;
                        
//                 }
//                 else{
//                         rear++;
                        
//                 }
//                 arr[rear]= data; 
//         }

//         void pushFront(int data) {
//                 //TODO: add one more condition in the QUEUE FULL if block
//                 if((front == 0 && rear == size-1)) {
//                         cout << "Q is fulll, cannot insert" << endl;
//                         return;
//                 }
//                 else if(front == -1) {
//                         front = rear = 0;     
//                 }
//                 else if (front == 0 && rear != size-1 ) {
//                         front = size-1;
//                 }
//                 else{
//                         front--;    
//                 }
//                 arr[front]= data; 
//         }

//         void popFront() {
//                 if(front == -1) {
//                         cout << "Q is empty , cannot pop" << endl;
//                         return;
//                 }
//                 else if (front == rear) {
//                         arr[front] = -1;
//                         front = -1;
//                         rear = -1;  
//                 }
//                 else if(front == size-1) {
//                         arr[front] = -1;
//                         front = 0;
//                 }
//                 else {
//                         arr[front] = -1;
//                         front++;
//                 }
                
//         }

//         void popRear() {
//                 if(front == -1) {
//                         cout << "Q is empty , cannot pop" << endl;
//                         return;
//                 }
//                 else if (front == rear) {
//                         arr[front] = -1;
//                         front = -1;
//                         rear = -1;  
//                 }
//                 else if(rear == 0) {
//                         arr[rear] = -1;
//                        rear = size-1;
//                 }
//                 else {
//                         arr[rear] = -1;
//                         rear--;
//                 }          
//         }
//      // Is tarah se Deque ya Queue ko print karna avoid karna hai
//         void print() {
//                 for(int i=0; i<size; i++) {
//                         cout << arr[i] << " ";
//                 }
//                 cout << endl;
//         }
//  };

// int main() {
//   Deque dq(10);
//   dq.print();

//   dq.pushRear(10);
//   dq.pushRear(20);
//   dq.pushRear(30);
//   dq.pushRear(40);
//   dq.pushRear(50);
//   dq.pushRear(60);
//   dq.pushRear(70);
//   dq.pushRear(80);

//   dq.print();

//   dq.popRear();
//   dq.print();

//   dq.popRear();
//   dq.print();

//   dq.popFront();
//   dq.print();

//     dq.popFront();
//   dq.print();

//     dq.popFront();
//   dq.print();

//   dq.pushFront(101);
//   dq.print();

//   dq.pushFront(102);
//   dq.print();

//   dq.pushFront(103);
//   dq.print();

//   dq.pushFront(104);
//   dq.print();

//   dq.popFront();
//   dq.print();

//   dq.popFront();
//   dq.print();

//   dq.pushRear(201);
//   dq.print();

//   dq.pushRear(202);
//   dq.print();

//   dq.pushRear(203);
//   dq.print();

//   dq.pushRear(204);
//   dq.print();

//   dq.pushRear(205);
//   dq.print();

//   return 0;
// }