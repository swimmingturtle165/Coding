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
class StepPair
{
  public:
  int curr;
  int stepsofar;
  string psf;

  StepPair(int n1,int n2, string ans)
  {
    this->curr=n1;
    this->stepsofar=n2;
    this->psf=ans;
  }
  bool operator<(const StepPair& other)const
  {
    return this->stepsofar < other.stepsofar;
  }
   bool operator>(const StepPair& other)const
  {
    return this->stepsofar > other.stepsofar;
  }
};
void solve(int n,int target)
{
  StepPair start(n,0,"");
  vector<bool> trav(graph.size(),false);
  priority_queue<StepPair,vector<StepPair>,greater<StepPair>> q;
  q.push(start);
  while(q.size()!=0)
  {
    StepPair rem=q.top();
    q.pop();
    if(trav[rem.curr]==true)
    {
      continue;
    }
    trav[rem.curr]=true;
    if(rem.curr==target)
    {
     cout<<rem.psf<<rem.curr<<" @ "<<rem.stepsofar<<endl;
      return;
    }
    for(int y=1 ; y<=6 && y+rem.curr <=target;y++ )
    {
    StepPair nex(rem.curr+y,rem.stepsofar+1,rem.psf +to_string(rem.curr)+" ");
    q.push(nex);
    }
   for(int i = 0 ; i <graph[rem.curr].size();i++)
        {
          Edge ne=graph[rem.curr][i];
          if(trav[ne.nbr]==false)
          {
            StepPair jump(ne.nbr,rem.stepsofar,rem.psf +to_string(rem.curr)+" ");
            q.push(jump);
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
void display()
{
    for(int i = 0 ; i < graph.size();i++)
    {
        cout<<i<<" ";
        for(int j=0;j<graph[i].size();j++)
        {
            Edge e=graph[i][j];
            cout<<e.nbr<<"=>"<<e.wt<<" ";
        }
        cout<<endl;
    }
}



int main()
{
 for(int i = 0;i<=30;i++)
 {
   graph.push_back(vector<Edge>());
 }
  addedge(2,27,1);
  addedge(4,23,1);
  addedge(7,14,1);
  addedge(5,21,1);
  display();
  solve(0,30);
 
}