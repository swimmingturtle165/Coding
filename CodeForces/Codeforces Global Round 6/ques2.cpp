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
        long long num,q=14;
        cin>>num;
        // bool ans=solve(0,0,num);
        long long anw=num%q;
        if(num>14 &&(anw<=6 && anw>0))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}