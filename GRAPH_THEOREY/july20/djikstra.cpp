#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class  Edge{
  public:
  int nbr;
  int wt;

};
vector<vector<Edge>> graph;
class DpPair
{
    public:
    int v;
    int c;
    string psf;

    DpPair(int v,int c,string psf)
    {
      this->v=v;
      this->c=c;
      this->psf=psf;
    }
    
    DpPair()
    {}

    bool operator<(const DpPair& other) const
    {
        return this->c <other.c;
    }
    
    bool operator>(const  DpPair& other) const
    {
        return this->c > other.c;
    }

};

void djikstra(int n)
{
  DpPair start(n,0,"");
  vector<bool> check(graph.size(),false);
  priority_queue<DpPair,vector<DpPair>,greater<DpPair>> q;
  q.push(start);

  while(q.size()!=0)
  {
      DpPair curr=q.top();
      q.pop();
      if(check[curr.v]==true)
      {
          continue;
      }
      cout<<curr.psf<<" @ "<<curr.c<<endl;
      check[curr.v]=true;
      for(int i = 0 ; i < graph[curr.v].size();i++)
      {
        if(check[graph[curr.v][i].nbr]==false)
        {
          DpPair upd(graph[curr.v][i].nbr,curr.c+graph[curr.v][i].wt,curr.psf + to_string(curr.v));
          q.push(upd);
        }
      }
  }

  
}


void addedge(int v1,int v2, int wt)
{
    Edge e1;
    e1.nbr=v2;
    e1.wt=wt;
    graph[v1].push_back(e1);

    Edge e2;
    e2.nbr=v1;
    e2.wt=wt;
    graph[v2].push_back(e2);

}
int main()
{
  graph.push_back(vector<Edge>()); //0
  graph.push_back(vector<Edge>()); //1
  graph.push_back(vector<Edge>());
  graph.push_back(vector<Edge>());
  graph.push_back(vector<Edge>());
  graph.push_back(vector<Edge>());
  graph.push_back(vector<Edge>());//6
  addedge(0,1,10);
  addedge(1,2,10);
  addedge(2,3,10);
  addedge(0,3,40);
  addedge(3,4,2);
  addedge(4,5,3);
  addedge(5,6,3);
  addedge(4,6,8);
  //addedge(2,5,5);
   djikstra(0);
}
  
  //display();