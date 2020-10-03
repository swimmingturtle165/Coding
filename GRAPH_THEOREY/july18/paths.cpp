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
int spv=INT_MAX,lpv=INT_MIN,celing=INT_MAX,floorl=INT_MIN;
string sp,lp,celingp,floorp;
void printallpaths(int start,int end,vector<bool>&visited,string psf,int plsf,int factor)
{
    if(start==end)
    {
        psf+=(char)(start+'0');
        if(plsf<spv)
        {
            spv=plsf;
            sp=psf;
        }
        if(plsf>lpv)
        {
            lpv=plsf;
            lp=psf;
        }
        if(plsf<celing && plsf>factor)
        {
           celing=plsf;
           celingp=psf;
        }
        if(plsf>floorl && plsf<factor)
        {
         floorl=plsf;
         floorp=psf;
        }
        cout<<psf<<endl;
        return;
    }
    visited[start]=true;
    for(int i = 0 ; i < graph[start].size();i++)
    {
        if(visited[graph[start][i].nbr]==false)
        {
       printallpaths(graph[start][i].nbr,end,visited,psf+to_string(start)+" ",plsf+graph[start][i].wt,factor);
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
  printallpaths(0,6,trav,"",0,45);
  cout<<"Largest "<<lp<<" @ "<<lpv<<endl;
  cout<<"smallest "<<sp<<" @ "<<spv<<endl;
  cout<<"ceiling "<<celingp<<" @ "<<celing<<endl;
  cout<<"floor "<<floorp<<" @ "<<floorl<<endl;
}