#include <bits/stdc++.h>
using namespace std;




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
        long long diff=abs(b-a);
        for(long long i = 0 ; i <1000000000;i++)
        {
            long long sum=i*(i+1)/2;
            if(sum>=diff)
            {
                if((sum+diff)%2==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}