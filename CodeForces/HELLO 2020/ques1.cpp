#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long n,m;
    cin>>n>>m;
    vector<string> first,second;
    first.push_back(" ");
    second.push_back(" ");

    for(int i = 0 ; i <n;i++)
    {
        string temp;
        cin>>temp;
        first.push_back(temp);
    }
    for(int i = 0 ; i <m;i++)
    {
        string temp;
        cin>>temp;
        second.push_back(temp);
    }
    long q;
    cin>>q;
    while(q--)
    {
        long num;
        cin>>num;
        long r1,r2;
        r1=num%n;
        r2=num%m;
        if(r1==0)
        {
            r1+=n;
        }
        if(r2==0)
        {
            r2+=m;
        }
        if(first[r1]==second[r2])
        {
            
        }
        cout<<first[r1]<<second[r2]<<endl;
    }
}