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
#define     SACHITJAGGI      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            cout.flush();
#define endl '\n'         
#define     all(x)           (x).begin(),(x).end()
#define     setcount(x)      __builtin_popcountll(x)
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

inline int add(int a,int b) { return (a%MOD + b%MOD + MOD)%MOD; }
inline int mul(int a,int b) { return (a%MOD * b%MOD + MOD)%MOD; }
inline int sub(int a,int b) { return (a%MOD - b%MOD + MOD)%MOD; }

template<class T> void dispvector(vector<T> v){ for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n"; }

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
    SACHITJAGGI
    long t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        unordered_set<ll> strg;
        FOR(i,0,n)
        {
            cin>>arr[i];
            strg.insert(arr[i]);
        }
        vector<ll> a;
        
        FOR(i,1,n+1)
        {
            if(strg.count(i)==0)
            {
                a.pb(i);
            }
        }
        sort(all(a));
        // reverse(all(a));

        int met=0;
        unordered_set<ll> done;
        vector<ll> answ(n,-1);
          FOR(i,0,n)
        {
            if( strg.count(i+1)==0 && done.count(arr[i])==0)
            {
                met++;
                answ[i]=arr[i];
                done.insert(arr[i]);
            }
            
        }

        // dispvector<ll>(answ);

        int prev=0;
        
        vector<ll> idx_lft;

        FOR(i,0,n)
        {
            if(answ[i]!=-1) continue;

            if( done.count(arr[i])==0)
            {
                met++;
                answ[i]=arr[i];
                done.insert(arr[i]);
            }
            else
            {
                idx_lft.pb(i);
            }

           
        }

      

        prev=-1;
        reverse(all(a));
        FOR(i,0,idx_lft.size())
        {
            if(a[i]==idx_lft[i]+1)
            {
                // swap with prev
                
                

                swap(a[i],a[i+1]);
                
            }
            
            answ[idx_lft[i]]=a[i];
            prev=idx_lft[i];
            
        }
        
         cout<<met<<endl;
        dispvector<ll>(answ);

        // vector<pll> lft1;
        // unordered_set<ll> lft2;
        // FOR(i,0,a.size())
        // {
        //     lft2.insert(a[i]);
        // }
        // // vector<ll> lft3;

        // FOR(i,0,n)
        // {
        //     if(answ[i]==-1)
        //     {   
        //         if(lft2.count(i+1)==1)
        //         {
        //             lft1.pb({0,i});
        //         }
                
        //     }
        // }
        // sort(all(lft1));
        // ll idx=0;
        // // cout<<"** "<<endl;
        // // FOR(i,0,lft1.size())
        // // {
        // //     cout<<lft1[i].f<<" "<<lft1[i].s<<endl;
        // // }
        // // cout<<"** "<<endl;
        
        // while(lft1.size()!=1 &&idx<lft1.size())
        // {
        //     if(lft1[idx].f==0)
        //     {
        //         // 
        //         answ[lft1[idx].s]=(lft1[(idx+1)%lft1.size()].s)+(1);

        //         done.insert(answ[lft1[idx].s]); 
        //     }
            
        //     idx++;
        //     //  dispvector<ll>(answ);

        // }
        // // dispvector<ll>(answ);

        // ll lfsdf=n;
        // idx=0;

        // // for(auto it:done) cout<<it<<" *&* ";
        // // cout<<endl;

        // while(idx<n)
        // {
        //     while(idx< n && answ[idx]!=-1) idx++;

        //     if(idx==n)
        //          break;
        //     // cout<<"(( "<< idx<<" "<<answ[idx]<<endl;
        //     // cout<<idx<<" ** "<<lfsdf<<endl;
            
            
        //     while(done.count(lfsdf)==1 ) {
        //         lfsdf--;
               
        //     }
        //     // cout<<idx<<" ** "<<lfsdf<<endl;
        //     answ[idx]=lfsdf;
        //     done.insert(lfsdf);
        //     lfsdf--;
        //     idx++;
            
        // }
        
        // FOR(i,0,n) cout<<arr[i]<<" ";
        // cout<<endl;

    }
    return 0;
}
