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
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define endl '\n'         
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

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
  
 
// ll factorialNumInverse[300000 + 1]; 
  
// // array to precompute inverse of 1! to N! 
// ll naturalNumInverse[300000 + 1]; 
  
// // array to store factorial of first N numbers 
// ll fact[300000 + 1]; 
  
// // Function to precompute inverse of numbers 
// void InverseofNumber(ll p=MOD) 
// { 
//     naturalNumInverse[0] = naturalNumInverse[1] = 1; 
//     for (int i = 2; i <= 300000; i++) 
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
// } 
// // Function to precompute inverse of factorials 
// void InverseofFactorial(ll p=MOD) 
// { 
//     factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
//     // precompute inverse of natural numbers 
//     for (int i = 2; i <= 300000; i++) 
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
// } 
  
// // Function to calculate factorial of 1 to N 
// void factorial(ll p=MOD) 
// { 
//     fact[0] = 1; 
  
//     // precompute factorials 
//     for (int i = 1; i <= 300000; i++) { 
//         fact[i] = (fact[i - 1] * i) % p; 
//     } 
// } 
  
// // Function to return nCr % p in O(1) time 
// ll Binomial(ll N, ll R, ll p=MOD) 
// { 
//     // n C r = n!*inverse(r!)*inverse((n-r)!) 
//     ll ans = ((fact[N] * factorialNumInverse[R]) 
//               % p * factorialNumInverse[N - R]) 
//              % p; 
//     return ans; 
// } 
   
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
vector<int> pi;
 
void prefix_function(string s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}
template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}



    void initialize( vector<ll>&Arr,vector<ll>&size, int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i;
        size[ i ] = 1;
    }
}

// O(log*N) ==> recursive log log log log .....(log N)
// finding root of an element.
// modified root function.
int root (vector<ll>&Arr ,int i)
{
    if(i<0 || i>=Arr.size()) return -2;
    
    if(Arr[ i ] != i)    //chase parent of current element until it reaches root.
    {
        Arr[ i ] = root(Arr, Arr[ i ] ) ;  //path compression
    }
    return  Arr[i];
}
    void weighted_union(vector<ll>&Arr,vector<ll>&size,int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(root_A==root_B) return;
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    
        
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
        // size[root_B]=size[root_A];
    }
}

bool find(vector<ll>&Arr,int A,int B)
{
    if( root(Arr,A)==root(Arr,B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}
   

unordered_map<ll,ll> cst,val,desired;

unordered_map<ll,unordered_set<ll>> occup;

vector<ll> parent;
vector<ll> sz;
vector<ll> dp;

vector<ll> cheapest;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;


ll p1;

void dfs1(int v, int p,vector<vector<ll>>& graph)
{
    ll n=graph.size();
    ll l = ceil(log2(n));
    tin[v] = ++timer;
    up[v][0] = p;

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : graph[v]) {
        if (u != p)
            dfs1(u, v,graph);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
       ll n=p1;

    ll l = ceil(log2(n));

    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root,vector<vector<ll>>& graph) {
    int n=graph.size();
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    ll l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs1(root, root,graph);
}

ll ans=0;

void dfs(ll curr, ll pr,ll min_cst,vector<bool>& vst,vector<vector<ll>>& graph,ll &zero,ll &one)
{

    ll v1=min(min_cst,cst[curr]);

    vst[curr]=true;
    ll zero_des=0;
    ll one_des=0;

    for(auto it :graph[curr])
    {
        if(it!=pr)
        {
            dfs(it,curr,v1,vst,graph,zero_des,one_des);
        }
    }
    if(val[curr]!=desired[curr])
    {
        if(val[curr]==0)
        {
            one_des++;
        }
        else
        {
            zero_des++;
        }
    }
    ll v2=min(zero_des,one_des);
    ans+=2ll*v2*cheapest[curr];
    zero_des-=v2;
    one_des-=v2;
    zero+=zero_des;
    one+=one_des;
    // cout<<curr<<" "<<zero_des<<" "<<one_des<<endl;
    return;
    

    


}

void dfs3(ll curr,ll par,ll min_cst,vector<vector<ll>>& graph)
{
    ll v1=min(min_cst,cst[curr]);
    cheapest[curr]=v1;
    for(auto it:graph[curr])
    {
        if(it!=par)
        {
            dfs3(it,curr,v1,graph);
        }
    }
}


signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        p1=n+1;

        parent.resize(n+1);
        sz.resize(n+1);
        dp.resize(n+1);
        cheapest.resize(n+1);


        initialize(parent,sz,n+1);

        vector<ll> origi(n),desi(n);

        vector<vector<ll>> graph(n+1,vector<ll>());
        // dp[0]=5;
        FOR(i,1,n+1)
        {
            ll a,b,c;

            cin>>a>>b>>c;

            cst[i]=a;
            val[i]=b;

            origi[i-1]=b;
            desi[i-1]=c;
            desired[i]=c;
            
            if(b==c) 
            {
                dp[i]=0;
            }
            else
            {
            //    occup[b].insert(i);
               dp[i]=INT64_MAX;
            }
                
        }

        sort(origi.begin(),origi.end());
        sort(desi.begin(),desi.end());
        
        bool flg=true;

        FOR(i,0,n) if(origi[i]!=desi[i]) flg=false;

        if(flg==false)
        {
            cout<<-1<<endl;
            return 0;
        }

        FOR(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            
            graph[u].pb(v);
            graph[v].pb(u);


        }
        preprocess(1,graph);

        vector<bool> vst(n+1,false);
        
        unordered_set<ll> lft;
        
        dfs3(1,1,INT64_MAX,graph);
        ll v1=0,v2=0;
        dfs(1,-1,INT64_MAX,vst,graph,v1,v2);
        // vector<ll> tmp;
        // ll min_cst=cst[1];
        // for(auto it:lft)
        // {
        //     // cout<<it<<endl;
        //     ll trgt=desired[it];

        //     if(find(parent,it,occup[trgt]) == true)
        //     {
        //         tmp.pb(it);
            
        //     }
        
        // }
        // for(auto it :tmp)
        // {
        //     dp[it]=min(min_cst,dp[it]);
        //     lft.erase(it);
        // }

       

        cout<<ans<<endl;
        
    }
    return 0;
}
