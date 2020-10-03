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
        int n;
        cin>>n;
        int arr[n];
        long long sum=0,val=0;
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            val=val xor arr[i];
        }
        if(val*2==sum)
        {
            cout<<0<<endl;
            cout<<endl;
        }
        
        else
        {
            cout<<2<<endl;
            cout<<val<<" "<<sum+val<<endl;
        }
        
   }
}