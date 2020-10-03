#include <bits/stdc++.h>
using namespace std;

int insert(int v,vector<vector<int>>&graph,vector<int> groups)
{
    vector<int> val;
    // val.insert(0,groups.size());
    for(int i = 0 ; i <groups.size();i++)
    {
        val.push_back(0);
    }
    int mini=0;
    for(int i = 0 ;i<graph[v].size();i++)
    {
        int temp=graph[v][i];
        val[groups[temp]]++;
        
    }
    for(int i = 2;i<val.size();i++)
    {
        if(val[i]%2==0 && val[i]>0)
        {
            return i;
        }
    }
    return -1;
}

void addEdge(int v1,int v2,vector<vector<int>>&graph)
{
    if(v1>v2)
    {
        swap(v1,v2);
    }
    
    graph[v2].push_back(v1);
}

void addEdge_mod(int v1,int v2,vector<vector<int>>&graph1)
{
    if(v1>v2)
    {
        swap(v1,v2);
    }
    
    graph1[v1].push_back(v2);
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
       vector<vector<int>> graph1;
       for(int i = 0 ; i <= n;i++)
       {
           graph1.push_back(vector<int>());
           
           graph.push_back(vector<int>());
       }
       for(int i = 0 ; i <m;i++)
       {
           int v1,v2;
           cin>>v1>>v2;

           vector<int>::iterator it,it1;

           it=find(graph[v1].begin(),graph[v1].end(),v2);
           it1=find(graph[v2].begin(),graph[v2].end(),v1);
           
           int mini=min(v1,v2),maxi=max(v1,v2);
           if(it==graph[v1].end() && it1==graph[v2].end())
           {
           addEdge(mini,maxi,graph);
           addEdge_mod(mini,maxi,graph1);
           }
       }

    //     cout<<"***************************************************"<<endl;
    //     cout<<" graph "<<endl;
    //    for(int i = 1 ; i <graph.size();i++)
    //    {
    //        cout<<i<<"--- >>> ";
    //        for(int j=0;j<graph[i].size();j++)
    //        {
    //            cout<<graph[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    //     cout<<" graph "<<endl;
    //    cout<<"***************************************************"<<endl;
    //     cout<<" graph1 "<<endl;

    //    for(int i = 1 ; i <graph1.size();i++)
    //    {
    //        cout<<i<<"--- >>> ";
    //        for(int j=0;j<graph1[i].size();j++)
    //        {
    //            cout<<graph1[i][j]<<" ";
    //        }
    //        cout<<endl;
    //    }
    //     cout<<" graph1 "<<endl;
    //    cout<<"***************************************************"<<endl;

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
           bool flag=true;
           vector<int> groups;
           int answ=1;
           int ind=-1;
           for(int i = graph.size()-1 ; i >=0 ;i--)
           {
               if((graph[i].size()+graph1[i].size())%2==1)
               {
                   ind=i;
                   break;
               }
           }
           if(ind!=-1)
           {
               cout<<2<<endl;
               for(int i = 1;i<=n;i++)
               {
                   if(i!=ind)
                   {
                       cout<<1<<" ";
                   }
                   else
                   {
                       cout<<2<<" ";
                   }
                   
               }
               cout<<endl;
           }
           if(ind==-1)
           {
             bool done=true;
             for(int i = 0 ; i <graph1.size();i++)
             {
                 groups.push_back(1);
             }
             for(int i = graph1.size()-1;i>=0;i--)
             {
                 for(int j = graph1[i].size()-1 ; j>=0;j--)
                 {
                    //   cout<<i<<" "<<j<<"%%"<<endl;
                     if(graph[graph1[i][j]].size()==0)
                     {
                         continue;
                     }
                     else if(graph[graph1[i][j]].size()%2==0)
                     {       
                        //  cout<<" ## "<<endl;
                        bool flag1=false;
                         for(int k = 0;k<graph[graph1[i][j]].size();k++)
                         {
                        //  cout<<" ## ";
                        //         cout<<graph1[i][j]<<"  "<<graph[graph1[i][j]][k]<<endl;
                                int temp=graph[graph1[i][j]][k];
                                 vector<int> :: iterator it1;
                                //  for(int z = 0 ; z <graph1[temp].size();z++)
                                //  {
                                //      cout<<graph1[temp][z]<<" ";
                                //  }
                                //  cout<<endl;
                                  it1=find(graph1[temp].begin(),graph1[temp].end(),graph1[i][j]);
                                   if(it1==graph1[temp].end())
                                   {
                                       
                                   } 
                                 if(i!=temp)
                                 {
                                 graph1[temp].erase(it1);
                                 }
                                //  for(int z = 0 ; z <graph1[temp].size();z++)
                                //  {
                                //      cout<<graph1[temp][z]<<" ";
                                //  }
                                //  cout<<endl;
                                 
                         }
                        //  cout<<" del  "<<graph1[i][j]<<endl;
                         graph1[i].erase(graph1[i].begin()+j);
                        // for(int z = 0 ; z <graph1[i].size();z++)
                        //          {
                        //              cout<<graph1[i][z]<<" ";
                        //          }
                        //          cout<<" done "<<endl;
                        int ins=insert(graph1[i][j],graph,groups);
                        if(ins==-1)
                        {
                         answ++;
                         ind++;
                        groups[graph1[i][j]]=answ;
                        }
                        else
                        {
                            groups[graph1[i][j]]=ins;
                        }
                        
            //             for(int l = 0 ; l <groups.size();l++)
            //  {
            //      cout<<groups[l]<<" ";
            //  }
            //  cout<<endl;
                     }
                     else if(graph[graph1[i][j]].size()%2==1)
                     {
                        
                        //  cout<<"&&&"<<endl;
                        
                          for(int k = 0;k<graph[graph1[i][j]].size();k++)
                         {
                                // cout<<graph1[i][j]<<"  "<<graph[graph1[i][j]][k]<<endl;
                                int temp=graph[graph1[i][j]][k];
                                 vector<int> :: iterator it1;
                                //  for(int z = 0 ; z <graph1[temp].size();z++)
                                //  {
                                //      cout<<graph1[temp][z]<<" ";
                                //  }
                                //  cout<<endl;
                                  it1=find(graph1[temp].begin(),graph1[temp].end(),graph1[i][j]);
                                 if(i!=temp)
                                 {
                                 graph1[temp].erase(it1);
                                 }
                                //  for(int z = 0 ; z <graph1[temp].size();z++)
                                //  {
                                //      cout<<graph1[temp][z]<<" ";
                                //  }
                                //  cout<<endl;
                                
                                 
                         }
                            
                        int ins=insert(graph1[i][j],graph,groups);
                        if(ins==-1)
                        {
                         answ++;
                         ind++;
                        groups[graph1[i][j]]=answ;
                        }
                        else
                        {
                            groups[graph1[i][j]]=ins;
                        }
                    
            //             for(int l = 0 ; l <groups.size();l++)
            //  {
            //      cout<<groups[l]<<" ";
            //  }
            //  cout<<endl;
                     
                        
                        done=false;
                        break;
                     }
                    
                    
                     
                 } 
            //      cout<<answ<<endl;
            //  for(int l = 0 ; l <groups.size();l++)
            //  {
            //      cout<<groups[l]<<" ";
            //  }
            //  cout<<endl;
                 if(done==false)
                     {
                         break;
                     }
                 
             }
             cout<<answ<<endl;

            for(int l = 1 ; l <groups.size();l++)
             {
                 cout<<groups[l]<<" ";
             }
             cout<<endl;
             

           }
       }
        
        
       
        graph.clear();      
        graph1.clear();
   }
}