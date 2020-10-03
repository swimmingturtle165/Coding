#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<long long> inp;
    for(long long i = 0 ; i <n;i++)
    {
        long long temp;
        cin>>temp;
        inp.push_back(temp);
    }
    vector<long long> starting,ending;
    for(long long i = 0 ; i <inp.size();i++)
    {
        starting.push_back(i);

        while(i<n-1 &&inp[i]<inp[i+1])
        {
            i++;
        }
        ending.push_back(i);
    }
    //  ending.push_back(n-1);
    if(starting.size()==1)
    {
        cout<<inp.size()<<endl;
        return 0;
    }
    long long res=1;
    for(long long i = 0 ; i <starting.size()-1;i++)
    {
        // cout<<starting[i]<<"  _  "<<ending[i]<< endl;
        res=max(res,ending[i]-starting[i]+1);
        if(starting[i+1]-ending[i]==1 )
        {
            if(inp[ending[i]-1]<inp[starting[i+1]])
            {
            res=max(res,ending[i+1]-starting[i]);
            }
            if(inp[ending[i]]<inp[starting[i+1]+1])
            {
                res=max(res,ending[i+1]-starting[i]);
            }
        }
    }
    int i =starting.size()-1;
    // cout<<starting[i]<<"  _  "<<ending[i]<< endl;
     res=max(res,ending[starting.size()-1]-starting[starting.size()-1]+1);
    cout<<res<<endl;
}