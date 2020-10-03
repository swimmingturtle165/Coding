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
        long long v1,c2,n,sum;
        cin>>n>>c2>>v1>>sum;
        if(v1*n+c2<sum)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(sum%v1 > c2)
            {
                 cout<<"NO"<<endl;
            }
            else
            {
                 cout<<"YES"<<endl;
            }
            
        }
        
    }
}