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
        long r,g,b;
        cin>>r>>g>>b;

        long sum=r+g+b;
        long maxi=max(r,max(g,b));
        long left=sum-maxi;
        if(left+1<maxi)
        {
            cout<<"No"<<endl;
        }        
        else
        {
            cout<<"Yes"<<endl;
        }
        
    }
}
