#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int n=s.size();
        
        if(s[n-1]=='o')
        {
            cout<<"FILIPINO"<<endl;
        }
        else if(s[n-1]=='u')
        {
            cout<<"JAPANESE"<<endl;
        }
        else
        {
            cout<<"KOREAN"<<endl;
        }
        
    }
}