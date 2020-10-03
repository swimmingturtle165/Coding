#include <bits/stdc++.h>
using namespace std;
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

void addEdge(int v1,int v2,vector<vector<int>>&graph)
{        
    graph[v1].push_back(v2);
}

void generate_ans(vector<int>& inp,unordered_map<int,int,custom_hash> &strg,int v,vector<vector<int>>&graph)
{
    int si=0;
    vector<int> answers;
    vector<bool> done;
    for(int i = 0;i<=inp.size();i++)
    {
        done.push_back(false);
    } 
    queue<int> str;
    str.push(v);
    while(str.size()>0)
    {

        int temp=str.front();
        str.pop();

        if(done[temp]==true)
        {
           break;
        }
        else
        {
            si++;
            answers.push_back(temp);
            done[temp]=true;
            for(int i = 0 ; i < graph[temp].size();i++)
            {
                str.push(graph[temp][i]);
                // done[graph[temp][i]]=true;
                // cout<<"**"<<temp<<" " <<i<<" " <<endl;
            }
        }
        

    }

    for(int i = 0 ; i < answers.size();i++)
    {
        strg[answers[i]]=si;
    }
}



int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--)
    {

        int n;
        cin>>n;
        vector<int> inp;
        unordered_map<int,int,custom_hash> strg;
        vector<vector<int>> graph;
        for(int i = 0 ;i<=n;i++)
        {
            graph.push_back( vector<int>());
        }
        
        for(int i = 1 ; i <= n;i++)
        {

            int temp;
            cin>>temp;
            inp.push_back(temp);
            
            if(i==temp)
            {
                strg.insert({temp,1});
            }
            else
            {
                addEdge(i,temp,graph);
            }       
            
        }
            //  cout<<"***"<<endl;

        for(int i = 1 ; i <=n;i++)
        {
            if(strg.find(i)==strg.end())
            {
                 generate_ans(inp,strg,i,graph);
            }
            cout<<strg[i]<<" ";
        }
        cout<<endl;
    }

}