#include <bits/stdc++.h>
using namespace std;

long long solve(long long diff)
{
    long long i=0;
    while(i*i+i<2*diff)
    {
        i++;
    }
    if(i*i +i==2*diff)
    {
        return i;
    }
    else
    {
         long long d=((i*i +i)/2)-diff;
        if(d%2==0)
        {
            return i;
        }
        else
        {
        return i+1;
            
        }
        
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<solve(max(a,b)-min(a,b))<<endl;
    }
}