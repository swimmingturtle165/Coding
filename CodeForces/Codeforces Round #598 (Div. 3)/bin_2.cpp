#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<long long> indexes;
        for(long long i = 0 ; i <s.size();i++)
        {
            if(s[i]=='0')
            {
                indexes.push_back(i);
            }
        }
        long long i = 0;
        while(k>0 && i<indexes.size())
        {
            // cout<<i<<" "<<k<<endl;

            if(indexes[i]-i<k)
            {
                k=k-indexes[i]+i;
                indexes[i]=i;

            }
            else
            {
                indexes[i]=indexes[i]-k;
                k=0;
                break;
            }
            i++;
        }
            // cout<<i<<" "<<k<<endl;

        vector<long long> output(s.size(),1);
        for(long long i = 0 ; i <indexes.size();i++)
        {
            long long ci=indexes[i];
            output[ci]=0;
        }
        for(long long i = 0 ; i <output.size();i++)
        {
            cout<<output[i];
        }
        cout<<endl;
    }
}