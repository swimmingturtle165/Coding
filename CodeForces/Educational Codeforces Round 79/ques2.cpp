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
        long n,s,time=0,maxi=0;
        cin>>n>>s;
        vector<long> inp,time_used,maxi_part;
        for(int i = 0 ; i <n;i++)
        {
            long temp;
            cin>>temp;

            inp.push_back(temp);
            time+=temp;
            
            time_used.push_back(time);
            if(inp[maxi]<temp)
            {
                maxi=i;
            }
            
            maxi_part.push_back(maxi);
        
        }
        int done=0;
        for(int i = 0 ; i <n;i++)
        {
            if(time_used[i]>s)
            {
                break;
            }
            done++;
        }
        if(done==n)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<maxi_part[done]+1<<endl;
        }
        
    }
}
