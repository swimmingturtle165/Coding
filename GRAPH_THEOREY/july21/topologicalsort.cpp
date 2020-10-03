#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Edge
{
    public: 
    int nbr;
    int wt;
};
vector<vector<Edge>> graph(7,vector<Edge>());
void addedge(int n1, int n2,int n3)
{
    Edge e;
    e.nbr=n2;
    e.wt=n3;
    graph[n1].push_back(e);
}
//hello 
void istopo(stack<int> &s,int r,vector<bool>&visited)
{
    visited[r]=true;
    for(int i = 0 ;i < graph[r].size();i++)
    {
      Edge ne=graph[r][i];
      if(visited[ne.nbr]==false)
      {
        istopo(s,ne.nbr,visited);
      }
    }
    s.push(r);
}
void topographcalorder()
{
  vector<bool> visited(graph.size(),false);
  stack<int> s;
  for(int i = 0 ;i < graph.size();i++)
  {
      if(visited[i]==false)
      {
        istopo(s,i,visited);
      }
  }
  while(s.size()>0)
  {
      int temp=s.top();
      s.pop();
      cout<<temp<<" ";
  }
  return;
}

int main()
{
  addedge(0,1,1);
  addedge(0,4,1);
  addedge(1,2,1);
  addedge(2,3,1);
  addedge(4,3,1);
  addedge(5,4,1);
  addedge(5,6,1);
  addedge(6,3,1);
  topographcalorder();
}