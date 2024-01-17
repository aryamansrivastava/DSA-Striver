
// Number Hashing
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

		ll n;
		cin >> n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>> a[i];
		}

		// precomputation
		int hash[13] = {0};
		for(int i=0;i<n;i++){
			hash[a[i]]++;
		}

		// q queries
		int q;
		cin >> q;
		while(q--){
			int number;
			cin >> number;
			//fetching
			cout << hash[number] << endl;
		}
	return 0;
}

//Input               
// 5          <- array size
// 1 2 1 3 2    <- array
// 5         <- no of query
// 1 
// 3
// 4
// 2
// 10

//Output -> Frequency of numbers
// 2     
// 1
// 0
// 2
// 0


// Character Hashing

// total 256 characters exist
// to hash all the chahracters -> hash[s[i]]++ krenge
// and fetch bhi -> hash[c] se ho jaayega

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

		string s;
        cin >> s;

		// precomputation
		int hash[26] = {0};
		for(int i=0;i<s.size();i++){
			hash[s[i]-'a']++;
		}

		// q queries
		int q;
		cin >> q;
		while(q--){
			char c;
			cin >> c;
			//fetching
			cout << hash[c-'a'] << endl;
		}
	return 0;
}

//Input               
// abcdabdeach   <- string s
// 5           <- no of query
// a
// d
// h
// b
// c

//Output -> Frequency of chahracters
// 3    
// 2
// 1
// 2
// 2


// Using Map and Unordered Map
// Map stores all the values in the Sorted manner
// whereas an Unordered_map does not.
// try to use unordered map first, if it fails then map

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

		ll n;
		cin >> n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>> a[i];
		}

		// precomputation
		unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
			mp[a[i]]++;
		}

        //iterate in the map
        for(auto it: mp){
            cout << it.first << "->" << it.second << endl;
        }

		// q queries
		int q;
		cin >> q;
		while(q--){
			int number;
			cin >> number;
			//fetching
			cout << mp[number] << endl;
		}
	return 0;
} 

//Input               
// 7                <- array size
// 1 2 3 1 3 2 12    <- array
// 5               <- no of query
// 1 
// 2
// 3
// 4
// 12

//Output -> Frequency of numbers
//this is how it is stored in the map

// 1->2
// 2->2
// 3->2
// 12->1

// 2     
// 2
// 2
// 0
// 1 