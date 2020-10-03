#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,ans=0;
    cin>>n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>inp[i];
    }
    long long ans1=0,ans2=0;
    for(long long i=0;i<n;i++)
    {
        if(i%2==0)
        {
            ans1+=(inp[i]+1)/2;
            ans2+=(inp[i])/2;
        }
        if(i%2==1)
        {
            ans2+=(inp[i]+1)/2;
            ans1+=(inp[i])/2;
        }
    }
    ans=min(ans1,ans2);
    cout<<ans<<endl;
}