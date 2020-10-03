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
        map<int,bool> mp;
        for(int i = 0 ; i <n;i++)
        {
            cin>>arr[i];
                       
        }
        bool ans=false;
        for(int i = 0 ; i <n-1 && ans==false;i++)
        {
            if(abs(arr[i]-arr[i+1])>1)
            {
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<i+2<<endl;
                ans=true;
            }
        }
        if(ans==false)
        {
            cout<<"NO"<<endl;
        }

    }
}