#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long arr[n];
        long long ans[n];
        for(long long i = 0 ; i < n;i++)
        {
            cin>>arr[i];

            ans[i]=arr[i];
        }
        // if(n>=k)
        // {
        //     for(long long i = 0 ; i <k;i++)
        //     {                
        //         arr[i]=(arr[i]^arr[n-i-1]);            
        //     }
        //     for(long long i = 0 ; i < n;i++)
        //     {
        //         cout<<arr[i]<<" ";
        //     }

        // }
        // else
        // {
            long long mov=k%(3*n);
           
            for(long long i = 0 ; i < mov;i++)
            {
                long index;
                
                 index=i%n;
                
                ans[index]=(ans[index]^ans[n-index-1]);
            }
            
            
        //     if(mov%3==1)
        //     {
        //         for(long long i = 0 ; i <n/2;i++)
        //         {
        //             ans[i]=(arr[i]^arr[n-i-1]);
        //         }
        //         if(n%2==1)
        //         {
        //             ans[n/2]=0;
                    
        //         }
        //         for(long long i = (n+1)/2;i<n;i++)
        //         {
        //             ans[i]=arr[n-i-1];
        //         }
        //     }
        //     if(mov%3==2)
        //     {
        //          for(long long i = 0 ; i <n/2;i++)
        //         {
        //             ans[i]=arr[n-i-1];       
        //         }
        //         if(n%2==1)
        //         {
        //             ans[n/2]=0;
        //         }
        //         for(long long i = (n+1)/2;i<n;i++)
        //         {
        //             ans[i]=(arr[i]^arr[n-i-1]);
        //         }
        //     }
        //     else
        //     {
        //          for(long long i = 0 ; i <n/2;i++)
        //         {
        //             ans[i]=arr[i];       
        //         }
        //         if(n%2==1)
        //         {
        //             ans[n/2]=0;
        //         }
        //         for(long long i = (n+1)/2;i<n;i++)
        //         {
        //             ans[i]=arr[i];
        //         }
        //     }
        //     for(long long i = 0 ; i <k%n;i++)
        //     {
        //         ans[i]=(ans[i]^ans[n-i-1]);
        //     }
        if(n%2==1 && n/2<k)
        {
            ans[n/2]=0;
        }
            for(long long i = 0 ; i < n;i++)
            {
                cout<<ans[i]<<" ";
            }
        
         cout<<endl;

    }
}