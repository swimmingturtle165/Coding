#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef      int    ll;
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
  
struct segmentTree{

    ll sz=1;
    ll neutralElement=0;
    vector<ll> sgmt;

    ll operation(ll a1,ll a2)
    {
        return gcd(a1,a2);
    }

    void build(int left,int right,int x,vector<ll> &arr)
    {
        if(right-left==1)
        {
            // leaf node
            if(left<arr.size())
            {
                sgmt[x]=arr[left];
            }
            return;
        }
        ll mid=(left+right)/2;
        build(left,mid,2*x+1,arr);
        build(mid,right,2*x+2,arr);
        sgmt[x]=operation(sgmt[2*x+1],sgmt[2*x+2]);
        return;

    }
    
    void initialize(vector<ll> &arr)
    {
        ll n=arr.size();
        while(sz<n)
        {
            sz=(2ll*sz);
        }
        // cout<<sz<<endl;
        sgmt.assign(2*sz,neutralElement);

        build(0,sz,0,arr);

    }   

    ll getVal(int left,int right,int x,int lx,int rx)
    {
        // sgmt[x] has value to answer from [lx,rx)
        // we need to find from [left,right)
        // ll mid=(lx+rx)/2
        // 2*x+1 stores value from [left,mid)
        // 2*x+2 stores value from [mid,right) 

        if(lx>=right || rx<=left)
        {
            // out of bounds
            return neutralElement;
        }
        if(lx>=left && right>=rx)
        {
            // complete intersection
            return sgmt[x];
        }
        ll mid=(lx+rx)/2;
        ll lftAns=getVal(left,right,2*x+1,lx,mid);
        ll rgtAns=getVal(left,right,2*x+2,mid,rx);
        return operation(lftAns,rgtAns);


    }

    void update(int val,int idx,int x,int lx,int rx)
    {
         // sgmt[x] has value to answer from [lx,rx)
        // we need to find from [left,right)
        // ll mid=(lx+rx)/2
        // 2*x+1 stores value from [left,mid)
        // 2*x+2 stores value from [mid,right) 

        if(rx-lx==1)
        {
            sgmt[x]=val;
            return ;
        }

        if(idx<lx && rx>=idx)
        {
            return;
        }

        ll mid=(lx+rx)/2;
        
        if(idx<mid)
        update(val,idx,2*x+1,lx,mid);
        else
        update(val,idx,2*x+2,mid,rx);

        sgmt[x]=operation(sgmt[2*x+1],sgmt[2*x+2]);
    }


};

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
        vector<ll> arr(2*n);
        ll g=0;
        FOR(i,0,n)
        {
            cin>>arr[i];
            g=gcd(g,arr[i]);
            arr[i+n]=arr[i];
        }
        segmentTree strg;

        strg.initialize(arr);

        ll lft=0,rgt=n;
        while(lft<rgt)
        {
            ll mid=(lft+rgt)/2;

            ll v=0;
            FOR(i,0,n)
            {
                if(strg.getVal(i,i+mid,0,0,strg.sz)==g)
                {
                    v++;
                }
            }
            if(v!=n)
            {
                lft=mid+1;
            }
            else
            {
                rgt=mid;
            }
        }
        cout<<rgt-1<<endl;



    }
    return 0;
}