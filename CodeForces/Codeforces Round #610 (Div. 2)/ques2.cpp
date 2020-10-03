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
        long n,p,k,ans=0;
        cin>>n>>p>>k;
        int arr[n];
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long sum_arr[n+1],temp=0;
        sum_arr[0]=0;
        for(int i = 0 ; i <n;i++)
        {
            sum_arr[i+1]=temp+arr[i];
            temp=sum_arr[i+1];
        }
        if(n==k)
        {
            if(p<arr[n-1])
            {
                for(int j = 1 ; j <n+1;j++)
                {
                    if(sum_arr[j]<=p)
                    {
                        //  cout<<p<<" ** "<<sum_arr[j]<<endl;
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
            else
            {
                ans=n;
                
            }
            cout<<ans<<endl;
            continue;
            
        }
        int initial_money=p,best_ans=0;

        for(int i = 0 ; i <min(n,k);i++)
        {
            int curr=i,ans=i;
            p=initial_money-sum_arr[i];
            if(p<0)
            {
                continue;
            }
            // cout<<p<<endl;
        while(curr<n && curr+k-1<=n-1 && p>=arr[curr+k-1])
        {
            ans+=k;
            p-=arr[curr+k-1];
            curr+=k;
        }
        while(curr<=n-1 &&p>=arr[curr])
        {
            ans++;
            p-=arr[curr];
            curr++;
        }
        best_ans=max(best_ans,ans);
        if(best_ans==n)
        {
            break;
        }
        
        }
        cout<<best_ans<<endl;
    }
}
