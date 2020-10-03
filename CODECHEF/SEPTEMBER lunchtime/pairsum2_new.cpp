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
        vector<long> sums;
        long rsum1=0,rsum2=0;
        for(int i = 0 ;i<n-1;i++)
        {
            int temp;
            cin>>temp;
            inp.push_back(temp);
            if(i==0)
            {
                rsum1=temp;
                sums.push_back(rsum1);
            }
            else
            {
                if(i%2==0)
                {
                     rsum1+=temp;
                     if(i!=0)
                     {
                         rsum2-=temp;
                     }
                    sums.push_back(rsum1);
                }
                else
                {
                    rsum2+=temp;
                    rsum1-=temp;
                    sums.push_back(rsum2);
                }
                
            }
            
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
                // for(int j = 0 ; j <maxi-mini;j++)
                // {
                //     if(j%2==0)
                //     {
                //         sm+=inp[mini+j-1];
                //     }
                //     else
                //     {
                //         sm-=inp[mini+j-1];
                //     }
                    
                // }
                if(maxi-mini>1)
                {
                    sm=0-sums[mini-1]+sums[maxi-1];
                }
                else
                {
                    sm=sums[mini-1];
                }
                
                cout<<sm<<endl;
            }
            
        }
    }
}