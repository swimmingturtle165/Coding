#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
    public:
    int nbr;
    int wt;
};

vector<vector<Edge>> graph;

class PPair
{
    public:
    int v;
    int av;
    int cost;

    PPair(int n1,int n2,int n3)
    {
        this->v=n1;
        this->av=n2;
        this->cost=n3;
    }
    bool operator<(const PPair& other) const
    {
        return  this->cost <other.cost;
    }
    bool operator >(const PPair& other )const
    {
       return  this->cost > other.cost; 
    }
    
};

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


void addedge(vector<vector<Edge>>& g,int v1,int v2, int wt)
{
    Edge e1;
    e1.nbr=v2;
    e1.wt=wt;
    g[v1].push_back(e1);

    Edge e2;
    e2.nbr=v1;
    e2.wt=wt;
    g[v2].push_back(e2);

}

void display(vector<vector<Edge> >& g)
{
    for(int i = 0 ; i < g.size();i++)
    {
        cout<<i<<" ";
        for(int j=0;j<g[i].size();j++)
        {
            Edge e=g[i][j];
            cout<<e.nbr<<"=>"<<e.wt<<" ";
        }
        cout<<endl;
    }
}
void prims()
{
    vector<vector<Edge> > mst(graph.size(),vector<Edge>());
   
    priority_queue<PPair,vector<PPair>,greater<PPair> > q;
    
    vector<bool> visited(graph.size(),false);
   
    PPair start(0,-1,0);
   
    q.push(start);
    while(q.size()>0)
    {
        PPair rem=q.top();
        q.pop();
        
        if(visited[rem.v]==true)
        {
            continue;
        }
        visited[rem.v]=true;
        
        if(rem.av!=-1)
        {            
          addedge(mst,rem.v,rem.av,rem.cost);
        }
        for(int i = 0 ; i < graph[rem.v].size();i++)
        {
            Edge ne=graph[rem.v][i];
            if(visited[ne.nbr]==false)
            {
                PPair addi(ne.nbr,rem.v,ne.wt);
                q.push(addi);
            }
        }
    }
    display(mst);

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

  addedge(0,1,20);
  addedge(1,2,10);
  addedge(2,3,20);
  addedge(0,3,40);
  addedge(3,4,2);
  addedge(4,5,3);
  addedge(5,6,3);
  addedge(4,6,8);
  //addedge(2,5,5);
   //djikstra(0);

   prims();

}

