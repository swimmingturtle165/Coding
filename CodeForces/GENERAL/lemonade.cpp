#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,l;
    cin>>n>>l;
    vector<double> inp;
    for(long i = 0 ; i <n;i++)
    {
        double temp;
        cin>>temp;
        inp.push_back(temp);
    }
    long c=1;
    double mini=INT_MAX;
    int ind=-1;
    int q=-1;
    for(long i = 0 ; i <n;i++)
    {
        inp[i]=inp[i]/c;
        
        if(inp[i]<mini)
        {
            mini=inp[i];
            ind=i;
            q=c;
        }
        c*=2;
    }
    double qu=l/c;
    long ans;
    if(qu<1)
    {
        qu=1;
    }
    else if(qu-long(qu)!=0)
    {
        qu+=1;
    }
    
    ans=qu;
    ans*=inp[ind];
    cout<<ans<<endl;
    
}