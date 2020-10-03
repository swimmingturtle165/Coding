#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        int arrq[m];
        for(int i = 0 ; i <n;i++)
        {
            
            
            arr[i]=0;
        }
        for(int i = 0 ; i < m;i++)
        {
            cin>>arrq[i];
        }
        bool flag=true;
        for(int i = 0 ; i < m ;i++)
        {
            
           int c=arrq[i]-1;
            if(arr[c] > (i)/n)
            {
                flag=false;
                
                break;
            }
            arr[c]++;
        }
        if(flag==true)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}