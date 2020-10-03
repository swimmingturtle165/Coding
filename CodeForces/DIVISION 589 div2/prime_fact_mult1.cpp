#include <bits/stdc++.h>
using namespace std;

vector<int> prime_fact(int n)
{
    vector<int> pf;
    map<int,bool> pfs;
    while(n%2==0)
    {
        if (pfs.find(2) == pfs.end() )
        {
        // key 2 doesn't exist
            pfs.insert({2,true});
            pf.push_back(2);
        }
        n=n/2;
    }
    for(int i = 3;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            if (pfs.find(i) == pfs.end() )
            {
            // key 2 doesn't exist
                pfs.insert({i,true});
                pf.push_back(i);
            }

           n=n/i; 
        }
    }
    if(n>2)
    {
       if (pfs.find(n) == pfs.end() )
            {
            // key 2 doesn't exist
                pfs.insert({n,true});
                pf.push_back(n);
            }  
    }
    return pf;
}

long long evaluate(int temp,long long pow)
{
    if(pow==0)
    {
        return 1;
    }
    else
    {
       long long ans=evaluate(temp,pow/2);


         if(ans>=1000000007)
            {
                ans=ans%1000000007;
            }

        ans=ans*ans;

         if(ans>=1000000007)
            {
                ans=ans%1000000007;
            }

        if(pow%2==1)
        {
            ans=ans*temp;
        }
        if(ans>=1000000007)
            {
                ans=ans%1000000007;
            }

            return ans;

    }
}

int main()
{
    int x=0;
    float n=0;
   
    cin>>x>>n;
    
    vector<int> pf=prime_fact(x);
    // display prime factors
   
    // for(int i = 0 ; i < pf.size();i++)
    // {
    //     cout<<pf[i]<<" ";
    // }
    // cout<<"******************"<<endl;
   
   
   
    int ans=1;
    float 
     temp1=n;
    for(int i = 0 ; i <pf.size() ;i++)
    {
        int temp=pf[i];

        float  pow=0;
        while(n>0)
        {
            pow+=(float)n/temp;
            n=n/temp;
        }
       ans=ans* evaluate(temp,pow);
         if(ans>=1000000007)
            {
                ans=ans%1000000007;
            }
            n=temp1;
        cout<<temp<<"--"<<(long long)pow<<endl;

    }
    cout<<ans<<endl;

}

