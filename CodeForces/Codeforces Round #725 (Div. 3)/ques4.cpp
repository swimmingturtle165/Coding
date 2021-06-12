#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef      int    ll;
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
        

        ll a,b,k;
        cin>>a>>b>>k;
        ll v2=1;
        ll a1=a/v2;
        ll a2=b/v2;

        if(a==b && k==1)
        {
            cout<<"No"<<endl;
            continue;
        }
      
        ll cnt1=0;
        ll cnt2=0;
        ll cnt=0;

        
        while( a1%2==0)
        {
            a1=a1/2;
            cnt1++;
        }
        ll v3=sqrt(a1);

        for(int i = 3 ; i<=v3;i=i+2)
        {
            while(a1%i==0)
            {
                a1=a1/i;
                cnt1++;
            }
        }
         while(a2>1 && a2%2==0)
        {
            a2=a2/2;
            cnt2++;
        }

        ll v5=sqrt(a2);
        for(int i = 3 ; i<=v5;i=i+2)
        {
            while(a2%i==0)
            {
                a2=a2/i;
                cnt2++;
            }
        }
        if(a1!=1)
        {
            cnt1++;
        }
        if(a2!=1)
        {
            cnt2++;
        }

         

       

       bool flg=false;
       ll mini1=0;
       ll mini2=0;

       if(a!=gcd(a,b))
       {
           mini1=1;
       }
       if(b!=gcd(a,b))
       {
           mini2=1;
       }

        // cout<<mini1<<" "<<mini2<<endl;
     
       if(k>=mini1+mini2 && k<=cnt1+cnt2+2*cnt)
       {
           cout<<"Yes"<<endl;
       }
       else
       {
           cout<<"No"<<endl;
       }
    }
    return 0;
}