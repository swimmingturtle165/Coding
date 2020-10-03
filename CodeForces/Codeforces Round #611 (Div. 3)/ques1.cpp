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
        int hr,mn;
        cin>>hr>>mn;
        int ans=(23-hr)*60+60-mn;
        cout<<ans<<endl;
    }
}
