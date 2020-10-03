#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n,m;
    long long ans=INT_MAX;
    cin>>n>>m;
   vector< long long >arr1(n,0),arr2(n,0);
    
    for(long long i = 0 ; i <n;i++)
    {
        cin>>arr1[i];        
    }
    
    for(long long i = 0 ; i <n;i++)
    {
        cin>>arr2[i]   ;     
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(long long i = 0 ; i <n;i++)
    {
        long long diff=(arr2[i]-arr1[0])%m;
        if(diff<0) diff+=m;
        // cout<<diff<<endl;
        bool flag=true;
        for(long long j = 0 ; j <n;j++)
        {
            if((m+arr2[(i+j)%n]-arr1[j])%m!=diff)
            {
                flag=false;
                break;
            }
        }     
        if(flag)
        {
                ans=min(ans,diff);

        }  
    }
    cout<<ans<<endl;   
   
    
    
}