#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
typedef     long long int    ll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);


signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;

        vector<unordered_set<int>> graph;
        graph.clear();
        
        graph.resize(n+1,unordered_set<int>());
        
        int cnt=0;

        FOR(i,0,n-1)
        {
            int u,v;
            cin>>u>>v;
            graph[u].insert(v);
            graph[v].insert(u);

        }
        bool flg=true;
        while(flg)
        {
            vector<bool> vst(graph.size(),false);
            queue<int> q;

            FOR(i,1,graph.size())
            {
                if(graph[i].size()==1)
                {
                    if(i==x)
                    {
                        flg=false;
                        break;
                    }
                    q.push(i);
                }
            } 
            if(flg==false)
            {
                break;
            }

            while(q.size()>0 )
            {
                int curr=q.front();
                // cout<<curr<<endl;
                q.pop();
                
                cnt++;
                for(auto&it:graph[curr])
                {
                    // cout<<it<<endl;
                    if(graph[it].find(curr)!=graph[it].end())
                    {
                    graph[it].erase(graph[it].find(curr));

                    }
                    
                    if(graph[it].size()==1 && flg)
                    {
                        if(it==x)
                        {
                            q.push(curr);
                            break;
                        }
                        // vst[it]=true;
                        q.push(it);
                    }
                }
                vst[curr]=true;
                graph[curr].clear();
            }
            flg=false;
        }
        // solve(graph,x,cnt);
        // cnt+=5;
        // cout<<cnt<<endl;
        if(cnt%2==0)
        {
            cout<<"Ayush"<<endl;
        }
        else
        {
            cout<<"Ashish"<<endl;
        }
        FOR(i,0,n+1)
        {
        graph[i].clear();

        }
        graph.clear();
        

     }
    return 0;
}
