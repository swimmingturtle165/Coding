#include <bits/stdc++.h>
using namespace std;

long long evaluate(long long n)
{
    if(n==0)
    {
        return 1;
    }
    long long temp=evaluate(n/2);
   temp= temp%1000000007;
    temp=temp*temp;
  temp=   temp%1000000007;
     if(n%2==1)
     {
         temp*=2;
            temp=  temp%1000000007;

     }
     return temp;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    bool flag=false;
    cin>>s;
    long long cn=0;
    long long ans=1;
    for(long long i = 0 ; i <s.size()-1;i++)
    {
        long long cn=0;
        while(s[i]=='u' && s[i+1]=='u' && i<=s.size()-2)
        {
            flag=true;
            cn++;
            i++;
        }       
        if(cn>1)
        {
             long long temp=evaluate(cn);
            temp-=cn;
            temp++;
            ans=temp*ans;
            ans=ans%1000000007;

        }
        else if(cn==1)
        {
            ans*=2;
            ans=ans%1000000007;

        }
        cn=0;
        
    }
      ans=ans%1000000007;
    for(long long i = 0 ; i <s.size()-1;i++)
    {
        long long cn=0;
        while(s[i]=='n' && s[i+1]=='n' && i<=s.size()-2)
        {
            flag=true;

            cn++;
            i++;
        }       
        if(cn>1)
        {
            long long temp=evaluate(cn);
            temp-=cn;
            temp++;
            ans=temp*ans;
            ans=ans%1000000007;

         

        }
        else if(cn==1)
        {
            ans*=2;
            ans=ans%1000000007;
        }
        cn=0;

        

    }
    if(flag)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
    
}