#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        unsigned long long  n,k;
        cin>>n>>k;
        if(k==1 || (n/k)%k==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }        

    }
}