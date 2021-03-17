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
        segtree.assign(2 * sz, 0);
    }

    void build(vector<ll>&a, ll x, ll lx ,ll rx)
    {

        if(rx-lx==1)
        {
            // leaf node
            if(lx<a.size())
            {
                segtree[x] = 1;
            }
            return;
        }
        ll mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid,rx);
        segtree[x] = segtree[2 * x + 1] + segtree[2 * x + 2];


    }

    void build(vector<ll>&a)
    {
        build(a, 0, 0, sz);
    }


    ll get_segment(ll l, ll r,ll x,ll lx ,ll rx)
    {

        //  get sum from l to r-1
        // we currently store in x sum from lx to rx-1
        

        if(l>=rx || r<=lx)
        {
            // don't intersect
            return 0;
        }

        if(l<=lx && rx<=r)
        {
            //  complete intersection
             return segtree[x]; 
        }
        
        ll mid = (lx + rx) / 2;
        // left child             +                        right child       
        return    get_segment(l, r, 2 * x + 1, lx, mid) + get_segment(l, r, 2 * x + 2, mid,rx);
    

        
    }
    
    ll get_segment(ll l, ll r)
    {
        return get_segment(l, r, 0, 0, sz);
    }

    void set(ll idx, ll val,ll x,ll lx, ll rx)
    {
        if(rx-lx==1)
        {
            segtree[x] = val;
            return ;
        }
        ll mid = (lx + rx) / 2;
        if (idx < mid)
        {
            // left child
            set(idx, val, 2 * x + 1, lx, mid);
        }
        else
        {
            // right child 
            set(idx, val, 2 * x + 2, mid,rx);

        }
        segtree[x] = segtree[2*x+1] + segtree[2*x+2];
        return;
    }

    void set(ll idx, ll val)
    {
         set(idx, val, 0, 0, sz);
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
        ll n;
        cin >> n;
        vector<ll> inp(2*n);
        segmenttree arr;
        arr.init(2*n);
        FOR(i, 0, 2*n)
        {
         cin >> inp[i];
         
        }
        vector<bool> vst(n + 1, false);
        vector<ll> prev(n + 1, false);
        vector<ll> ans(n + 1, 0);
        // ll v1 = 0;
        // FOR(i, 0, log2(arr.sz)+1)
        // {
            
        //     v1 = pow(2, i);
        //     FOR(j,0,pow(2,i))
        //     {
        //         cout << arr.segtree[v1-1 + j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << " &&&&&&& " << endl;

        FOR(i,0,2*n)
        {
            if(vst[inp[i]]==true)
            {
                ll left = prev[inp[i]];
                ll right = i;

                arr.set(left, 0);
                ans[inp[i]]+= arr.get_segment(left, right);

                // cout << " &&&&&&& " << inp[i]<<" "<<left<< endl;

                //  FOR(i, 0, log2(arr.sz)+1)
                // {
                    
                //     v1 = pow(2, i);
                //     FOR(j,0,pow(2,i))
                //     {
                //         cout << arr.segtree[v1-1 + j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << " &&&&&&& " << endl;
            }
            else
            {
                vst[inp[i]] = true;
                prev[inp[i]] = i;
                arr.set(i, 1);

            }
        }
        
         vector<bool> vst1(n + 1, false);
        vector<ll> prev1(n + 1, false);
        // ll v1 = 0;
        // FOR(i, 0, log2(arr.sz)+1)
        // {
            
        //     v1 = pow(2, i);
        //     FOR(j,0,pow(2,i))
        //     {
        //         cout << arr.segtree[v1-1 + j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << " &&&&&&& " << endl;
        // FOR(i,1,n+1)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        reverse(inp.begin(), inp.end());
        arr.init(2*n);
        FOR(i, 0, 2 * n)
        {
            if(vst1[inp[i]]==true)
            {
                ll left = prev1[inp[i]];
                ll right = i;

                arr.set(left, 0);

                ans[inp[i]]+= arr.get_segment(left, right);


                // cout << " &&&&&&& " << inp[i]<<" "<<left<< endl;

                //  FOR(i, 0, log2(arr.sz)+1)
                // {
                    
                //     v1 = pow(2, i);
                //     FOR(j,0,pow(2,i))
                //     {
                //         cout << arr.segtree[v1-1 + j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << " &&&&&&& " << endl;
            }
            else
            {
                vst1[inp[i]] = true;
                prev1[inp[i]] = i;
                arr.set(i, 1);

            }
        }
        FOR(i,1,n+1)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        // arr.build(inp);
    }
    return 0;
}
