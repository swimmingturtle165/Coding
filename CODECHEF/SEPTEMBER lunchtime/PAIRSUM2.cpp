#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> inp;
        for(int i = 0 ;i<n-1;i++)
        {
            int temp;
            cin>>temp;
            inp.push_back(temp);
        }
        for(int i = 0 ; i <q;i++)
        {
            int a,b;
            cin>>a>>b;
            long sm=0;
            int mini=min(a,b);
            int maxi=max(a,b);
            if((maxi-mini)%2==0)
            {
                cout<<"UNKNOWN"<<endl;
            }
            else
            {
                for(int j = 0 ; j <maxi-mini;j++)
                {
                    if(j%2==0)
                    {
                        sm+=inp[mini+j-1];
                    }
                    else
                    {
                        sm-=inp[mini+j-1];
                    }
                    
                }
                cout<<sm<<endl;
            }
            
        }
    }
}