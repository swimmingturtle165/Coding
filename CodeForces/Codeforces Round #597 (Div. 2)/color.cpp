#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{ 
    if (a == 0) 
        return b;  

    return gcd(b % a, a);  
 } 
  
   
  long long lcm(long long a, long long b)  
 {  
    return (a*b)/gcd(a, b);  
 }  

void solve(long long a,long long b)
{
    long long sz=lcm(a,b);
    bool arr[sz+1];
    for(long long i = 0 ; i <=sz;i++)
    {
        arr[i]=false;
        if(i==0)
        {
            arr[i]=true;
        }
         if(i>=b && arr[i]==false)
        {
            arr[i]=arr[i-b];
        }
         if(i>=a&& arr[i]==false)
         {
             arr[i]=arr[i-a];
         }
    }
    bool flag=false;
    long long count=0;
    long long mini=min(a,b);
    for(long long i = 0 ; i <=sz;i++)
    {
        while(arr[i]==true && i<=sz)
        {
            count++;
            i++;
        }
        if(count>=mini)
        {
            flag=true;
        }
        count=0;
    }
    if(flag)
    {
        cout<<"Finite"<<endl;
    }
    else
    {
        cout<<"Infinite"<<endl;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
     cin>>t;
     while(t--)
    {
        long long a,b;
         cin>>a>>b;
        solve(a,b);
    }
}