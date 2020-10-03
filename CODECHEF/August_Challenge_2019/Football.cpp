#include<bits/stdc++.h>
using namespace std;


int main()
 {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    long t;
    cin>>t;
     while(t--)
    {
       long long ans=0;
       int n;
       cin>>n;
       int arr_goals[n];
       int arr_penalties[n];
       
       for(int i = 0 ; i< n;i++)
       {
           cin>>arr_goals[i];
          // cout<<arr_goals[i]<<" ";
       }
       //cout<<endl;
       for(int i = 0 ; i< n;i++)
       {
           cin>>arr_penalties[i];
          // cout<<arr_penalties[i]<<" ";
       }
      // cout<<endl;
      for(int i = 0 ; i< n;i++)
       { 
          long long temp=(arr_goals[i]*20 )- (arr_penalties[i]*10);
          if(temp>0)
          {
              ans=max(temp,ans);
          } 
       }
       cout<<ans<<endl;
    }  
 }