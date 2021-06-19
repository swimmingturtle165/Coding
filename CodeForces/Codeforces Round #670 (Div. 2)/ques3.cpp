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
  
ll dfs(ll curr,ll parent,ll& n,unordered_map<ll,vector<ll>>& strg,vector<vector<ll>>& graph)
{
    ll cnt=1;
    ll maxi=0;
    for(auto u:graph[curr])
    {
        if(u!=parent)
        {
            ll tmp=dfs(u,curr,n,strg,graph);
            maxi=max(maxi,tmp);
            cnt+=tmp;
        }
    }
   
    maxi=max(maxi,n-cnt);
    

    strg[maxi].pb(curr);

    return cnt;
}

pll dfs2(ll curr,ll parent,ll block,vector<vector<ll>>& graph)
{
    ll cnt=1;
    ll maxi=0;
    bool flg1=false;
    bool flg2=false;

    for(auto u:graph[curr])
    {
        if(u!=parent && u!=block)
        {
            pll tmp=dfs2(u,curr,block,graph);
            if(tmp.f==-1 && tmp.s!=-1)
            {
                tmp.f=curr;
            }
            if(tmp.f==-1 && tmp.s==-1)
            {
                flg2=false;
            }
            if(tmp.f!=-1)
            {
               return tmp;
            }
        }
        if(u==block)
        {
            flg2=true;
        }
        flg1=true;
        
    }
    if(flg2==false)
    return {-1,curr};
    else
    return {-1,-1};

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
        vector<vector<ll>> graph(n+1,vector<ll>());
        pll tmp;
        FOR(i,0,n-1)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
            tmp={a,b};
        }
        unordered_map<ll,vector<ll>> strg;

        dfs(1,-1,n,strg,graph);

        ll maxi=INT_MAX;
        vector<ll> answ;
        for(auto it:strg)
        {
            if(it.f<maxi)
            {
                maxi=it.f;
                answ=it.s;
            }
        }
        // cout<<maxi<<" (( "<<endl;
        // dispvector<ll>(answ);
        if(answ.size()==2)
        {
            ll v1=answ[0];
            ll v2=answ[1];
            pll v3=dfs2(v1,-1,v2,graph);
            
            cout<<v3.f<<" "<<v3.s<<endl;
            cout<<v2<<" "<<v3.s<<endl;

        }
        else
        {
            cout<<tmp.f<<" "<<tmp.s<<endl;
            cout<<tmp.f<<" "<<tmp.s<<endl;

        }

    }
    return 0;
}
