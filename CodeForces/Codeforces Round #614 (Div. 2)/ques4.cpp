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

ll cpt_x,cpt_y;
bool mycmp(pair<ll,ll>a,pair<ll,ll>b)
{
    // if(abs(a.first-cpt_x)+abs(a.second-cpt_y)<abs(b.first-cpt_x)+abs(b.second-cpt_y))
    // {
    //     cpt_x=a.first;
    //     cpt_y=a.second;
    // }
    // else
    // {
    //     cpt_x=b.first;
    //     cpt_y=b.second;
    // }
    
    return (abs(a.first-cpt_x)+abs(a.second-cpt_y))<(abs(b.first-cpt_x)+abs(b.second-cpt_y));
}


signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    ll x_0,y_0,a_x,a_y,b_x,b_y,x_st,y_st,t;
    cin>>x_0>>y_0>>a_x>>a_y>>b_x>>b_y>>x_st>>y_st>>t;

    cpt_x=x_st;
    cpt_y=y_st;

    ll curr_x=x_0,curr_y=y_0;
    ll ans=0;
    vector<pair<ll,ll>> data_nos;
    ll collected=0;
    ll mini=INT_MAX,idx=-1;
    ll curr=0;
    while(collected<=t)
    {
        data_nos.pb({curr_x,curr_y});
        
        curr_x=a_x*curr_x+b_x;
        
        curr_y=a_y*curr_y+b_y;
        ll fsas=abs(curr_x-x_st)+abs(curr_y-y_st);
        if(fsas<mini)
        {
            mini=fsas;
            idx=curr;
        }
        collected+=fsas;
        curr++;
    }
    cpt_x=data_nos[curr].first;
    cpt_y=data_nos[curr].second;
    debug2(cpt_x,cpt_y);
    sort(data_nos.begin(),data_nos.end(),mycmp);
    ll curr_t=0;
    cpt_x=x_st;
    cpt_y=y_st;

    for(int i = 0 ; i <data_nos.size();i++)
    {
        ll temp=abs(data_nos[i].first-cpt_x)+abs(data_nos[i].second-cpt_y);
        if(temp+curr_t<=t)
        {
            curr_t+=temp;
            cpt_x=data_nos[i].first;
            ans++;
            cpt_y=data_nos[i].second;
        }
    }

    cout<<ans<<endl;
    return 0;
}