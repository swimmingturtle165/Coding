#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long  t;
    cin>>t;
    while(t--)
    {
        long long  a,b,k;
        cin>>a>>b>>k;
        long long  v=__gcd(a,b);
        if(v!=1)
        {
            a=a/v;
            b=b/v;
            
        }
        if(a>b)
        {
            swap(a,b);
        }
        if(a*(k-1)+1>=b)
        {
            cout<<"OBEY"<<endl;
        }
        else
        {
            cout<<"REBEL"<<endl;
        }
        
        
    }
}