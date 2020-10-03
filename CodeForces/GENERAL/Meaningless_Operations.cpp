#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    map<long long,int> mp;
        vector<long long> values;
        values.push_back(1);

    long long curr=2;
    long long lim=pow(2,25);
    int power=1;
    while(curr<=lim)
    {   mp[curr-1]=power;
        values.push_back(curr-1);
        curr*=2;
        power++;
    }
    while(t--)
    {
        long long inp;
        cin>>inp;
        if(inp==1)
        {
            cout<<1<<endl;
            continue;
        }
        map<long long,int> :: iterator it;
        it=mp.find(inp);
        if(it!=mp.end())
        {
            long long maxi=1;
            for(long long i = 2 ; i <=pow(inp,0.5)+1;i++)
            {
                if(inp%i==0)
                {
                    maxi=max(maxi,inp/i);
                }
            }
            cout<<maxi<<endl;
            
        }
        else
        {
            vector<int> in,oup;
            long long temp=inp;
            while(temp>0)
            {
                in.push_back(temp%2);
                temp=temp/2;
            }
            int sz=in.size();
            cout<<values[sz]<<endl;
        }
        
    }
}

