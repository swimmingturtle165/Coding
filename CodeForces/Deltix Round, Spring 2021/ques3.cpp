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


vector<vector<ll>> answ;

ll solve(ll curr,ll depth,vector<ll>& arr,vector<ll>& present,vector<vector<ll>>& dp)
{
    if(curr==arr.size())
    {
        // dispvector<ll>(present);
        return 1;
    }
    // 3 options 
    // 1->same depth
    // 2->increase depth if(arr[curr]==1)
    // 3->decrease depth 
    ll flg=0;

   
    // if(depth>0 && present.back()+1==arr[curr])
    // {
    //     // 1)same depth
    //     ll rem=present.back();
    //     present.pop_back();
    //     present.pb(arr[curr]);

    //     dp[curr][depth]=(dp[curr][depth]==-1?solve(curr+1,depth,arr,present,dp):dp[curr][depth]);
        
    //     flg=(dp[curr][depth]);

    //      if(flg==1)
    //     {
    //         // cout<<2<<"* ";

    //         // dispvector<ll>(present);

    //         answ.pb(present);
    //         present.pop_back();
    //         present.pb(rem);

    //         return 1;
    //     }
    //     present.pop_back();

    //     present.pb(rem);

    // }
     
    // if(depth>=2 )
    // {
    //     vector<ll> srg;
    //     dispvector<ll>(present);
    //     // decrease depth
    //     while(present.size()>=2)
    //     {
    //         ll rem2=present.back();
    //         present.pop_back();
    //         srg.push_back(rem2);
    //         if(arr[curr]==present.back()+1)
    //         {

    //         present.pb(arr[curr]);
    //         dp[curr][present.size()]=(dp[curr][present.size()]==-1?solve(curr+1,present.size()-srg.size(),arr,present,dp):dp[curr][present.size()]);
    //         flg=dp[curr][present.size()];
    //         }
    //         present.pop_back();

    //      if(flg)
    //      {
    //          answ.pb(present);
    //         //  present.pop_back();
    //         while(srg.size()>0)
    //         {
    //             present.pb(srg.back());
    //             srg.pop_back();
    //         }
    //         return flg;
    //      }
         
    //          present.pop_back();


    //     }
    //     while(srg.size()>0)
    //     {
    //         present.pb(srg.back());
    //         srg.pop_back();
    //     }
        
       
       


    
    // }
    if(arr[curr]==1 )
    {
        // 2->increase depth if(arr[curr]==1)
        present.push_back(1);
       
        // dp[curr][depth+1]=solve(curr+1,depth+1,arr,present,dp);

        dp[curr][depth+1]=( dp[curr][depth+1]==-1?solve(curr+1,depth+1,arr,present,dp):dp[curr][depth+1]);
        flg=(dp[curr][depth+1]);

        if(flg==1)
        {
            // cout<<1<<"* ";
            // dispvector<ll>(present);
             answ.pb(present);
             present.pop_back();
             return 1;
        }

    }
    else
    {
        stack<ll> st;
        while(flg!=1)
        {

          while(present.size()>1 && present.back()!=arr[curr]-1)
         {
            st.push(present.back());
            present.pop_back();

         }
         st.push(present.back());
         present.pop_back();

         present.push_back(arr[curr]);

         dp[curr][present.size()]=dp[curr][present.size()]==-1?solve(curr+1,present.size(),arr,present,dp):dp[curr][present.size()];
         flg=dp[curr][present.size()];
         if(flg==false)
         present.pop_back();


        }
        answ.push_back(present);
        present.pop_back();
        while (st.size()>0)
        {
            present.push_back(st.top());
            st.pop();
        }
        
        return flg;
    }

    return 0;
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
        vector<ll> arr(n);
        FOR(i,0,n) cin>>arr[i];
        vector<ll> present;
        vector<vector<ll>> dp(n+5,vector<ll>(n+5,-1));

        solve(0,0,arr,present,dp);

        for(int i = answ.size()-1;i>=0;i--)
        {
            cout<<answ[i][0];
            for(int j = 1 ; j <answ[i].size();j++)
            {
                cout<<"."<<answ[i][j];
            }
            cout<<endl;
        }
        answ.clear();
    }
    return 0;
}
