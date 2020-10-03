#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i = 1;i<=n;i++) 
    {
        mp[i]=-1;
    }
    for(int i = 0 ; i <n;i++)
    {
        
        cin>>arr[i];
        if(arr[i]!=0)
        {
            mp[arr[i]]=i+1;
        }
    }
    vector<int> ans,put;
    for(int i = 1;i<=n;i++)
    {
        if(mp[i]==-1)
        {
            ans.push_back(i);
            put.push_back(-1);
        }
    }

    
    int j=0;
    for(int i = 0; i <n;i++)
    {
        if(arr[i]==0)
        {
            // cout<<i<<endl;
            
            if(i+1==ans[j])
            {
                if(j>0)
                {
                    // cout<<"HELLO"<<endl;
                    int lastins=put[j-1];
                    

                    arr[lastins]=ans[j];
                    arr[i]=ans[j-1];
                    put[j-1]=i;
                    put[j]=lastins;
                }
                else if(j==0)
                {
                    swap(ans[j],ans[j+1]);
                    arr[i]=ans[j];
                    put[j]=i;
                    

                }
                // cout<<ans[1]<<" ^^"<<endl;
                
            }
            else
            {
                put[j]=i;
                arr[i]=ans[j];
                // cout<<i<<endl;
            }
            
            j++;
            
        }
        
        
    }
    for(int i = 0 ; i <n;i++)
    {
        cout<<arr[i]<<" ";
    }
        
}
