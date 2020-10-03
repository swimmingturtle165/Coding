#include <bits/stdc++.h>
using namespace std;


int main()
{
    int r,c;
    cin>>r>>c;
    vector<int> rows,col;
    for(int i = 0 ;i<r;i++)
    {
        int temp;
        cin>>temp;
        rows.push_back(temp);
    }
    for(int i = 0 ; i <c;i++)
    {
        int temp;
        cin>>temp;
        col.push_back(temp);
    }
    int **arr=new int*[r];
    for(int i = 0 ; i <r;i++)
    {
        arr[i]=new int[c];
    }
     for(int i = 0 ; i < r;i++)
    {
        for(int j = 0 ; j <c;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i = 0 ;i < r;i++)
    {
        for(int j = 0 ; j < rows[i];j++)
        {
            arr[i][j]=1;
        }
    }
    for(int i = 0 ;i < c;i++)
    {
        for(int j = 0 ; j < col[i];j++)
        {
            arr[j][i]=1;
        }
    }

    bool flag=true;
    //check
    for(int i = 0 ;i < r&&flag;i++)
    {
        for(int j = 0 ; j < rows[i] &&flag;j++)
        {
            if(arr[i][j]!=1)
            { 
            flag=false;
            cout<<0<<endl;
            break;
         
            }
        }
        if(rows[i] <c && arr[i][rows[i]]==1 &&flag)
        {
            flag=false;
            cout<<0<<endl;
            break;
           
        }
    }
    
    for(int i = 0 ;i < c&&flag;i++)
    {
        for(int j = 0 ; j < col[i] &&flag ;j++)
        {
           if(arr[j][i]!=1)
           {
                 flag=false;
                 cout<<0<<endl;
                 break;
                
           }
           
        }
        if(col[i]<r&& arr[col[i]][i]==1 &&flag)
           {
                flag=false;
                cout<<0<<endl;
                 
           }
    }
    long options=0;
     //cout<<"*********"<<endl;
     
    for(int i = 1 ; i < r &&flag;i++)
    {
        for(int j = rows[i]+1 ; j <c;j++)
        {
            
            // if(arr[i][j]==0)
            // {
                // for(int k = j+1;k<c;k++)
                // {
                if(arr[i][j]==0 && i!=col[j])
                {
                   options++;
               }
                // }
                // break;
            
            
            
        }
    
    }
    //cout<<"*********"<<endl;
   // cout<<options<<endl;
    // long long div=pow(10,9)+7;
    // long long unsigned val=options==0?0:pow(2,options);
    // val=val%div;
    // cout<<val<<endl;

   
       if(flag)
       {
           
        long long ans=1;
        long long div=1000000007;
        for(int i = 0 ; i < options;i++)
        {
            ans*=2;
            if(ans>=div)
            {
                ans=ans%div;
            }
        }

        cout<<ans<<endl;
       }
       
    
}