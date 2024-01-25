// BENCHES

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// #ifdef ARYAMAN_SRIVASTAVA
//     freopen("Input.txt", "r", stdin);
//     freopen("Output.txt", "w", stdout);
// #endif
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
//     int n,m;
//     cin>>n>>m;
//     int ans1=m;
//     int a[n],b[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     sort(a,a+n);
//     int max=a[n-1];
//     for(int i=0;i<n;i++)
//     {
//         b[i]=max-a[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(m>0)
//         {
//             m=m-b[i];
//         }
//         else
//         {
//             break;
//         }
//     }
//     if(m<=0)
//     {
//         cout<<max<<" "<<max+ans1;
//     }
//     else{
//         if(m%n!=0)
//         {
//         cout<<max+1+m/n<<" "<<max+ans1;
//         }
//         else
//         {
//            cout<<max+m/n<<" "<<max+ans1;
//         }
//
//     return 0;
// }

// Array Reordering

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main() {
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll n,ct=0;
//         cin>>n;
//         ll arr[n];
//         for(int i=0;i<n;i++){
//         cin>>arr[i];
//         }
//         sort(arr,arr+n);
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//           {  if(__gcd(arr[i],2*arr[j])>1 || (__gcd(2*arr[i],arr[j])>1))
//             ct++;}
//         }
//          cout<<ct<<endl;
//       }
// }

// BESTIE

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main() {
//     ll t;
//     cin >> t;
//     while(t--){
//         ll n;
//         cin >> n;
//         ll a[n];
//         for(int i=0;i<n;i++){
//             cin >> a[i];
//         }
//         if(n==1){
//         if(a[0]==1)
//             cout<<0<<endl;
//         else
//             cout<<1<<endl;
//        }
//      if(n==2){
//         if(__gcd(a[0],a[1])==1)
//             cout<<0<<endl;
//         else
//             if(__gcd(a[0],__gcd(2ll,a[2]))==1)
//                 cout<<1<<endl;
//             else
//                 cout<<2<<endl;
//             return;
//     }
//         for(int i=n-2;i>=1;i--){
//             if(__gcd(a[i],a[i+1])==1){

//             }
//         }
//     }
// }

// int luck(int x){
//     int ma=INT_MIN;
//     int mi=INT_MAX;

//     while (x>0)
//     {   int rem = x%10;
//         ma=max(ma,rem);
//         mi=min(mi,rem);
//         x=x/10;

//     }
//     return ma-mi;
// }

// Sets and Union
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
// 	ll t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		ll n;
// 		cin >> n;
// 		vector<vector<int>> V(n);
// 		vector<int> arr;
// 		for (int i = 0; i < n; i++)
// 		{
// 			int x;
// 			cin >> x;
// 			vector<int> S(x);
// 			for (int j = 0; j < x; j++)
// 			{
// 				cin >> S[j];
// 				arr.push_back(S[j]);
// 			}
// 			// V[i] = S;
// 		}
// 		sort(arr.begin(), arr.end());
// 		ll y = arr.size();
// 		for (int k = 0; k < y - 1; k++)
// 		{
// 			if (arr[k] == arr[k + 1])
// 			{
// 				arr.erase(k + 1);
// 			}
// 		}
// 	}

// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

// 	ll t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		ll n,m,k;
// 		cin >> n >> m >> k;
// 		ll a[n],b[m];
// 		ll sum1=0,sum2=0,ans=0;
// 		for(int i=0;i<n;i++){
// 			cin >> a[i];
// 			sum1+=a[i];
// 		}
// 		for(int i=0;i<m;i++){
// 			cin >> b[i];
// 			sum2+=b[i];
// 		}
// 		sort(a,a+n);
// 		sort(b,b+m);
// 		// if(k==1){
// 		// 	if(sum1>=sum2) ans = sum1;
// 		// 	else ans = sum1-a[0]+b[m-1];
// 		// }
// 		if (k % 2) {
// 			ans = sum1-a[0] + max(a[0],b[m-1]);
// 		}

// 		else{
// 			 for(int i=1;i<=k;i++){
// 				if(i%2==1){
// 					if(a[0]<b[m-1]){
// 						ll temp = a[0];
// 						a[0] = b[m-1];
// 						b[m-1] = temp;
// 					}
// 				}
// 				if(i%2==0){
// 					if(b[0]<a[n-1]){
// 						ll temp = b[0];
// 						b[0] = a[n-1];
// 						a[n-1] = temp;
// 					}
// 				}
// 			 }

// 			 for(int i=0;i<n;i++){
// 				ans+=a[i];
// 			 }
// 		}

// 		cout << ans << endl;

// 	}
// 	return 0;
// }

 

// Fear of the dark

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll px, py, ax, ay, bx, by;
//         cin >> px >> py >> ax >> ay >> bx >> by;

//         double x1 = sqrtl((px - ax) * (px - ax) + (py - ay) * (py - ay)), x2 = sqrtl(ax * ax + ay * ay), d1;

//         if (x1 >= x2)
//             d1 = x1;
//         else
//             d1 = x2;

//         double y1 = sqrtl((px - bx) * (px - bx) + (py - by) * (py - by)), y2 = sqrtl(bx * bx + by * by), d2;
//         if (y1 >= y2)
//             d2 = y1;
//         else
//             d2 = y2;

//         double dist = sqrtl((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
//         dist /= (2.0);
//         double ans;
//         if (d1 <= d2)
//             ans = d1;
//         else
//             ans = d2;
//         cout << fixed << setprecision(9) << min({ans, max({dist, x1, y2}), max({dist, x2, y1})}) << endl;
//     }
//     return 0;
// }



// isko samajhna hai tle eliminators se
//matching arrays 
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// #define all(x) x.begin(),x.end()
// #define pb push_back
// #define ff   first
// #define ss   second

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n,x;
//         cin >> n >> x;
//         vector<ll> a(n),b(n);
//         ll ct=0,ct2=0;
//         for(int i=0;i<n;i++){
//             cin >> a[i];
//         }
//         for(int i=0;i<n;i++){
//             cin >> b[i];
//         }
//         vector<pair<int, int>> vp;
//         for(int i=0; i<n; i++)
//             vp.pb({a[i], i});

//         sort(vp.begin(), vp.end());
//         sort(b.begin(), b.end());

//         vector<int> ans(n);
//         int f = 1;
 
//         for(int i=x; i>0; i--)
//         {
//             ans[vp[n-i].ss] = b[x-i];
//             f &= (ans[vp[n-i].ss] < a[vp[n-i].ss]);
//         }
 
//         for(int i=x+1, j=0; i<=n; i++, j++)
//         {
//             ans[vp[j].ss] = b[x+j];
//             f &= (ans[vp[j].ss] >= a[vp[j].ss]);
//         }

//         if(f)      
//         {
//             cout<<"YES\n";
//             for(auto e: ans)   cout<<e<<" ";
//             cout<<"\n";
//         }
//         else   cout<<"NO\n";
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     ll t;
//     cin >> t;
//     while(t--){
//         ll n;
//         cin >> n;
//         ll a[n],b[n],c[n];
//         vector<pair<int,int>> v1;
//         vector<pair<int,int>> v2;
//         vector<pair<int,int>> v3;
//         // ll maxi1=INT_MIN,maxi2=INT_MIN,maxi3=INT_MIN;
//         ll ans=0;
//         for(int i=0;i<n;i++){
//             cin >> a[i];
//             // maxi1=max(a[i],maxi1);
//             v1.push_back({a[i],i});
//         }
//         for(int i=0;i<n;i++){
//             cin >> b[i];
//             // maxi2=max(b[i],maxi2);
//             v2.push_back({b[i],i});
//         }
//         for(int i=0;i<n;i++){
//             cin >> c[i];
//             // maxi3=max(c[i],maxi3);
//             v3.push_back({c[i],i});
//         }
//         sort(v1.begin(),v1.end());
//         sort(v2.begin(),v2.end());
//         sort(v3.begin(),v3.end());

//         for(int x=0;x<3;x++){
//             for(int y=0;y<3;y++){
//                 for(int z=0;z<3;z++){
//                     if (x != y && z != x && y != z) {
// 						ans = max(ans, a[x] + b[y] + c[z]);
// 					}
//                }
//            }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> a(n), freq(n+1);
        for(int i=0;i<n;i++){
            cin >> a[i];
            freq[a[i]]++;
        }
        ll ans=0;
        ll smaller=0;
        for(int i=0;i<=n;i++){
            ans+= 1LL*freq[i]*(freq[i]-1)*(freq[i]-2)/6;
            ans+= 1LL*freq[i]*(freq[i]-1)/2*smaller;
            smaller += freq[i];
        }
        cout << ans << endl;
    } 
    return 0;
}