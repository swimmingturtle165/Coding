#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef      long long     ll;
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
        vector<vector<pll>> graph1(n+1,vector<pll>());

        vector<ll> dp(n+1,INT64_MAX);
        vector<ll> maxi(n+1,0);
        vector<bool> visited(n+1,false);

         vector<ll> dp1(n+1,INT64_MAX);
        vector<ll> maxi1(n+1,0);
        vector<bool> visited1(n+1,false);

        dp[0]=dp[1]=0;

        dp1[0]=dp1[n]=0;

        
        FOR(i,0,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].pb({b,c});
            graph1[b].pb({a,c});

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
                if(dp[dst]>dp[idx]+price )
                {
                    // cout<<"**"<<endl;
                    ll k1=dp[idx]+price;
                    dp[dst]=k1;
                    maxi[dst]=max(maxi[idx],price);
                    pq.push({dp[dst],dst});
                }
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;

            }

        }
        pq.push({0,n});
        while(pq.size()>0)
        {
            pll curr=pq.top();
            pq.pop();
            ll idx=curr.s;
            ll cst=curr.f;

            if(visited1[idx])
            {
                continue;
            }
            visited1[idx]=true;

            for(auto v:graph1[idx])
            {
                ll dst=v.f;
                ll price=v.s;
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;
                if(dp1[dst]>dp1[idx]+price )
                {
                    // cout<<"**"<<endl;
                    ll k1=dp1[idx]+price;
                    dp1[dst]=k1;
                    maxi1[dst]=max(maxi1[idx],price);
                    pq.push({dp1[dst],dst});
                }
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;

            }

        }
        ll ans=INT64_MAX;
        FOR(i,1,n+1)
        {
            // cout<<i<<" "<<dp[i]<<" "<<maxi[i]<<" "<<dp1[i]<<" "<<maxi1[i]<<endl;
            ans=min(ans,(dp[i]+dp1[i]) - ((max(maxi[i],maxi1[i])+1ll)/2ll));
            // cout<<ans<<" "<<(dp[i]+dp1[i]) <<" "<< ((max(maxi[i],maxi1[i])+1ll)/2ll)<<endl;
        }
        cout<<ans<<endl;
        // dispvector<ll>(dp);
        // dispvector<ll>(maxi);

        // cout<<maxi[n]<<" "<<dp[n]<<endl;
        // cout<<dp[n]<<endl;
    }
    return 0;
}
