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
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

struct segmenttree{

    ll sz=1;

    vector<ll> segtree;
    vector<ll> mins;


    void init(ll n)
    {
        sz = 1;
        while (sz<n)
        {
            sz = sz * 2;
        }
        segtree.assign(2 * sz, 0);
        mins.assign(2 * sz, 0);

    }

   


    ll get_segment(ll l,ll r,ll x,ll lx ,ll rx)
    {

        //  get sum from l to r-1
        // we currently store in x sum from lx to rx-1
        

        if(l>=rx || r<=lx )
        {
            // don't intersect
            return INT_MAX;
        }

        if(l<=lx && rx<=r)
        {
            //  complete intersection
              return mins[x];
        }
        
        ll mid = (lx + rx) / 2;
        
        // left child   
       ll m1= get_segment(l, r, 2 * x + 1, lx, mid);

        //  right child
       ll m2=get_segment(l, r, 2 * x + 2, mid, rx);
       
       return min(m1,m2)+segtree[x];
    }

    ll get_segment(ll l,ll r)
    {
        return get_segment(l,r, 0, 0, sz);
    }

    
    
    void add(ll l, ll r,ll v,ll x,ll lx ,ll rx)
    {

        if(l>=rx || r<=lx)
        {
            // don't intersect
            return;
        }

        if(l<=lx && rx<=r)
        {
            //  complete intersection
                segtree[x]+=v;
                mins[x] += v;
                return;
        }
        
        ll mid = (lx + rx) / 2;
        
        // left child             + 
        add(l, r, v, 2 * x + 1, lx, mid);
        //  right child
        add(l, r, v, 2 * x + 2, mid, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + segtree[x];

        return;
    }

    void add(ll l, ll r,ll v)
    {
        add(l, r, v, 0, 0, sz);
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
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        segmenttree arr;
        arr.init(n);
        while(m--)
        {
            ll op;
            cin >> op;
            if(op==1)
            {
                ll l, r, v;
                cin >> l >> r >> v;
                arr.add(l, r, v);

            }
            else
            {
                ll l,r;
                cin >> l >> r;
                cout<<arr.get_segment(l,r)<<endl;
            }
            
        }
    }
    return 0;
}
