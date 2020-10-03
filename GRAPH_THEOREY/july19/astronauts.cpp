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
int count=0;
vector<vector<Edges>> graph;
void teams(vector<string> &ans,int curr,string team)
{
    if(team.size()==2)
    {
        cout<<team<<endl;
        return;
    }
    if(curr==ans.size())
    {
        return;
    }
    for(int i = 0; i <ans[curr].size();i++ )
    {
        for(int j =curr+1;j<ans.size();j++)
        {
          teams(ans,j,team+to_string(ans[curr][i]));
          //cout<<team  <<ans[curr][i]
           teams(ans,j,team); 
        }
      
    }
    
}

void generatepermutations(vector<string> ans)
{
  for(int i = 0 ; i < ans.size()-1;i++)
  {
      for(int j =0;j<ans[i].size();j++)
      {
          int temp=i+1;
          while(temp<ans.size())
          {
          for(int k=0;k<ans[temp].size();k++)
           {
            cout<<ans[i][j]<<" -> "<<ans[i+1][k]<<"  "<<++count<<endl;
           }
        temp++;
      }
  }
}
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
    //get remove *mark print *addchild
    q.push(start);
    while(q.size()!=0)
    {
        int rem=q.front();
        q.pop();
        ans+=to_string(rem);
        
        bool answ=false;
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

 vector<string> gcc(int n)
{
    vector<bool> trav(n,false);
    vector<string> ans;
  
      for(int i = 0 ; i < n;i++)
      {
          if(trav[i]==false)
          ans.push_back(gsc(i,"",trav));
      }
      for(int i = 0;i<ans.size();i++)
      {
          cout<<ans[i]<<endl;
      }
      return ans;
}

int main()
{
  graph.push_back(vector<Edges>()); //0
  graph.push_back(vector<Edges>()); //1
  graph.push_back(vector<Edges>()); //2
  graph.push_back(vector<Edges>()); //3
  graph.push_back(vector<Edges>()); //4
  graph.push_back(vector<Edges>()); //5
  graph.push_back(vector<Edges>()); //6
  graph.push_back(vector<Edges>()); //7
  graph.push_back(vector<Edges>()); //8
  graph.push_back(vector<Edges>()); //9
  //graph.push_back(vector<Edges>());

//   addedge(0,1,10);
//   addedge(1,2,10);
//   addedge(2,3,10);
//   addedge(0,3,40);
//   addedge(3,4,2);
//   addedge(4,5,3);
//   addedge(5,6,3);
//   addedge(4,6,8);
  //addedge(2,5,5);
  addedge(2,9,0);
  addedge(3,8,0);
  addedge(8,7,0);
  addedge(1,7,0);
  addedge(6,5,0);
  addedge(4,2,0);
   vector<string> ans=gcc(10);
   //generatepermutations(ans);
   cout<<"################"<<endl;
    teams(ans,0,"");
  //display();
  
  

  
  
}