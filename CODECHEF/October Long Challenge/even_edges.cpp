#include <bits/stdc++.h>
using namespace std;

class Edges
{
    public:

    int nbr;
    int wt;

    Edges(int n1,int n2)
    {
        nbr=n1;
        wt=n2;
    }
};





void addEdge(int v1,int v2,int wt,vector<vector<Edges>>&graph)
{
    Edges e1(v2,wt),e2(v1,wt);

    graph[v1].push_back(e1);
    graph[v2].push_back(e2);
}





// string gsc(int start,string ans,vector<bool>&trav,vector<vector<Edges>>&graph,int &temp)
// {
    
//     queue<int> q;
//     trav[start]=true;
//     //get remove *mark work *addchild
//     q.push(start);
//     while(q.size()!=0)
//     {
//         int rem=q.front();
//         q.pop();
//         ans+=to_string(rem);
        
//         //bool answ=false;
//         for(int i = 0 ; i < graph[rem].size();i++)
//         {
//             temp++;
//             if(trav[graph[rem][i].nbr]==false)
//             {
                
//                 q.push(graph[rem][i].nbr);
//                 trav[graph[rem][i].nbr]=true;
//             }
//         }
        
//     }
//     return ans;
// }
// int helper(vector<vector<Edges>> graph)
// {
//     int odd=0,even=0;
//     vector<bool> trav;
//     for(int i = 0 ; i <=graph.size();i++)
//     {
//         trav.push_back(false);
//     }
//     int arr[2][graph.size()];
//     vector<string> independent_comp;
//     vector<int> ind;
//     vector<int> edges;
//     for(int i = 1 ; i <=graph.size();i++)
//     {
//         if(trav[i]==false)
//         {
//             int temp1=0;
//             string temp=gsc(i,"",trav,graph,temp1);
//             for(int i = 0 ; i <temp.size();i++)
//             {
//                 int a=temp[i]-'0';
//                 arr[0][a]=a;
//                 arr[1][a]=independent_comp.size()+1;
//             }
//             edges.push_back(temp1);
//             independent_comp.push_back(temp);
//             ind.push_back(temp.size());
//             temp1%2==0?even++:odd++;
//         }
//     }
//     long long ans=0;

// }





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       vector<vector<Edges>> graph;
       for(int i = 0 ; i <= n;i++)
       {
           graph.push_back(vector<Edges>());
       }
       for(int i = 0 ; i <m;i++)
       {
           int v1,v2;
           cin>>v1>>v2;
           addEdge(v1,v2,1,graph);
       }
       if(m%2==0)
       {
           cout<<1<<endl;
           for(int i = 1 ; i <=n;i++)
           {
               cout<<1<<" ";
           }
       }
       else
       {
           for(int i = 0 ; i <=n;i++)
           {
               
           }
           while(m%2!=0)
           {
               
                    int temp=-1;
                    for(int i = 0 ; i<=n;i++)
                    {
                        if(graph[i].size()%2==1)
                        {
                            temp=i;
                            break;
                        }
                    }
                    //cout<<2<<endl;
                    for(int i = 1 ; i <=n;i++)
                    {
                        if(i!=temp)
                        {
                        cout<<1<<" ";
                        }
                        else
                        {
                            cout<<2<<" ";
                        }
                    }
           }
       }
       
       
       
   }
}