#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,money;
    cin>>n>>money;
    vector<long long> prices,array_sum,sorted_prices,sorted_prices_sum;
    long long curr=0;
    long long mini=INT_MAX;
    for(int i = 0 ; i <n;i++)
    {
        long long temp;
        cin>>temp;
        mini=min(mini,temp);
        curr+=temp;
        prices.push_back(temp);
        sorted_prices.push_back(temp);
        array_sum.push_back(curr);
    }
    // sort(sorted_prices.begin(),sorted_prices.end());
    
    long long ans=n*(money/curr);
    money=money%curr;
    long long temp=0,inx=0;
    while(mini<=money)
    {
        curr=0;
        // cout<<ans<<endl;
        while(array_sum[temp]<=money)
        {
        temp++;
        // temp=temp%n;  

        }
        
        if(temp!=0)
        {
        inx+=temp;
        ans+=temp;
        temp--;

        money-=array_sum[temp];
        curr=array_sum[temp];
        }
        for(int i = temp;i<n;i++)
        {
            if(prices[i]<=money)
            {
                inx++;
                ans++;
                curr+=prices[i];
                money-=prices[i];
            }
        }
        ans+=inx*(money/curr);
        money=money%curr;
        temp=0;
        inx=0;
        curr=0;
    }
    cout<<ans<<endl;
}