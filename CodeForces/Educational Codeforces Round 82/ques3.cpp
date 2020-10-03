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
#define     maxv             INT_MaX
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
        static const uint64_t FIXED_RaNDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RaNDOM);
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
        string str;
        cin>>str;
        if(str.size()==1)
        {
            cout<<"YES"<<endl;
            FOR(i,0,26)
            {
                cout<<(char)(i+'a');
            }
            cout<<endl;
            continue;
        }
        // vector<bool> done(26,false);
        bool flag  = true;
        // vector<vector<bool>> strg;
        bool strg[26][26];
        memset(strg,false,sizeof(strg));
        // FOR(i,0,26)
        // {
        //     strg.pb(vector<bool> (26,false));
        // }
        vector<int> strg_cnt(26,0);
        ll sum=0;
        FOR(i,0,str.length()-1)
        {

           
            
            if(strg[str[i]-'a'][str[i+1]-'a']==false)
            {
                strg[str[i]-'a'][str[i+1]-'a']=true;
                strg_cnt[str[i]-'a']++;
            }

            swap(str[i],str[i+1]);
            if(strg[str[i]-'a'][str[i+1]-'a']==false)
            {
                strg[str[i]-'a'][str[i+1]-'a']=true;
                strg_cnt[str[i]-'a']++;
            }
            swap(str[i],str[i+1]);
        }

        FOR(i,0,26)
        {            
            if(strg_cnt[i]>2)
            {
                flag=false;
                break;
            }
            sum+=strg_cnt[i];
        }
        if(sum>50)
        {
            flag=false;
        }
        if(flag)
        {
           
            ll starting=-1;
            FOR(i,0,26)
            {
                if(strg_cnt[i]==1)
                {
                    starting=i;
                    break;
                }
            }
            if(starting==-1)
            {
               flag=false; 
            }
            
            if(flag)
            {
                string key_pad="";
            key_pad+=(char)('a'+starting);
                vector<bool> done(26,false);
                done[starting]=true;
                FOR(i,1,26)
                {
                    
                    ll curr=-1;
                    FOR(j,0,26)
                    {
                        if(strg[starting][j]==true &&j!=starting &&done[j]==false )
                        {
                            curr=j;
                            break;
                        }
                    }
                    if(curr==-1)
                    {
                        break;                          
                    }
                    else
                    {
                        
                        key_pad+=(char)(curr+'a');
                        starting=curr;
                        done[starting]=true;
                    }
                    
                }
                cout<<"YES"<<endl;
                cout<<key_pad;
                FOR(i,0,26)
                {
                    if(done[i]==false)
                    {
                        cout<<(char)(i+'a');
                    }
                }
                cout<<endl;
            }
        }
        if(!flag )
        {
            cout<<"NO"<<endl;
        }
        
        
    }
    return 0;
}
