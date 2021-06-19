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
        sort(arr.begin(),arr.end());
        ll mini=INT_MAX;
        unordered_map<ll,ll> strg;

        FOR(i,0,n) strg[arr[i]]++;

        FOR(i,0,n-1)
        {
            mini=min(mini,arr[i+1]-arr[i]);
        }

        vector<ll> prefix_dist(n,0);
        vector<ll> suffix_dist(n,0);

        FOR(i,1,n)
        {
            prefix_dist[i]+= prefix_dist[i-1];
           
                prefix_dist[i]++;
        }

        FORDE(i,n-2,0)
        {
            suffix_dist[i]+=suffix_dist[i+1];
           
                suffix_dist[i]++;
        }
        ll answ=0;

        ll maxi=0;

        ll option=0;

        FOR(i,1,n)
        {
            if(arr[i]-arr[i-1]==mini)
            {
                
                // 4 possible cases


                // i  i-1
                //opt 0 i=>n 0=>i-1
                //opt 1 0=>n
                
                ll v1=i-1>=0?suffix_dist[i-1]:0;  //suffix_dist[i-1]
                ll v2=i+1<n?suffix_dist[i+1]:0;   //suffix_dist[i+1]
                ll v3=i-2>=0?prefix_dist[i-2]:0;  //prefix_dist[i-2]
                ll v4=i-1>=0?prefix_dist[i-1]:0;  //prefix_dist[i-1]

                

                ll tmp1=suffix_dist[i]+v4;

                if(tmp1>=maxi)
                {
                    maxi=tmp1;
                    answ=i;
                    option=1;
                }

                ll tmp2=v2+v3;

                if(i-2>=0 && i+1<n && arr[i-2]!=arr[i+1])
                {
                    tmp2++;
                }
                if(tmp2>=maxi)
                {
                    maxi=tmp2;
                    answ=i;
                    option=2;
                }

                // i-1  i
                //opt 3  i-1>=n 0=>i
                //opt 4  0=>n

                ll tmp3=v2+prefix_dist[i];

                if(i-1>=0 && i+1<n && arr[i-1]!=arr[i+1])
                {
                    tmp3++;
                }
                if(tmp3>=maxi)
                {
                    maxi=tmp3;
                    answ=i;
                    option=3;
                }

                ll tmp4=v3+v2;
                 if(i-1>=0 && i+1<n && arr[i-1]!=arr[i+1])
                {
                    tmp4++;
                }

                if(tmp4>=maxi)
                {
                    maxi=tmp4;
                    answ=i;
                    option=4;
                }

            }
        }
        //
        if(option==1)
        {
                // i  i-1
                //opt 0 i=>n 0=>i-1
                //opt 1 0=>n

                cout<<arr[answ]<<" ";
                FOR(i,answ+1,n) cout<<arr[i]<<" ";
                FOR(i,0,answ-1) cout<<arr[i]<<" ";
                cout<<arr[answ-1]<<endl;
        }
        if(option==2)
        {
                  // i  i-1
                //opt 0 i=>n 0=>i-1
                //opt 1 0=>n
                 cout<<arr[answ]<<" ";
                FOR(i,0,answ-1) cout<<arr[i]<<" ";
                FOR(i,answ+1,n) cout<<arr[i]<<" ";
                cout<<arr[answ-1]<<endl;
        }
        if(option==3)
        {
             // i-1  i
                //opt 3  i-1>=n 0=>i
                //opt 4  0=>n

                 cout<<arr[answ-1]<<" ";
                FOR(i,answ+1,n) cout<<arr[i]<<" ";
                FOR(i,0,answ-1) cout<<arr[i]<<" ";
                cout<<arr[answ]<<endl;
        }
        if(option==4)
        {
             // i-1  i
                //opt 3  i-1>=n 0=>i
                //opt 4  0=>n
                 cout<<arr[answ-1]<<" ";
                FOR(i,0,answ-1) cout<<arr[i]<<" ";
                FOR(i,answ+1,n) cout<<arr[i]<<" ";
                cout<<arr[answ]<<endl;
        }    
    }
    return 0;
}
