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


ll v9=INT64_MAX;

struct segmenttree{

    ll sz=1;

   vector<ll> segtree;
    
   vector<ll> val;

   ll modify_operation(ll a,ll b)
   {
       return (a | b) ;
   }
   

   ll calc_operation(ll a,ll b)
   {
       return (a & b) ;
   }


   void apply_mod_operation(ll&a , ll b)
   {
       a = modify_operation(a, b);
   }



    void build(ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            val[x] = 1;
            return;
        }
        ll mid = (lx + rx) / 2;
        build(2 * x + 1, lx, mid);
        build(2 * x + 2,  mid,rx);
        val[x] = (val[2 * x + 1]+val[2 * x + 2]);

    }
    
    void init(ll n)
    {
        sz = 1;
        while (sz<n)
        {
            sz = sz * 2;
        }
        segtree.assign(2 * sz, 0);
        val.assign(2 * sz, 0);
        // build(0, 0, sz);

    }


    ll get_segment(ll l,ll r,ll x,ll lx ,ll rx)
    {

        //  get val from l to r-1
        // we currently store in x val from lx to rx-1
        

        if(l>=rx || r<=lx )
        {
            // don't intersect
            return v9;
        }

        if(l<=lx && rx<=r)
        {
            //  complete intersection
            // cout<<lx<<" "<<rx<<" "<<x<<endl;
            // cout<<" && "<<val[x]<<endl;
              return val[x];
        }
        
        ll mid = (lx + rx) / 2;

        ll v1 = get_segment(l, r, 2 * x + 1, lx, mid);

        ll v2 = get_segment(l, r, 2 * x + 2,  mid,rx);

        ll res = calc_operation(v1, v2);
        // cout<<v1<<" "<<v2<<" "<<res<<" ";
        apply_mod_operation(res, segtree[x]);
        // cout<<res<<endl;
        return res;
    }

    ll get_segment(ll l,ll r)
    {
        return get_segment(l , r , 0 , 0 , sz);
    }

    
    
    void multiply(ll l, ll r,ll v,ll x,ll lx ,ll rx)
    {

        if(l>=rx || r<=lx)
        {
            // don't intersect
            return;
        }

        if(l<=lx && rx<=r)
        {
            //  complete intersection
            apply_mod_operation(segtree[x], v);
            if(rx-lx!=1)
            {
            val[x]=(val[2*x+1]&val[2*x+2]);
            }
            else
            {
                val[x]=0;
            }
            
            apply_mod_operation(val[x],segtree[x]);

            return;
        }
        
        ll mid = (lx + rx) / 2;
        
        // left child             + 
        multiply(l, r, v, 2 * x + 1, lx, mid);

        //  right child
        multiply(l, r, v, 2 * x + 2, mid, rx);

        val[x] = calc_operation(val[2 * x + 1], val[2 * x + 2]);

        apply_mod_operation(val[x], segtree[x]);

        return;
        
    }

    void multiply(ll l, ll r,ll v)
    {
        multiply(l, r, v, 0, 0, sz);
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
                arr.multiply(l, r, v);

            }
            else
            {
                ll l,r;
                cin >> l >> r;
                cout<<arr.get_segment(l,r)<<endl;
            }
            // cout<<"&& *************"<<endl;
            // FOR(i,0,log2(arr.sz)+1)
            // {
            //     ll v1=pow(2,i);
            //     FOR(j,0,v1)
            //     {
            //         cout<<arr.val[v1-1+j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<"&& *************"<<endl;


        }
    }
    return 0;
}
