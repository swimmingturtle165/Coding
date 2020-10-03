#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

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


// actual code

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
        ll n;
        ld x,y;
        ll a,b;
        ll k;
        cin>>n;
        vector<ld> inp(n,-1),val(n,0);
        for(ll i = 0 ; i <n;i++)
        {
            cin>>inp[i];
        }

        sort(inp.begin(),inp.end());
        reverse(inp.begin(),inp.end());
        cin>>x>>a>>y>>b>>k;
        priority_queue<ll> fir,sec,third;
        
        ll lc=(a*b)/__gcd(a,b);
        // debug(lc);
        ll maxi=x>y?a:b;
        ll mini=a+b-maxi;
        ld maxi_inter=x>y?x:y;
        ld mini_inter=x+y-maxi_inter;
        maxi_inter/=100;
        mini_inter/=100;
        // debug2(maxi_inter,mini_inter);
        ld curr_sum=0;
        ll curr=-1;
        ll idx=0;
        for(ll i = 0;i<n;i++)
        {
            if((i+1)%lc==0)
            {
                if(sec.size()==0 && third.size()==0)
                {
                    curr_sum+= ld (maxi_inter+mini_inter)*inp[idx];
                    fir.push(inp[idx]);
                }
                else if(sec.size()!=0 &&third.size()==0)
                {
                    ll val=sec.top();
                    sec.pop();
                    sec.push(inp[idx]);
                    fir.push(val);
                    curr_sum+=ld (mini_inter)*val;
                    curr_sum+=ld (maxi_inter)*inp[idx];
                }
                else if(third.size()!=0 && sec.size()==0)
                {
                    ll val=third.top();
                    third.pop();
                    third.push(inp[idx]);
                    fir.push(val);
                    curr_sum+=ld (maxi_inter)*val;
                    curr_sum+=ld (mini_inter)*inp[idx];
                }
                else 
                {
                    ll val1=inp[idx];

                    ll val2=sec.top();
                    sec.pop();
                    
                    ll val3=third.top();
                    third.pop();

                    fir.push(val2);
                    sec.push(val3);
                    third.push(val1);

                    curr_sum+=ld (val2)*mini_inter;
                    curr_sum+=ld (val3)*(maxi_inter-mini_inter);
                    curr_sum+=ld (val1)*mini_inter;


                }
                idx++;
            }
            else if((i+1)%maxi==0)
            {
                if(third.size()==0)
                {
                    curr_sum+=ld (maxi_inter)*inp[idx];
                    sec.push(inp[idx]);
                }
                else
                {
                    ll val=third.top();
                    third.pop();
                    third.push(inp[idx]);
                    sec.push(val);
                    curr_sum+= ld(mini_inter)*inp[idx];
                    curr_sum+=ld(maxi_inter-mini_inter)*val;
                }
                    idx++;

                
            }
            else if((i+1)%mini==0)
            {
                    third.push(inp[idx]);
                    curr_sum+= ld(mini_inter)*inp[idx];
                    idx++;
            }
            if(curr_sum>=k)
            {
                curr=i+1;
                break;
            }

            
        }
        if(curr>0)
        {
            cout<<curr<<endl;

        }
        else
        {
            cout<<-1<<endl;
        }
        

        
        
    }
    return 0;
}
