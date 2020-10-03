#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        n--;
        int q;
        cin>>q;
        int inp[n];
        long long sum[n+1];
        sum[0]=0;
        int c=1;
        for(int i = 0 ; i <n;i++ )
        {
            cin>>inp[i];
            if(i>0)
            {
                sum[i]=sum[i-1]+c*inp[i-1];
                 c=c*(-1);
            }
        }
        sum[n]=sum[n-1]+c*inp[n-1];
        // for(int i = 1,c=1 ; i <=n;i++)
        // {
        //     sum[i]=sum[i-1]+c*inp[i-1];
        //     c=c*(-1);
        // }

        
        while(q-->0)
        {
            long long val=0;
            int l,r;
            cin>>l>>r;
            int maxi=max(l,r);
            int mini=min(l,r);
           
            if((maxi-mini)%2==0)
            {
                cout<<"UNKNOWN"<<endl;
            }
            else if(maxi-mini==1)
            {
                cout<<inp[mini-1]<<endl;
            }
            // else if(mini==1)
            // {
            //     cout<<sum[maxi-1]<<endl;
            // }
            else
            {
                 maxi--;
                 mini--;

                if(maxi%2==0)
                {
                    val-=sum[maxi];
                    val+=sum[mini];
                }
                else if(mini%2==0)
                {
                    val+=sum[maxi];
                    val-=sum[mini];
                }
                cout<<val<<endl; 
            }
            
        }

    }
}