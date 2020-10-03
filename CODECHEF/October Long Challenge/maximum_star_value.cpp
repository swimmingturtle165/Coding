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
        long long n;
        cin>>n;
        int arr[n];
        bool possible_ans[n];
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
            possible_ans[i]=true;
        }
        int ans=0;
        for(int i =n-1 ;i>0;i--)
        {
            if(possible_ans[i])
            {
                int curr=0;
                for(int j = i-1;j>=0;j--)
                {
                    if(arr[j]%arr[i]==0)
                    {
                        curr++;
                        possible_ans[j]=false;
                    }
                }
                ans=max(curr,ans);
            }
        }
        cout<<ans<<endl;
    }
