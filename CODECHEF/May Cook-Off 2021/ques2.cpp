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
#define     flush            cout.flush();
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
  
 

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll g=2;
        if(y%x!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            y=y/x;
            vector<ll> strg;
            ll tm=y;
            while(tm>0)
            {
                strg.pb(tm%g);
                tm=tm/g;
            }
            reverse(strg.begin(),strg.end());
            ll start=0;
            // for(int i = 0;i<strg.size();i++)
            // {
            //     cout<<strg[i]<<" ";
            // }
            // cout<<endl;
            for(int i = 0 ; i < strg.size();i++)
            {
                if(strg[i]==0 || (i>0 && strg[i]<strg[i-1]) )
                {
                    for(int j = start+1;j<=i;j++)
                    {
                        strg[j]++;
                    }
                    strg[i]++;
                    strg[start]--;
                    if(strg[start]==0)
                    {
                        start++;
                    }
                }
                if(i>0 && i!=strg.size()-1 && strg[i-1]!=0 && strg[i]-strg[i-1]>1)
                {
                    strg[i]--;
                    strg[i+1]+=2;
                }
                
            }
            bool flg=true;
            for(int i = 0;i<strg.size();i++)
            {
                if(i!=0 && (strg[i]-strg[i-1]>1 || strg[i]<strg[i-1]) )
                {
                    flg=false;
                }
            }
            // for(int i = 0;i<strg.size();i++)
            // {
            //     cout<<strg[i]<<" ";
            // }
            // cout<<endl;
            if(flg)
            {
                ll cnt=0;
                ll maxi=0;
                for(int i = 0 ; i <strg.size();i++)
                {
                    maxi=max(maxi,strg[i]);
                    cnt+=strg[i];
                }
                if(maxi==1)
                {
                    cout<<cnt<<endl;
                }
                else
                {
                    cout<<cnt+1<<endl;
                }
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        
        
        
    }
    return 0;
}
