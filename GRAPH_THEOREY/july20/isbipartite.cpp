#include<iostream>
#include<vector>
#include<climits>
#include <queue>
using namespace std;

class Edges{  

    public:
    int nbr;
    int wt;
    

};
class BiPair
{
    public:
    int v;
    int level;
};
vector<vector<Edges>> graph;

bool isBipartite(int r,vector<int>&trav)
{
  queue<BiPair> q;
  BiPair bp;
  bp.v=r;
  bp.level=1;
  q.push(bp);

  while (q.size()!=0)
  {
      BiPair curr=q.front();
      q.pop();
      trav[curr.v]=curr.level;      //ye walas step bad me karna hai
    
      if(trav[curr.v]!=0)
      {

        if(curr.level%2!=trav[curr.v]%2)        //nahi to ye wali condition hamesha true hogi
        {
            return false;
        }
       

      }
      for(int i = 0 ; i < graph[curr.v].size();i++)
      {
          if(trav[graph[curr.v][i].nbr]==0)
          {
            BiPair temp;
            temp.v=graph[curr.v][i].nbr;
            temp.level=curr.level+1;
            q.push(temp);
          }
      }
  }
  return true;
}

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


bool isCompBipartite(int n)
{
    vector<int> trav(graph.size(),0);
  for(int i = 0 ; i < n ; i ++)
  {
    if(trav[i]==0)
    {
        bool ans=isBipartite(i,trav);
        if(ans==false)
        {
           return false;
        }
    }
  }
  return true;
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
  //addedge(2,5,5);
   cout<<isCompBipartite(7);
  
  //display();
}