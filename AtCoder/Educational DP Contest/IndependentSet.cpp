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
  
pll dfs(ll curr,ll parent,vector<vector<ll>>& graph)
{
    bool flg=false;
    vector<pll> answ;

    // answ.f => curr is white
    // answ.s => curr is black

    for(auto u:graph[curr])
    {

        if(u!=parent)
        {
            pll tmp=dfs(u,curr,graph);
            answ.pb(tmp);
            flg=true;
        }

    }
    if(flg==false)
    {
        // cout<<curr<<"* 1 1"<<endl;
        return {1,1};
    }
    // answ.f =>all children node is white
    // answ.s =>all children node is black
    pll ans;
    ll allw=1;
    FOR(i,0,answ.size())
    {
        allw*=answ[i].f;
        allw%=MOD;
    }
    ans.f=allw;
    ans.s=allw;
    vector<ll> prefix_white(answ.size(),0);
    vector<ll> suffix_both(answ.size(),0);
    FOR(i,0,answ.size())
    {
        prefix_white[i]=answ[i].f;
        if(i>0)
        {
            prefix_white[i]=(prefix_white[i]*prefix_white[i-1])%MOD;
        }
    }
    FORDE(i,answ.size()-1,0)
    {
        suffix_both[i]=(answ[i].f+answ[i].s);
        if(i+1!=answ.size())
        {
            suffix_both[i]=(suffix_both[i]*suffix_both[i+1])%MOD;
        }
    }
    FOR(i,0,answ.size())
    {
        ll val=1;

        if(i>0)
        {
            val*=prefix_white[i-1];
            val%=MOD;
        }

        if(i<answ.size()-1)
        {
            val*=suffix_both[i+1];
            val%=MOD;
        }

        val*=answ[i].s;
        val%=MOD;

        ans.f+=val;
        ans.f%=MOD;
    }

    // cout<<curr<<" "<<ans.f<<" "<<ans.s<<endl;
    return ans;

}


signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    SACHITJAGGI
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>> graph(n+1,vector<ll>());
        FOR(i,0,n-1)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vector<ll> prnt(n+1,-1);
        // vector<vector<ll>> dp(n,vector<ll>(2,0));
        pll tmp=dfs(1,-1,graph);
        cout<<(tmp.f+tmp.s)%MOD<<endl;
    }

    return 0;
}
