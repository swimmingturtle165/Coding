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


struct segmentTree{

    ll sz=1;
    ll neutralElement=0;
    vector<ll> sgmt;

    ll operation(ll a1,ll a2)
    {
        return (a1+a2);
    }

    void build(int left,int right,int x,vector<ll> &arr)
    {
        if(right-left==1)
        {
            // leaf node
            if(left<arr.size())
            {
                sgmt[x]=1;
            }
            else sgmt[x]=0;

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

    ll update(int val,int idx,int x,int lx,int rx)
    {
         // sgmt[x] has value to answer from [lx,rx)
        // we need to find from [left,right)
        // ll mid=(lx+rx)/2
        // 2*x+1 stores value from [left,mid)
        // 2*x+2 stores value from [mid,right) 

        if(rx-lx==1 && val==0)
        {
            sgmt[x]=0;
            return lx;
        }

       

        ll mid=(lx+rx)/2;

        ll rgt=sgmt[2*x+2];

        ll ans=0;

        if(val>=rgt)
        ans=update(val-rgt,val-rgt,2*x+1,lx,mid);
        else
        ans=update(val,idx,2*x+2,mid,rx);

        sgmt[x]=operation(sgmt[2*x+1],sgmt[2*x+2]);

        return ans;
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
        cin >> n ;
        vector<ll> inp(n);
        segmentTree arr;
        arr.initialize(inp);
         ll v=1;
        ll curr=0;
      
        arr.build(0,arr.sz,0,inp);
         
        FOR(i, 0, n)
        {
             cin >> inp[i];
        }
       
        vector<ll> ans(n);
        FORDE(i, n - 1, 0)
        {
             
            ans[i]=arr.update(inp[i],inp[i],0,0,arr.sz)+1;
           
          
        }
        FOR(i, 0, n)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
