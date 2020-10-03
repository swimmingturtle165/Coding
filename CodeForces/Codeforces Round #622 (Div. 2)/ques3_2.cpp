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
    ll n;
    cin>>n;
    vector<ll> inp(n),left(n),right(n);
    
    vector<ll> answ(n);
    FOR(i,0,n)
    {
       cin>>inp[i];        

    }
    stack<ll> st;
    FOR(i,0,n)
    {
        while(st.size()!=0 && inp[i]<=inp[st.top()])
        {
            st.pop();
        }
        if(st.size()==0)
        {
            left[i]=-1;
        }
        else
        {
            left[i]=st.top();
        }
        st.push(i);
        
    }
    while(st.size()!=0)
    {
        ll curr=st.top();
        left[curr]=-1;
        st.pop();
    }
    FOR(i,0,n)
    {
        while(st.size()!=0 && inp[n-1-i]<=inp[st.top()])
        {
            st.pop();
        }
        if(st.size()==0)
        {
            right[n-1-i]=-1;
        }
        else
        {
            right[n-1-i]=st.top();
        }
        st.push(n-1-i);
        // cout<<i<<" "<<st.top()<<" "<<right[n-1-i]<<endl;

        
    }
    while(st.size()!=0)
    {
        ll curr=st.top();
        right[curr]=-1;
        st.pop();
    }
    dispvector<ll>(left);
    dispvector<ll>(right);
    FOR(i,0,n)
    {
        if(left[i]==-1)
        {
            left[i]=inp[i]*(i+1);
        }
        else
        {
            left[i]=left[left[i]]+inp[i]*(i-left[i]);
        }
        
    }
    FOR(i,0,n)
    {
        if(right[n-1-i]==-1)
        {
            right[n-1-i]=inp[n-1-i]*(i+1);

        }
        else
        {
            right[n-1-i]=inp[n-1-i]*(1+(n-i)-right[n-1-i])+right[right[n-i-1]];
        }
        
    }
    dispvector<ll>(left);
    dispvector<ll>(right);

    ll maxi=-1;
    ll idx=0;
    FOR(i,0,n)
    {
        if(maxi<left[i]+right[i]-inp[i])
        {
        maxi=left[i]+right[i]-inp[i];
        idx=i;
        }
    }
        ll prev=inp[idx];
        answ[idx]=inp[idx];
        FOR(i,0,idx)
        {
            answ[idx-i-1]=min(inp[idx-1-i],answ[idx-i]);
        }
        FOR(i,idx+1,n)
        {
            answ[i]=min(answ[i-1],inp[i]);
        }
    dispvector<ll>(answ);
    
    
    return 0;
}
