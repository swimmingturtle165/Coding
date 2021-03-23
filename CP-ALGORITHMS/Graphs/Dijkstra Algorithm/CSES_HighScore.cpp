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
 
 
void dfs(int curr,vector<bool>& conn, vector<vector<pll>>& graph1)
{

    if(conn[curr])
    {
        return;
    }
    conn[curr]=true;
    for(auto it:graph1[curr])
    {
        dfs(it.first,conn,graph1);
    }

}
 
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

        vector<ll> dp(n+1,INT64_MIN);
        vector<ll> maxi(n+1,0);
        vector<bool> visited(n+1,false);

        vector<bool> conn(n+1,false);

 
        

        FOR(i,0,m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].pb({b,c});
            graph1[b].pb({a,c});

        }
        dfs(n,conn,graph1);
        // FOR(i,0,n+1)
        // {
        //     cout<<i<<" "<<conn[i]<<endl;
        // }
        // check for +ve weight cycle
        priority_queue<pll> pq;
 
        pq.push({0,1});
        ll ans=0;
        while(pq.size()>0)
        {
            ans++;
            
            pll curr=pq.top();
            pq.pop();
            ll idx=curr.s;
            ll cst=curr.f;
            // cout<<idx<<" "<<cst<<endl;
             if(visited[idx] &&   dp[idx]<cst)
            {
                // cout<<idx<<" "<<dp[idx]<<" "<<cst<<endl;

                // cout<<"**"<<endl;
                // checks for a positive cycle

                if(conn[idx])
                {
                cout<<-1<<endl;
                return 0;
                }
                else
                {
                    continue;
                }
                
                
            }
            else if(visited[idx] && dp[idx]>=cst)
            {
                // cout<<idx<<" "<<dp[idx]<<" "<<cst<<endl;
                continue;
            }
            
            dp[idx]=cst;
            visited[idx]=true;
 
            for(auto v:graph[idx])
            {
                ll dst=v.f;
                ll price=v.s;
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;
                if(dp[dst]<=dp[idx]+price )
                {
                    // cout<<"**"<<endl;
                    ll k1=price+dp[idx];
                    // dp[dst]=k1;
                    pq.push({k1,dst});
                }
                // cout<<dst<<" "<<price<<" "<<idx<<" "<<dp[idx]<<" "<<dp[dst]<<" "<<maxi[dst]<<endl;
 
            }
 
        }
        // dispvector<ll>(dp);
        // dispvector<ll>(maxi);
 
        // cout<<maxi[n]<<" "<<dp[n]<<endl;
        // cout<<dp[n]<<endl;
        cout<<dp[n]<<endl;
        // FOR(i,0,n) cout<<dp[i+1]<<" ";
 
        // cout<<endl;
    }
    return 0;
}