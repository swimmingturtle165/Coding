#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a,b,c,d,c1,c2;
    cin>>a>>b>>c>>d>>c1>>c2;
    long long highercost,lowercost,higherorder,lowerorder;
    if(c1<c2)
    {
        higherorder=min(b,min(c,d));
        d-=higherorder;
        highercost=c2;

        lowerorder=min(a,d);
        lowercost=c1;
    }
    else
    {
        

        higherorder=min(a,d);
        highercost=c1;
        d-=higherorder;

        lowerorder=min(b,min(c,d));
        lowercost=c2;

    }
    long long ans=highercost*higherorder +lowercost*lowerorder;
    cout<<ans<<endl;
    
}