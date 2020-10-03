#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Edges{  

    public:
    int nbr;
    int wt;

};
vector<vector<Edges>> graph;
void display()
{
    for(int i = 0 ; i < graph.size();i++)
    {
        cout<<i<<" ";
        for(int j=0;j<graph[i].size();j++)
        {
            Edges e=graph[i][j];
            cout<<e.nbr<<"=>"<<e.wt<<" ";
        }
        cout<<endl;
    }
}
void addedge(int v1,int v2, int wt)
{
    Edges e1;
    e1.nbr=v2;
    e1.wt=wt;
    graph[v1].push_back(e1);

    Edges e2;
    e2.nbr=v1;
    e2.wt=wt;
    graph[v2].push_back(e2);

}
void hamilton(int start,vector<bool>&visited,int cl,int os,string ans)
{ 
  if(cl==visited.size()-1)
  {
      ans+=to_string(start);
      cout<<ans<<" ";
      for(int i = 0 ; i < graph[start].size();i++)
      {
          if(graph[start][i].nbr==os)
          {
                cout<<"**"<<endl;
                return;
          }
      }
      cout<<"."<<endl;
        return;
  }
    visited[start]=true;
    for(int i = 0 ; i < graph[start].size();i++)
    {
        if(visited[graph[start][i].nbr]==false)
        {
       hamilton(graph[start][i].nbr,visited,cl+1,os,ans+to_string(start)+" ");
        }
    }
    visited[start]=false;
}

int main()
{

  graph.push_back(vector<Edges>()); //0
  graph.push_back(vector<Edges>()); //1
  graph.push_back(vector<Edges>());
  graph.push_back(vector<Edges>());
  graph.push_back(vector<Edges>());
  graph.push_back(vector<Edges>());
  graph.push_back(vector<Edges>());//6

  addedge(0,1,10);
  addedge(1,2,10);
  addedge(2,3,10);
  addedge(0,3,40);
  addedge(3,4,2);
  addedge(4,5,3);
  addedge(5,6,3);
  addedge(4,6,8);
  addedge(2,5,5);
  display();
  vector<bool> trav(7,false);
  int n;
  cin>>n;
  hamilton(n,trav,0,n,"");

}