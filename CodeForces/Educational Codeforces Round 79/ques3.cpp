#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector <long long> order,list;
        map<long long,long long> listed;
        for(long long i = 0 ; i <n;i++)
        {
            long long temp;
            cin>>temp;
            listed[temp]=i;
            // order.push_back(temp);
        }
       
       
        // cout<<listed[1]<<" check"<<endl;
        for(long long i = 0 ; i <m;i++)
        {
            long long temp;
            cin>>temp;           
            list.push_back(temp);
        }
        long long ans=0,found_max=-1;
        for(long long i = 0 ;  i<m;i++)
        {
           
            if(listed[list[i]]>found_max)
            {
                ans+=(long long)2*(listed[list[i]]-i)+1;
                found_max=listed[list[i]];
            }
            else
            {
                ans++;
            }
            // cout<<ans<<" -- "<<list[i]<<endl;
        }
        cout<<ans<<endl;
        

    }
}
