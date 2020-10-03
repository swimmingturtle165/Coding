#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

     long long t;
    cin>>t;
    while(t--)
    {
         long long r,g,b;
        cin>>r>>g>>b;
         long long mini=min(r,min(g,b));
         long long maxi=max(r,max(g,b));
         long long mid=r+g+b-mini-maxi;
        // if(maxi!=mid)
        // {
        // cout<<mini+min(mid,maxi-mini)<<endl;;
        // }
        // else if(maxi!=mini)
        // {
        //      long long temp=mini;
        //     maxi-=(mini/2 +mini%2);
        //     //mini-=mini/2+mini%2;
        //     mid-=mini/2;
        //     // cout<<maxi<<" "<<mid<<endl;
        //     cout<<temp+min(maxi,mid)<<endl;
        // }
        // else
        // {
            
        //         cout<<(3*r)/2<<endl;
           
            
        // }
        cout<<min((mini+mid),(mini +mid+maxi)/2)<<endl;
        
    }
}