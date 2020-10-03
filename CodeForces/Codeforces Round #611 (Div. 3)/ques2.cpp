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
        int n,k;
        cin>>n>>k;
        int rem=n%k;
        int ans=n-rem+min(rem,k/2);
        cout<<ans<<endl;
    }
}
