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
        vector<int> ans;
        set<int> dup;
        int n;
        cin>>n;
        int curr=-1;
        for(int i = 1 ;i<=pow(n,0.5);i++)
        {
            int temp=n/i;
            if(temp!=curr)
            {
                if(dup.count(temp)==0)
                {
                ans.push_back(temp);
                dup.insert(temp);
                }
                // dup.insert(i);
                // ans.push_back(temp);
                if(i!=temp)
                {
                ans.push_back(i);
                dup.insert(i);
                }
                curr=temp;
            }
            // if(float (n/i) -int(n/i)!=0)
            // {
            //     ans.push_back(i);
            // }
        }
        if(curr!=0)
        {
            ans.push_back(0);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}