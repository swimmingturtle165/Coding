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

string gsc(int start,string ans,vector<bool>&trav)
{
    
    queue<int> q;
    trav[start]=true;
    //get remove *mark work *addchild
    q.push(start);
    while(q.size()!=0)
    {
        int rem=q.front();
        q.pop();
        ans+=to_string(rem);
        
        //bool answ=false;
        for(int i = 0 ; i < graph[rem].size();i++)
        {
            if(trav[graph[rem][i].nbr]==false)
            {
                
                q.push(graph[rem][i].nbr);
                trav[graph[rem][i].nbr]=true;
            }
        }
        
    }
    return ans;
}

 bool  isConnected(int n)
{
    vector<bool> trav(n,false);
    
    int count=0;
  
      for(int i = 0 ; i < n;i++)
      {
          if(trav[i]==false)
          {
               count++;
          if(count==2)  
          {
              return false;
          }
          gsc(i,"",trav);
             
         }
      }
      
      return true;
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
   cout<<isConnected(7);
  
  //display();
}