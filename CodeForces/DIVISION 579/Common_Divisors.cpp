#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long gcd=0;
    long long* ans=new long long[n];
    for(long long i = 0 ; i < n ; i++)
    {
        
        cin>>ans[i];
        if(i==0)
        {
        gcd=ans[0];
        }
        else
        {
            gcd=__gcd(gcd,ans[i]);
        }
        
    }
    long long count=0;
    for(long long i =1;i*i<=gcd;i++)
    {
        if(gcd%i==0)
        {
            count+=2;
            if(i==gcd/i)
            {
            count--;
            }
        }
        
    }
    cout<<count<<endl;
    
}