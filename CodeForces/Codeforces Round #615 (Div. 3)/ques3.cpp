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
vector<ll> primeFactors(ll n)  
{  
    vector<ll> pmf,powers;
      if(n % 2 == 0)
      {
          ll curr=0;
            while (n % 2 == 0)  
            {  
            n = n/2;
            curr++;  
            }  
            pmf.pb(2);
            powers.pb(curr);
      }
  
    
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        if(n % i == 0) 
        {

          ll curr=0;
            while (n % i == 0)  
            {  
                n = n/i; 
                curr++; 
            }
            pmf.pb(i);
            powers.pb(curr);
        } 
        if(pmf.size()==2 )
        {
            if(n!=1)
            {
                ll a=pow(pmf[0],powers[0]);
                ll b=pow(pmf[1],powers[1]);
                ll c=n;
                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
            }
            else
            {
                if(powers[0]>2)
                {
                ll a=pow(pmf[0],1);
                ll b=pow(pmf[0],powers[0]-1);
                ll c=pow(pmf[1],powers[1]);
                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
                }   
                else if(powers[1]>2)
                {
                ll a=pow(pmf[1],1);
                ll b=pow(pmf[1],powers[1]-1);
                ll c=pow(pmf[0],powers[0]);
                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
                }   
                else
                {
                    continue;
                }
                          
            }
            
        } 
        


        
    }
    if(n>2)
    {
        pmf.pb(n);
        powers.pb(1);
    }  
                
                
        if(pmf.size()==1 &&powers[0]>=6)
        {
                vector<ll> answe;
                ll a=pow(pmf[0],1);
                ll b=pow(pmf[0],2);
                ll c=pow(pmf[0],powers[0]-3);
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;

        }
        if(pmf.size()==2 )
        {
            
                if(powers[0]>2)
                {
                ll a=pow(pmf[0],1);
                ll b=pow(pmf[0],powers[0]-1);
                ll c=pow(pmf[1],powers[1]);
                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
                }   
                else if(powers[1]>2)
                {
                ll a=pow(pmf[1],1);
                ll b=pow(pmf[1],powers[1]-1);
                ll c=pow(pmf[0],powers[0]);
                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
                }   
                if(powers[0]==2 && powers[1]==2)
                {
                    ll a=pow(pmf[1],1);
                ll c=pow(pmf[0],1);
                ll b=(pmf[1]*pmf[0]);

                vector<ll> answe;
                answe.pb(a);
                answe.pb(b);
                answe.pb(c);
                return answe;
                }
                
                
                          
            
            
        }
                vector<ll> answe;
                return answe;



     
      
}  


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
        cin>>n;
        vector<ll> ans=primeFactors(n);
        if(ans.size()==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        }
        
    }
    return 0;
}