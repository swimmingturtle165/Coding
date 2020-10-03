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
        long a,b,c,r,ans=0;
        cin>>a>>b>>c>>r;
        if(a>b)
        {
            swap(a,b);
        }
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        if(a<=c && b>=c)
        {
            if(c-a>r)
            {
                ans+=c-a-r;
            }
            if(b-c>r)
            {
                ans+=b-c-r;
            }
        }
        else if(a>c)
        {
            if(a-c>r)
            {
                ans=b-a;
            }
            else if(b-c<=r)
            {
                ans=0;
            }
            else 
            {
                ans=b-(c+r);
            }
        }
        else if(b<c)
        {
            if(c-b>r)
            {
                ans=b-a;
            }
            else if(c-a<=r)
            {
                ans=0;
            }
            else 
            {
                ans=c-r-a;
            }
        }
        cout<<ans<<endl;
    }
}
