#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long r,c;
    cin>>r>>c;
    if(r==1 && c==1)
    {
        cout<<0;
    }
    else if(c==1)
    {
        for(int i = 2;i<=r+1;i++)
        {
            cout<<i<<endl;
        }
    }
    
    else 
    {
    
    vector<int> dist;
    for(int i = 0 ; i  <r;i++)
    {
        
        for(int j = 0 ; j <c;j++)
        {
            
            cout<<(i+1)*(r+1+j)<<" ";
        }
        
        cout<<endl;
    }
    }
    
}