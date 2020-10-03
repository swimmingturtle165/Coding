#include<bits/stdc++.h>
using namespace std;

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
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n ;
        cin>>n;
        vector<ll> strg(n+1,0);
        vector<ll>inp1(n),inp2(n),inp3(n);
        FOR(i,0,n) cin>>inp1[i];
        FOR(i,0,n) cin>>inp2[i];
        FOR(i,0,n) cin>>inp3[i];
        bool flg=true;
        vector<ll> ind_x;
        vector<vector<ll>> graph (n+1,vector<ll>()) ;
        FOR(i,0,n-1)
        {
            ll a,b;
            cin>>a>>b;
            
            strg[a]++;
            strg[b]++;

            graph[a].pb(b);
            graph[b].pb(a);

            if(strg[a]>2 || strg[b]>2)
            {
                // cout<<a<<" "<<b<<endl;
                
                flg=false;
            }
           
        }
        if(!flg)
        {
            cout<<-1<<endl;
        }
        else
        {
            ll start;
            FOR(i,0,n+1)
            {
                if(strg[i]==1)
                {
                    start=i;
                    break;
                }
            }
            vector<bool> done(n+1,false);
            ind_x.pb(start);
            done[start]=true;

            FOR(i,0,n-1)
            {
                FOR(j,0,graph[start].size())
                {
                    if(done[graph[start][j]]==false)
                    {
                        ind_x.pb(graph[start][j]);
                        done[start]=true;
                        start=graph[start][j];
                    }
                }
            }

            vector<ll> cst(6,0);
            vector<vector<ll>> choices;
            choices.pb(vector<ll>{1,2,3});
            choices.pb(vector<ll>{1,3,2});
            choices.pb(vector<ll>{2,1,3});
            choices.pb(vector<ll>{3,1,2});
            choices.pb(vector<ll>{2,3,1});
            choices.pb(vector<ll>{3,2,1});
            FOR(i,0,6)
            {
                // cout<<i<<" ";
                FOR(j,0,n)
                {
                    ll curr=choices[i][j%3];
                    if(curr==1)
                    {
                        cst[i]+=inp1[ind_x[j]-1];
                    }
                    else if(curr==2)
                    {
                        cst[i]+=inp2[ind_x[j]-1];
                    }
                    else
                    {
                        cst[i]+=inp3[ind_x[j]-1];                        
                    }
                    
                }
                // cout<<cst[i]<<endl;
            }
            ll mini=cst[0];
            ll idx=0;
            FOR(i,0,6)
            {
                if(cst[i]<mini)
                {
                    mini=cst[i];
                    idx=i;
                }
            }
            cout<<mini<<endl;
            vector<ll> ans(n+1  ,0);
            FOR(i,0,n)
            {
               
                    ans[ind_x[i]]=choices[idx][i%3];               
            }
            FOR(i,0,n)
            {
               cout<<ans[i+1]<<" ";               
            }
            cout<<endl;


        }
        


    }
    return 0;
}