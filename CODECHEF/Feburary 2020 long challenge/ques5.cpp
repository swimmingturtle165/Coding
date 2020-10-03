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
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>


ll nCrModpDP(ll n, ll r) 
{ 
    
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    { 
        
        for (ll j = min(i, r); j > 0; j--) 
  
            
            C[j] = (C[j] + C[j-1])%MOD; 
    } 
    return C[r]; 
} 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll ntopowermandMod(ll n,ll m,ll mod_v)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowermandMod(n,m/2,mod_v);
        val=val%mod_v;
        val=val*val;
        val=val%mod_v;
        if(m%2==1)
        {
        val=val*n;
        val=val%mod_v;
        }
        return val;

    }
    
}
ll ntopowerm(ll n,ll m)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowerm(n,m/2);
        val=val*val;
        if(m%2==1)
        {
        val=val*n;
        }
        return val;

    }
    
}
template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        vector<ll> x_pts(n),y_pts(m);
        unordered_set<ll,custom_hash> x_neg,y_neg;
        unordered_set<ll> x_mod,y_mod;

        FOR(i,0,n)
        {
            cin>>x_pts[i];
            if(x_pts[i]<0)
            {
                x_neg.insert(0-x_pts[i]);
            }
            else
            x_mod.insert(abs(x_pts[i]));
        }
        FOR(i,0,m)
        {
            cin>>y_pts[i];
            if(y_pts[i]<0)
            {
                y_neg.insert(0-y_pts[i]);
            }
            else
            y_mod.insert(abs(y_pts[i]));

        }
        unordered_set<ll,custom_hash> done;
        ll ans=0;
        FOR(i,0,n)
        {
                    for (ll j=1; j<=sqrt(abs(x_pts[i])); j++) 
            { 
                if ((x_pts[i]*x_pts[i])%j == 0 ) 
                {              
                        if(y_mod.count(j)>0 && y_neg.count((x_pts[i]*x_pts[i])/j)>0)
                        {
                            ans++;
                        }
                        if( ((x_pts[i]*x_pts[i])/j)!=j && y_neg.count(j)>0 && y_mod.count((x_pts[i]*x_pts[i])/j)>0)
                        {   
                            
                            ans++;
                        }
                    
                    
                } 
            }
            
            if(y_mod.count(abs(x_pts[i]))>0 && y_neg.count(abs(x_pts[i]))>0)
            {
                ans++;
                done.insert(abs(x_pts[i]));
            } 
        }

        FOR(i,0,m)
        {
                    for (ll j=1; j<=sqrt(abs(y_pts[i])); j++) 
            { 
                if ((y_pts[i]*y_pts[i])%j == 0 ) 
                { 
                    // If divisors are equal, print only one 
                   
                        if(x_mod.count(j)>0 && x_neg.count((y_pts[i]*y_pts[i])/j)>0)
                        {
                            ans++;
                        }
                        else if(((y_pts[i]*y_pts[i])/j)!=j&&  x_neg.count(j)>0 && x_mod.count((y_pts[i]*y_pts[i])/j)>0)
                        {
                            
                            ans++;
                        }
                    
                    
                } 
            }
            
            if(done.count(abs(y_pts[i]))==0 && x_mod.count(abs(y_pts[i]))>0 && x_neg.count(abs(y_pts[i]))>0)
            {
                ans++;
            } 
        }
        if(x_mod.count(0)>0 || y_mod.count(0)>0)
        {
            ans+=(n-x_mod.count(0))*(m-y_mod.count(0));
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
