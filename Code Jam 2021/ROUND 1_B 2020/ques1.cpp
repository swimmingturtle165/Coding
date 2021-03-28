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

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    FastIO;
    long t;
    cin>>t;
    ll v=0;
    while(t--)
    {
        v++;
        cout<<"Case #"<<v<<": ";
        ll x,y;
        cin>>x>>y;
        ll ox=x,oy=y;
        x=abs(x);
        y=abs(y);
        ll pasd=(x&y);
        ll psd=(x|y);
        ll k1=log2(psd+1);
        
       
         if(pasd==0 && k1-ll(k1)==(ld)0)
        {
            char h='*',vt='*';
            if(ox>0)
            {
                h='E';
            }
            else
            {
                h='W';
            }
            if(oy>0)
            {
                vt='S';
            }
            else
            {
                vt='N';
            }
            
            
            ll v=x;
            vector<char> strg(64,'@');
            ll curr=63;
            while(v>0)
            {
                if(v%2==1)
                strg[curr]=h;   
                v=v/2;
                curr--;
            }
            v=y;
            curr=63;
            while(v>0)
            {
                if(v%2==1)
                strg[curr]=vt;
                curr--;

            }
            reverse(strg.begin(),strg.end());
            FOR(i,0,64)
            {
                if(strg[i]!='@')
                {
                    cout<<strg[i];
                }
            }
            cout<<endl;

            
        }
        else 
        {

            bool flg=false;
            ll v=log2(x);
            FOR(i,v,32)
            {
            char h='*',vt='*';

            if(ox>0)
            {
                h='W';
            }
            else
            {
                h='E';
            }
            if(oy>0)
            {
                vt='S';
            }
            else
            {
                vt='N';
            }
                ll v=ntopowerm(2,v);
                if(v<x)
                {
                    continue;
                }
                else 
                {
                    ll k=v-x;
                    ll pasd1=(k&y);
                    ll psd1=(k|y);
                    ll k2=log2(psd1+1);
                    
                    if(pasd1==0 && k2-ll(k2)==(ld)0)
                    {
                        
                        
                        
                                    flg=true;
                                    ll v=x;
                        vector<char> strg(64,'@');
                        ll curr=63;
                        while(v>0)
                        {
                            if(v%2==1)
                            strg[curr]=h;   
                            v=v/2;
                            curr--;
                        }
                        v=y;
                        curr=63;
                        while(v>0)
                        {
                            if(v%2==1)
                            strg[curr]=vt;
                            curr--;

                        }
                        reverse(strg.begin(),strg.end());
                        FOR(i,0,64)
                        {
                            if(strg[i]!='@')
                            {
                                cout<<strg[i];
                            }
                            else
                            {
                                if(h=='S')
                                {
                                    cout<<'N';
                                }
                                else
                                {
                                    cout<<'S';
                                }
                                break;
                                
                            }
                            
                        }
                        cout<<endl;
                    }
                }
            }
            if(flg==false)
            {
            char h='*',vt='*';

            if(ox>0)
            {
                h='E';
            }
            else
            {
                h='W';
            }
            if(oy>0)
            {
                vt='N';
            }
            else
            {
                vt='S';
            }
                    FOR(i,v,32)
                {
                    ll v=ntopowerm(2,v);
                    if(v<x)
                    {
                        continue;
                    }
                    else 
                    {
                        ll k=v-y;
                        ll pasd1=(k&x);
                        ll psd1=(k|x);
                        ll k2=log2(psd1+1);
                        
                        if(pasd1==0 && k2-ll(k2)==(ld)0)
                        {
                            
                            
                            
                            flg=true;
                            ll v=x;
                            vector<char> strg(64,'@');
                            ll curr=63;
                            while(v>0)
                            {
                                if(v%2==1)
                                strg[curr]=h;   
                                v=v/2;
                                curr--;
                            }
                            v=y;
                            curr=63;
                            while(v>0)
                            {
                                if(v%2==1)
                                strg[curr]=vt;
                                curr--;

                            }
                            reverse(strg.begin(),strg.end());
                            FOR(i,0,64)
                            {
                                if(strg[i]!='@')
                                {
                                    cout<<strg[i];
                                }
                                else
                                {
                                    if(vt=='N')
                                    {
                                        cout<<'S';
                                    }
                                    else
                                    {
                                        cout<<'W';
                                    }
                                    break;
                                    
                                }
                                
                            }
                            cout<<endl;
                        }
                    }
                }
            }
            if(flg==false)
            {
                cout<<"IMPOSSIBLE"<<endl;
            }
        }
       
    }
    return 0;
}
