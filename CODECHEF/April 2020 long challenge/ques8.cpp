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

template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;


//*******************************  global variables  ************************************
vector<vector<ll>> graph;
vector<ll> cst;
ll n;
ll penalty=0;
vector<vector<vector<ll>>> dp;
vector<vector<bool>> completed;

// ********************************************************************************
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll answer(vector<ll> &ans,ll total)
{
ll  N = 0, Number;

    N=total;
    unordered_map<ll, ll,custom_hash> Counter;
    for (int i = 0; i < N; i++)
    {
        Number=ans[i];
        for (int j = 2; j * j <= Number; j++)
        {
            while (Number % j == 0)
            {
                Counter[j]++;
                Number /= j;
            }

        }
        if (Number > 1) Counter[Number]++;


    }
    
    ll Answer = 1;
    for (auto it = Counter.begin(); it != Counter.end(); it++)
    {
        Answer *= (it->second + 1);
        Answer%=MOD;
    }
        Answer%=MOD;

    return  Answer;


 
}

ll pathcost(int start,int end,vector<bool>&trav,vector<ll>&ans,ll idx,ll st_pt)
{
        ans[idx]=cst[start];
        dp[st_pt][start]=ans;
        dp[start][st_pt]=ans;
        completed[st_pt][start]=true;
        completed[start][st_pt]=true;

        if(start==end)
        {       
            return idx+1;
        }  
        if(completed[start][end]==true)
        {
            FOR(i,0,dp[start][end].size())
            {
                ans[idx]=dp[start][end][i];
                idx++;
            }
            return idx;

        }
        

    trav[start]=true;
  for(int i=0;i<graph[start].size();i++)
  {
      if(trav[graph[start][i]]==false)
      {
        ll v1=pathcost(graph[start][i],end,trav,ans,idx+1,st_pt);        
        if(v1>=0)
        {
            return v1;
        }
      }        
  } 
  trav[start]=false;    
  
  return -1; 
}
ll getcst(ll a, ll b)
{
        vector<ll> ans(n+1,1);
        ll v1=0;
    if(completed[a][b]==true)
    {
        ans= dp[a][b];
        v1=ans.size()+1;        
    }
    else
    {
        vector<bool> trav(n+1,false);
        ll idx=0;
        ll st_pt=a;
        ll cost=pathcost(a,b,trav,ans,idx,st_pt);
        if(cost==-1)
        {
            return 0;
        }
        v1=cost;
    }
    
    
    
  
    ll answe=answer(ans,v1); 
    answe=answe%MOD;
    dp[a][b]=ans;
    dp[b][a]=ans;
    completed[a][b]=true;
    completed[b][a]=true;


    return answe;
    
}

signed main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FastIO;
    long t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        penalty=0;
        
        graph.clear();
        cst.clear();
        dp.clear();
        completed.clear();

        graph.resize(n+1);
        cst.resize(n + 1);
        dp.resize(n+1,vector<vector<ll>>());
        completed.resize(n+1,vector<bool> ());
        cout<<"**"<<endl;

        cout<<completed[n][n]<<endl;
        FOR(i, 0, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        FOR(i,0,n)  cin>>cst[i+1];
        ll q;
        cin>>q;
        while(q--)
        {
            ll a,b;
            cin>>a>>b;
             cout<< getcst(a,b)<<endl;
        }

    }
    return 0;
}
