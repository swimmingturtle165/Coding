#include <bits/stdc++.h>
using namespace std;

void addEdge(int v1,int v2,vector<vector<int>>&graph)
{
    
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);

}


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
       vector<vector<int>> graph;
       for(int i = 0 ; i <= n;i++)
       {           
           graph.push_back(vector<int>());
       }
       for(int i = 0 ; i <m;i++)
       {
           int v1,v2;
           cin>>v1>>v2;           
           addEdge(v1,v2,graph);
                      
       }
       

       if(m%2==0)
       {
           cout<<1<<endl;
           for(int i = 0 ; i <n;i++)
           {
               cout<<1<<" ";
           }
           cout<<endl;
       }
       else
       {       
            int temp=-1;
            for(int i = 1 ; i<=n;i++)
            {
                if( graph[i].size()%2==1 )
                {
                    temp=i;
                    break;
                }
            }

          
           if(temp==-1)
           {
                 int in=-1;
                 for(int i = 0 ; i <graph.size();i++)
                 {
                     if(graph[i].size()>0)
                     {
                         in=i;
                         break;
                     }
                 }
                 int a1=in;
                 int a2=graph[in][0];
                 cout<<3<<endl;
                 for(int i = 1;i<=n;i++)
                 {
                        if(a1==i )
                        {
                            cout<<2<<" ";
                        }
                        else if(a2==i)
                        {
                            cout<<3<<" ";
                        }
                         else
                        {
                            cout<<1<<" ";
                        }
                 }
                 cout<<endl;
            }
           else
           {
               
            cout<<2<<endl;
            for(int i = 1 ; i <=n;i++)
            {
                if(i==temp)
                {
                cout<<2<<" ";
                }
                else
                {
                cout<<1<<" ";
                }
            }
               cout<<endl;
           }
           
        }
       
        graph.clear();      
   }
}