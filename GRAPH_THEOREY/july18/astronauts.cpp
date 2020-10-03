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
bool done [10]; 


int main()
{
   int n;
   cout<<"Enter the size of vector";
   vector<int> col1,col2;

//    for(int i = 0 ; i < 5 ; i++)
//    {
//        int temp1,temp2;
//        cin>>temp1;
//        cin>>temp2;
//        col1.push_back(temp1);
//        col2.push_back(temp2);
//    }

  graph.push_back(vector<Edges>());//0
  graph.push_back(vector<Edges>());//1
  graph.push_back(vector<Edges>());//2
  graph.push_back(vector<Edges>());//3
  graph.push_back(vector<Edges>());//4
  graph.push_back(vector<Edges>());//5
  graph.push_back(vector<Edges>());//6
  graph.push_back(vector<Edges>());//7
  graph.push_back(vector<Edges>());//8
  graph.push_back(vector<Edges>());//9
  graph.push_back(vector<Edges>());//10
//   for(int i = 0 ; i < n;i++)
//   {
//      if(col2[i]!=-1)
//      {
//          addedge(i,col2[i],0);         
//      }
//   }
addedge(2,9,0);
addedge(3,8,0);
addedge(7,8,0);
addedge(1,7,0);
addedge(6,5,0);
addedge(4,2,0);


  bool done[n];
  vector<string> group;
  for(int i = 0 ; i <= 10;i++)
  {
      string ans="";
      for(int j = 0 ; j < graph[i].size();j++)
      {
        if(done[graph[i][j].nbr]==false)
        {
          done[graph[i][j].nbr]=true;
         ans+= graph[i][j].nbr;

        }
      }
       //done[graph[i][j].nbr]=false;

      if(ans.size()!=0)
      {
       group.push_back(ans);
      }      
  }
  for(int i = 0 ; i < group.size();i++)
  {
      cout<<group[i]<<endl;
  }


//   addedge(0,1,10);
//   addedge(1,2,10);
//   addedge(2,3,10);
//   addedge(0,3,40);
//   addedge(3,4,2);
//   addedge(4,5,3);
//   addedge(5,6,3);
//   addedge(4,6,8);
//   addedge(2,5,5);
//   display();
  
}