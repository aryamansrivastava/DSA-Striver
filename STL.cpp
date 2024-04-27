// // The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures
// //  and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators.

// // STL has 4 components:

// // Algorithms
// // Containers
// // Functors
// // Iterators

// //Learn about C++ STL more on gfg


// #include<bits/stdc++.h>
// using namespace std;

// // Pairs

// void explainPair(){
//     pair<int,int> p1 ={1,4};
//     cout << p1.first << " " << p1.second << endl;

//     pair<int,pair<int,int>> p2 ={1,{3,5}};

//     cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

//     pair<int, int> arr[] = {{1,2},{2,5},{5,1}};

//     cout << arr[1].second;
// }

// // Vector
// //always you can increase its size even if you have predefined the size like v(6)

// void explainVector(){

//     vector<int> vect;

//     vect.push_back(1);
//     vect.emplace_back(3);

//     cout << vect[0] << " " << vect.back() << endl;

//     vector<pair<int,int>> vec;
//     vec.push_back({4,5});
//     vec.emplace_back(4,5);

//     vector<int> v1(5,100);  //{100,100,100,100,100}
//     vector<int> v2(5);      //{0,0,0,0,0}

//     vector<int> v3(5,20);
//     vector<int> v4(v3);   //v4=v3   copy

//     vector<int>::iterator it=v3.begin();   

//     it++;
//     cout << *(it) << " "; 

//     it = it+2;
//     cout << *(it) << " ";

//     // vector<int>::iterator it = v3.end();
//     // vector<int>::iterator it = v3.rend();
//     // vector<int>::iterator it = v3.rbegin();

//     // printing vectors using iterator
//     vector<int> vi{2,4,5,6,7,9};
//     for(vector<int>::iterator it = vi.begin();it != vi.end(); it++){
//         cout << *(it) << " ";
//     }

//     for(auto it = vi.begin();it != vi.end(); it++){
//         cout << *(it) << " ";
//     }

//     for(auto it : vi){
//         cout << it << " ";
//     }

//     // {2,4,5,6,7,9}
//     vi.erase(vi.begin()+1);  // 4 erase ho jaavega

//     // {2,5,6,7,9}
//     vi.erase(vi.begin() + 1,vi.begin() + 4);   // {5,6,7} erase ho jaavega

//     //Insert function

//     vector<int> ve(2,100);  //{100,100}
//     ve.insert(ve.begin(),300);  //{300,100,100}
//     ve.insert(ve.begin() + 1, 2, 30);  //{300,30,30,100,100}

//     vector<int> copy(2,50);  //{50,50}
//     ve.insert(ve.begin(),copy.begin(),copy.end()); //{50,50,300,30,30,100,100}

//     vector<int> x{10,20,52};

//     cout << x.size();   //3
//     x.pop_back();     //{10,20}
//     x.clear();   //erase the entire vector

//     cout << x.empty();

//     // v1 -> {10,20}
//     // v2 -> {30,40}
//     v1.swap(v2);  //v1 -> {30,40}, v2 -> {10,20}

// }

// void explainList(){
//     list<int> ls;

//     ls.push_back(2);     // {2}
//     ls.emplace_back(4);  // {2,4}

//     ls.push_front(5);    // {5,2,4}
//     ls.emplace_front(3);  // {3,5,2,4}

//     // rest functions same as vector
//     // begin, end, rbegin, rend, clear, clear, size, swap
// }
 

// void explainDeque(){
//     deque<int> dq;

//     dq.push_back(2);     // {2}
//     dq.emplace_back(4);  // {2,4}

//     dq.push_front(5);    // {5,2,4}
//     dq.emplace_front(3);  // {3,5,2,4}

//     dq.back();
//     dq.front();

//     // rest functions same as vector
//     // begin, end, rbegin, rend, clear, clear, size, swap
    
// } 

// void explainStack(){
//     //LIFO
//     // all the operations(top,push,pop) are O(1)
//     stack<int> st;
//     st.push(1); // {1}
//     st.push(2); // {2,1}
//     st.push(3); // {3,2,1}
//     st.push(3); // {3,3,2,1}
//     st.emplace(5); // {5,3,3,2,1}

//     cout << st.top(); //print 5 "**st[2] is invalid **"

//     st.pop();  //st looks like {3,3,2,1}

//     cout << st.top(); // 3
//     cout << st.size();  // 4
//     cout << st.empty();
    
//     stack<int>st1, st2;
//     st1.swap(st2); 
// } 

// void explainQueue(){
//     //FIFO
//     // all the operations(top,push,pop) are O(1)
//     queue<int> q;
//     q.push(1); // {1}
//     q.push(2); // {1,2}
//     q.emplace(5); // {1,2,5}

//     q.back() += 5;

//     cout << q.back();  //prints 10

//     // Q is {1,2,10}

//     cout << q.front(); //print 1

//     q.pop();  // {2,10}

//     //size,swap,empty same as stack
// } 

// void PriorityQueue(){

//     priority_queue<int> pq;

//     pq.push(1); // {1}
//     pq.push(2); // {2,1}
//     pq.emplace(5); // {5,2,1}

//     cout << pq.top(); //prints 5

//     pq.pop(); //{2,1}

//     cout << pq.top(); //prints 2
//     // push,pop -> log(n)
//     // top -> O(1)

//     //size,swap,empty same as others

//     //Minimum Heap
//     priority_queue<int,vector<int>, greater<int>> pq;
//     pq.push(5); // {5}
//     pq.push(2); // {2,5}
//     pq.push(8); // {2,5,8}
//     pq.emplace(10); // {2,5,8,10}

//     cout << pq.top(); //prints 2

// } 

// bool comp(pair<int,int> p1, pair<int,int> p2){
//     if(p1.second < p2.second()) return true;
//     if(p1.second > p2.second()) return false;
//     //they are same

//     if(p1.first > p2.first()) return true;
//     return false;

// }

// // set

// //eraser

// //multiset

// // unordered set

// // map


// // multimap



// void explainExtra(){

//     sort(a,a+n);
//     sort(v.begin(),v.end());
//     sort(a+2,a+4);

//     sort(a,a+n,greater<int>); 

//     pair<int,int> a[] = {{1,2},{2,1},{4,1}};

//     // sort it according to second element 
//     // if second element is same,then sort 
//     // it according to first element but in descending
    
//     sort(a,a+n,comp);

//     // {{4,1},{2,1},{1,2}};

//     int num = 7;
//     int cnt = __builtin_popcount();

//     long long num = 165786578687;
//     int cnt = __builtin_popcountll();

//     string a = "123";
//     sort(s.begin(),s.end());

//     do{
//         cout << s << endl;
//     }  while(next_permutation(s.begin(),s.end()));

//     int maxi = *max_element(a,a+n);

// }


// int main(){

//     explainPair();
//     explainVector();
//     explainList();
//     explainDeque();
//     explainStack();
//     explainQueue();
//     explainPriorityQueue();
//     explainexplainExtra();

//     return 0;
// }