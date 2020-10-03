#include<bits/stdc++.h>
using namespace std;

typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<int,int>      pint;
#define     FOR(i,a,b)       for(int i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(int i=b;i>=a;i--)
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
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(0)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
int nCrModpDP(int n, int r) 
{ 
    
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (int i = 1; i <= n; i++) 
    { 
        
        for (int j = min(i, r); j > 0; j--) 
  
            
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
int ntopowermandMod(int n,int m,int mod_v)
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
        int val=ntopowermandMod(n,m/2,mod_v);
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
int ntopowerm(int n,int m)
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
        int val=ntopowerm(n,m/2);
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
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       vector<int> sta;
  
       for(int i = 0 ; i <k;i++)
       {
           int temp;
           cin>>temp;
           
           sta.pb(temp);
       } 
       sort(sta.begin(),sta.end());
       int ans=0;
       for(int i = 0 ; i <sta.size()-1;i++)
       {

          ll cnt=1;
          ll st=sta[i];
          ll end=sta[i];
          while(i<sta.size()-1 && sta[i+1]==sta[i]+1)
          {
              
              i++;
              end++;
              cnt++;
          }
          if(st==1)
          {
              continue;
          }
          else if(end==n && cnt%2==0)
          {
              ans++;
          }
          else if(end!=n && cnt%2==1)
          {
              ans++;
          }
          

       } 
       cout<<ans<<endl;
   }
    return 0;
}