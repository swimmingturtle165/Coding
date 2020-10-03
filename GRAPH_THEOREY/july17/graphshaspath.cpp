#include<iostream>
#include<vector>
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
//bool trav[8];
bool haspath(int start,int end,vector<bool>&trav)
{
    if(start==end)
    {
        //cout<<"TRUE"<<endl;
        return true;
    }  
    trav[start]=true;
  for(int i=0;i<graph[start].size();i++)
  {
      if(trav[graph[start][i].nbr]==false)
      {
        bool temp= haspath(graph[start][i].nbr,end,trav);
        if(temp==true)
        {
            return true;
        }
       } 
  }   
  trav[start]=false; 
  
  return false;    
 
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
  display();
  int start,end;
  cin>>start>>end;
  vector<bool> trav(7,false);
  //trav.resize(7);
  bool ans=haspath(start,end,trav);
  cout<<ans<<endl;
}