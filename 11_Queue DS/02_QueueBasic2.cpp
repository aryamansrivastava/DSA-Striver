
// // Reversing a Queue using Recursion

// #include <iostream>
// #include<stack>
// #include<queue>
// using namespace std;

// void reverseQueue(queue<int> &q) {
//         stack<int> s;

//         //step 1: put all elements of q into s
//         while(!q.empty() ) {
//                 int element = q.front();
//                 q.pop();

//                 s.push(element);
//         }

//         //step2: put all element from stack into q
//         while(!s.empty()) {
//                 int element = s.top();
//                 s.pop();

//                 q.push(element);
//         }
// }

// void reverseQueueRecursion(queue<int>& q){
//     //base case
//     if(q.empty()){
//         return;
//     }
//     //Step 1
//     int temp = q.front(); 
//     q.pop();
    
//     //Step 2
//     reverseQueueRecursion(q);
    
//     //Step 3
//     q.push(temp);
// }

// //Reverse first k elements of queue

// void reverseK(queue<int> &q, int k ) {
//         //StepA: queue -> k elements -> push in stack
//         stack<int> s;
//         int count = 0;
//         int n = q.size();

//         if(k <= 0 || k > n)
//                 return ;

//         while(!q.empty()){
//                 int temp = q.front();
//                 q.pop();
//                 s.push(temp);
//                 count++;

//                 if(count == k)
//                         break;
//         } 

//         //stepB: stack se -> q me wapas
//         while(!s.empty()) {
//                 int temp = s.top();
//                 s.pop();
//                 q.push(temp);
//         }

//         //step C: push n-k element from q front to back 
//         count = 0;
//         while(!q.empty() and n-k != 0) {
//                 int temp = q.front();
//                 q.pop();
//                 q.push(temp);
//                 count++;

//                 if(count == n-k)
//                         break;
//         }
// }

// // Interleave two halves of the Queue

// void interleaveQueue(queue<int> &q) {
//         //Step A: separate both halves
//         int n = q.size();
//         if(q.empty())
//           return;
//         int k = n/2;
//         int count = 0;
//         queue<int> q2;

//         while(!q.empty()) {
//                 int temp = q.front();
//                 q.pop();
//                 q2.push(temp);
//                 count++;

//                 if(count == k)
//                         break;
//         }

//         //stepB: interleaving start krdo
//         while(!q.empty() && !q2.empty()) {
//                 int first = q2.front();
//                 q2.pop();

//                 q.push(first);

//                 int second = q.front();
//                 q.pop();

//                 q.push(second);
//         }
//         //odd wala case
//         if(n&1) {
//                int element = q.front();
//                q.pop();
//                q.push(element);
//         }
// }

//   int main() {
//   queue<int> q;

//   q.push(5);
//   q.push(15);
//   q.push(25);
//   q.push(55);

//   // reverseQueue(q);

//   // reverseQueueRecursion(q);

//   // reverseK(q,3);

//   interleaveQueue(q);

//   cout << "printing resultant queue: " ;
//   while(!q.empty()){
//     cout << q.front() << " ";
//     q.pop();
//   }
//   cout << endl;
//   return 0;
// }



// First negative integer in every window of size k

#include <iostream>
#include<deque>
using namespace std;

void solve(int arr[],int n, int k ) {
        deque<int> q;
        //process first window of size k 
        for(int i=0; i<k; i++) {
                if(arr[i] < 0) {
                        q.push_back(i);
                }
        }

        //remaining window ko process kro
        for(int i=k; i<n; i++) {
                //answer dedo purani wondow ka 
                if(q.empty()) {
                        cout << 0 << " ";
                }
                else {
                        cout << arr[q.front()] << " ";
                }

                //out of window elements ko remove krdo
                while((!q.empty()) && (i - q.front() >= k)) {
                        q.pop_front();
                }

                //check current element for insertion 
                if(arr[i] < 0 ) 
                        q.push_back(i);
        }

        //answer print karo for last window
       if(q.empty()) {
                cout << 0 << " ";
        }
        else {
                cout << arr[q.front()] << " ";
        }
}

int main() {
  int arr[] = {12,-1,-7,8,-15,30,16,28};
  int size = 8;
  
  int k = 3;

  solve(arr,size,k);

  return 0;
}


// Homework
// First non-repeating character in a stream(GFG)

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char, int> m;
		    string ans = "";
		    queue<char> q;

		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];

		        q.push(ch);
		        m[ch]++;

		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} 