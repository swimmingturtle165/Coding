#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef     unsigned long long     ll;
typedef     long double      ld;
typedef     pair< ll, ll>      pll;
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


   


signed main(int argc, char** argv)
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    FastIO;
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        vector<vector<pll>> graph(n+1,vector<pll>());
        ll v1=INT64_MAX;
        vector<ll> dp(n+1,v1/3);
        vector<ll> maxi(n+1,0);
        vector<bool> visited(n+1,false);

        dp[0]=dp[1]=0;
        
        FOR(i,0,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].pb({b,c});
        }
        priority_queue<pll,vector<pll>,greater<pll>> pq;

        pq.push({0,1});
        
        while(pq.size()>0)
        {
            pll curr=pq.top();
            pq.pop();
            ll idx=curr.s;
            ll cst=curr.f;

            if(visited[idx])
            {
                continue;
            }
            visited[idx]=true;

            for(auto v:graph[idx])
            {
                ll dst=v.f;
                ll price=v.s;
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;
                if(dp[dst]-dp[idx]>=price+((maxi[idx]+1ll)/2ll)-((max(maxi[idx],price)+1ll)/2ll) )
                {
                    // cout<<"**"<<endl;
                    ll k1=price+((maxi[idx]+1ll)/2ll)-((max(maxi[idx],price)+1ll)/2ll);
                    k1+=dp[idx];
                    dp[dst]=k1;
                    maxi[dst]=max(maxi[idx],price);
                    pq.push({dp[dst],dst});
                }
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;

            }

        }
        // dispvector<ll>(dp);
        // dispvector<ll>(maxi);

        // cout<<maxi[n]<<" "<<dp[n]<<endl;
        cout<<dp[n]<<endl;
    }
    return 0;
}
