#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    vector<int> boards;
    for(int i = 0 ; i <m;i++)
    {
        int temp;
        cin>>temp;
        boards.push_back(temp);
    }
    vector<int> path(n+2,0);
    path[n+1]=m+1;
    int curr=n+1;
    while(curr>d-1 && m>0)
    {
        cout<<curr<<endl;
        path[curr-d]=m;
        
        if(m>=1)
        {
            int curren=curr;
        curr-=boards[m-1];
        curr++;
        
        for(int i = curr;i<=curren;i++)
        {
            path[i]=m;
        }
        m--;
        }
        curr=curr-d+1;

    }
        cout<<curr<<endl;

    int ans=-1;
    for(int i = 0 ; i <=n+1;i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    for(int i = 0 ;i<d;i++)
    {
        if(path[i]!=-1)
        {
            ans=i;
        }
    }
    if(ans!=-1)
    {
        cout<<"YES"<<endl;
        int step=0;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}