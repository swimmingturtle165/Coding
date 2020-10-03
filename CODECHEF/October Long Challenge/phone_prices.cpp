#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n;i++)
        {
            cin>>arr[i];
        }
        int ans=0;
        int c_v=INT_MAX;
        int c_i=0;
        for(int i = 0 ; i < n;i++)
        {
           
             if(i-c_i>5)
            {
                c_i++;
                c_v=arr[c_i];
                       
                for(int j = c_i;j<i;j++)
                {
                    if(c_v>arr[j])
                    {
                        c_v=arr[j];
                        c_i=j;
                    }
                }
            }

            if(arr[i]<c_v)
                 {
                ans++;
                c_v=arr[i];
                c_i=i;
                 }
        }
        cout<<ans<<endl;
    }
}
