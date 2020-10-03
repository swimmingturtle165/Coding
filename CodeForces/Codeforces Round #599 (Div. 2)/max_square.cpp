#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> inp;
        for(int i = 0 ; i <n;i++)
        {
            int temp;
            cin>>temp;
            inp.push_back(temp);
        }       
        sort(inp.begin(),inp.end());
        int best=-1;
        int ans=-1;
        for(int i = 0 ; i <n;i++)
        {
            int mini=min(inp[i],n-i);
            int temp_ans=mini*mini;
            // cout<<mini<<" "<<temp_ans<<endl;
            if(temp_ans >ans)
            {   
                best=mini;
                ans=temp_ans;
            }
        }
        cout<<best<<endl;
    }
}