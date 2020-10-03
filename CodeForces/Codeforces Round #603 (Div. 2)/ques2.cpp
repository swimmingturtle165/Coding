#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        set<int> mp,left;
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
            
            left.insert(arr[i]);
        }
        // mp.insert(arr[0]);
        int ans=0;
        for(int i = 0;i<n;i++)
        {
            if(mp.count(arr[i])!=0)
            {
                
                ans++;
                int temp=arr[i]-arr[i]%10;
                // cout<<mp.count(temp)<<"  "<<left.count(temp)<<endl;
                while(mp.count(temp)!=0 || left.count(temp)!=0)
                {
                    temp++;
                }
                left.erase(arr[i]);
                arr[i]=temp;
                
                   
            }
            else
            {
                left.erase(arr[i]);
                
            }
            

                mp.insert(arr[i]);

        }
        cout<<ans<<endl;
        for(int i = 0 ; i <n;i++)
        {
            int accompanying=arr[i]==0?3:4-log10(arr[i]+1);
            for(int k = 0 ; k <accompanying;k++)
            {
                cout<<0;
            }
            cout<<arr[i]<<endl;
        }
    }
}