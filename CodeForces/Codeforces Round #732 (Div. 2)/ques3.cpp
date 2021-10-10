#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(ll i=b;i>=a;i--)
#define     debug(x)         cout<< '>'<<#x<<" : "<<x<<"\n";
#define     debug2(x,y)      cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";
#define     debug3(x,y,z)    cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";cout<< '>'<<#z<<" : "<<z<<"\n";
#define     umap             unordered_map
#define     uset             unordered_set
#define     lb               lower_bound
#define     ub               upper_bound
#define     mp               make_pair
#define     in               insert
#define     s                second
#define     f                first
#define     nn               cout<<"\n"
#define     pb               push_back
#define     testcase         int t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             INT_MAX
#define     minv             INT_MIN
#define     MOD              1000000007
#define     SACHITJAGGI      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            cout.flush();
#define endl '\n'         
#define     all(x)           (x).begin(),(x).end()
#define     setcount(x)      __builtin_popcountll(x)
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

inline int add(int a,int b) { return (a%MOD + b%MOD + MOD)%MOD; }
inline int mul(int a,int b) { return (a%MOD * b%MOD + MOD)%MOD; }
inline int sub(int a,int b) { return (a%MOD - b%MOD + MOD)%MOD; }

template<class T> void dispvector(vector<T> v){ for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n"; }

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  
bool solve(vector<int>& arr)
{
    int n=arr.size();
    // unordered_map<int,int> strg;
    // FOR(i,0,n) strg[arr[i]]++;
    vector<pll> arr1;
    FOR(i,0,n) arr1.pb({arr[i],i});

    vector<pll> arr2=arr1;

    sort(arr1.begin(),arr1.end());

    unordered_map<ll,vector<ll>> strg;
    unordered_map<ll,vector<ll>> strg1;


   
    int cnt=0;
    

    FOR(i,0,n)
    {
        strg[arr1[i].f].pb((i)%2);
        strg1[arr1[i].f].pb((arr1[i].s)%2);
    }

    for(auto &it:strg)
    {
        vector<ll> a1=it.s;
        vector<ll> a2=strg1[it.first];

        ll sum1=0;
        ll sum2=0;

        for(auto it1:a1) sum1+=it1;
        for(auto it1:a2) sum2+=it1;

        if(sum1!=sum2) return false;

    }
    return true;
    
    

    // multiset<int> s;
    // int lftmaxi=0;
    // int rgtmini=INT_MAX;
    // int cnt=0;
    // vector<int> count(n,0);
    // for (int i = n - 1; i >= 0; i--) {
    //     if(arr[i]>rgtmini)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         rgtmini=arr[i];
    //         cnt++;
    //     }
    // }
    // cout<<cnt<<" ";

    // for (int i = 0; i < n; i++) 
    // {
    //     if(arr[i]<lftmaxi)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         lftmaxi=arr[i];
    //         cnt++;
    //     }
    // }
    // cout<<cnt<<" ";
    // cout<<endl;
    // dispvector<int>(count);

    // multiset<int> s1;
    // for (int i =0; i<n; i++) {
    //     auto it = s1.upper_bound(arr[i]);
    //     count[i]+= i-distance(s1.begin(), it);
    //     s1.insert(arr[i]);
    // }
    // // dispvector<int>(count);
    
    // for (int i = 0; i < n; i++)
    //     if(count[i]%2==1) return false;
    
   
}


signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    SACHITJAGGI
    long t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<int> arr(n);
        FOR(i,0,n) cin>>arr[i];
        if(solve(arr)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}