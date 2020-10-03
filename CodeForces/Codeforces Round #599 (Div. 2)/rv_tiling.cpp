#include <bits/stdc++.h>
using namespace std;
 
vector<long long> prime_fact(long long n)
{
    vector<long long> pf;
    map<long long,bool> pfs;
    while(n%(long long)2==0)
    {
        if (pfs.find(2) == pfs.end() )
        {
        // key 2 doesn't exist
            pfs.insert({2,true});
            pf.push_back(2);
        }
        n=n/2;
    }
    for(long long i = 3;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            // if (pfs.find(i) == pfs.end() )
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
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    
        long long n;
        cin>>n;
        if(n==1 || n==2)
        {
            cout<<n<<endl;
        }
        else
        {
            vector<long long> pf=prime_fact(n);
            int ans=pf.size();
            for(int i =0;i<pf.size()-1;i++)
            {
                long long temp1=pf[i];
                long long temp2=pf[i+1];
                long long val=gcd(temp1,temp2);
                long 

            }
        }
        
        
    
}
