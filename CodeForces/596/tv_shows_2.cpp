#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,d;
        cin>>n>>k>>d;
       
        map<int,int> mp;
        vector<int> inp;
        for(int i = 0 ; i <n;i++)
        {
            int temp;
            cin>>temp;
            mp[temp]=0;
            inp.push_back(temp);
        }
        int ans=0;
        
        for(int i = 0 ; i <d;i++)
        {
            if( mp[inp[i]]==0)
            {
                ans++;
            }
            mp[inp[i]]=mp[inp[i]]+1;
        }
            int temp=ans;

        for(int i = d;i< n;i++)
        {
            
            if( mp[inp[i]]==0)
            {
                temp++;
            }
             mp[inp[i]]=mp[inp[i]]+1;
             mp[inp[i-d]]=mp[inp[i-d]]-1;
             if( mp[inp[i-d]]==0)
             {
                 temp--;
             }
             ans=min(ans,temp);             
        }
        cout<<ans<<endl;
    
    }
}