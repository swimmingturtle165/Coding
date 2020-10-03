#include <bits/stdc++.h>
using namespace std;



bool solve(int a,int b)
{
    if(a==1 || b==1)
    {
        return true;
    }
    if(a==b  || gcd(a,b)!=1)
    {
        return false;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
     cin>>t;
     while(t--)
    {
        long long a,b;
         cin>>a>>b;
       bool flag= solve(a,b);
       if(flag)
    {
        cout<<"Finite"<<endl;
    }
    else
    {
        cout<<"Infinite"<<endl;
    }
    }
}