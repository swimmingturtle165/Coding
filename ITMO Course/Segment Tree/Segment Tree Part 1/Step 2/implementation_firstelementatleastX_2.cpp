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
#define endl '\n'         

   
struct segmenttree{

    ll sz=1;

    vector<ll> segtree;

    void init(ll n)
    {
        sz = 1;
        while (sz<n)
        {
            sz = sz * 2;
        }
        segtree.assign(2 * sz, -1);
    }

    void build(vector<ll>&a, ll x, ll lx ,ll rx)
    {

        if(rx-lx==1)
        {
            // leaf node
            if(lx<a.size())
            {
                segtree[x] = a[lx];
            }
            return;
        }
        ll mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid,rx);
        segtree[x] = max(segtree[2 * x + 1] , segtree[2 * x + 2]);


    }

    void build(vector<ll>&a)
    {
        build(a, 0, 0, sz);
    }

    void set(ll idx, ll val,ll x,ll lx, ll rx)
    {
        if(rx-lx==1)
        {
            // leaf node
            segtree[x] = val;
            return;
        }
        ll mid = (lx + rx) / 2;
        
        if(idx<mid)
        {
            // left child
            set(idx, val, 2 * x + 1, lx, mid);
        }
        else
        {
            // right child 
            set(idx, val, 2 * x + 2, mid,rx);

        }
        segtree[x] = max(segtree[2 * x + 1] , segtree[2 * x + 2]);

    }

    void set(ll idx, ll val)
    {
        set(idx, val, 0, 0, sz);
    }

    ll get_segment(ll val,ll idx,ll x,ll lx ,ll rx)
    {

        //  get sum from l to r-1
        // we currently store in x sum from lx to rx-1
        

        
        if(segtree[x]<val || rx<=idx)
        {
            return -1;
        }
        if(rx-lx==1)
        {
            return lx;
        }
        ll left = segtree[2 * x + 1];
        ll right = segtree[2 * x + 2];
        ll mid = (lx + rx) / 2;
        
        ll res= get_segment(val,idx, 2 * x + 1, lx, mid);
        
        if(res==-1)
        {
            res=get_segment(val,idx, 2 * x + 2, mid,rx);
        }

        return res;
    }
    
    ll get_segment(ll val,ll idx)
    {
        return get_segment(val ,idx,0, 0, sz);
    }
};

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> inp(n);
        segmenttree arr;
        arr.init(n);
        FOR(i, 0, n)
        {
         cin >> inp[i];
        }
        arr.build(inp);
        while (m--)
        {
            ll op;
            cin >> op;
            if(op==1)
            {
                ll idx, val;
                cin >> idx >> val;
                arr.set(idx, val);
            }
            else
            {
                ll val,idx;
                cin >> val>>idx;
               cout<< arr.get_segment(val,idx)<<endl;

            }
        }
    }
    return 0;
}
