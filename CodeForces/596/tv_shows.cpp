#include <bits/stdc++.h>
using namespace std;


int get_distinct(vector<int>&s,int index,int d)
{
    // cout<<index<<" *** "<<endl;
    if(index+d>s.size())
    {
        
        return 1000;
    }
    else
    {
        bool done[100];
        for(int i = 0 ; i < 100;i++)
        {
            done[i]=false;
        }
        int ans=0;
        for(int i =index;i<index+d;i++)
        {
            if(done[s[i]]==false)
            {
                ans++;
                done[s[i]]=true;
            }
        }
        return ans;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,d;
        cin>>n>>k>>d;
        vector<int> schedule,repeats;
        // vector<vector<int>> occurance;
        // for(int i = 0 ; i < 101;i++)
        // {
        //     occurance.push_back( vector<int>());
        // }
        for(int i = 0 ; i < n;i++)
        {
            int temp;
            cin>>temp;
            schedule.push_back(temp);
        //     occurance[temp].push_back(i);
        //     if(occurance[temp].size()>1 )
        //     {
        //         int sz=occurance[temp].size();
        //         if(occurance[temp][sz-1] - occurance[temp][sz-2]<d)
        //         {
        //             repeats.push_back(occurance[temp][sz-2]);
        //         }
        //     }
        // }
        // if(repeats.size()==0)
        // {
        //     cout<<d<<endl;
         }
        // else
        // {
            int ans=d;
            // for(int i = 0 ; i <repeats.size();i++)
            // {
            //     if(n-repeats[i]<d)
            //     {
            //         // cout<<n<<" "<<repeats[i]<<" ** "<<endl;
            //         break;
            //     }
            //         // cout<<n<<" "<<repeats[i]<<" ** "<<endl;

            //     int temp=get_distinct(schedule,repeats[i],d);
            //     if(temp!=-1)
            //     {
            //         ans=min(ans,temp);
            //     }
            // }   
           for(int i = 0 ; i < n;i++)
           {
               int temp=get_distinct(schedule,i,d);
               ans=min(ans,temp);
           }
            cout<<ans<<endl;        
        
        
    }
}