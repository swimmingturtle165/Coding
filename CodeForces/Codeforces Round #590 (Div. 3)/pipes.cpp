#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        string l1,l2;
        cin>>l1>>l2;
        int ** arr=new int*[2];
        
        for(int i = 0 ; i < 2;i++)
        {
            arr[i]=new int[n];
            for(int j = 0 ; j < n;j++)
            {
                if(i==0)
                {
                    arr[i][j]=l1[j]-'0';
                }
                else
                {
                     arr[i][j]=l2[j]-'0';
                }
                
            }
        }
        int j=0,i=0;
        while (i<n)
        {
            if(arr[j][i]==1 || arr[j][i]==2)
            {
                i++;
            }
            else
            {
                j=(j+1)%2;
                if(arr[j][i]==1|| arr[j][i]==2)
                {
                    break;
                }
                i++;
            }
            if(i==n-1 && j==1)
            {
                break;
            }
            if(i==n-1 && j==0 && arr[j][i]=='1')
            {
                j++;
                break;
            }
            
        }
        cout<<"*****"<<endl;
        if(i==n-1 && j==1 )
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        

    }
}