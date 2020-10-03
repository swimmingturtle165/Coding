#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) 
{ 
    vector<int>conv;
    float temp=log2 (n);
    long st=0;
    if(temp -int(temp)!=0)
    {
        temp++;
    }
    st=temp;
    int sum=0;
    while (n>0)
    {
        long val=n/st;
        
         sum+=val;
        
        st=st/2;
        n=n%st;

    }
    
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,p;
    cin>>n>>p;
    if(n<p+1)
    {
        cout<<-1<<endl;
    }
    else
    {
        bool flag=true;
        int temp=n;
        for(int i = 0 ; i <= temp;i++)
        {
            cout<<n<<"   "<<countSetBits(n)<<"  "<<i<<" **  "<<endl;           
             if(i==countSetBits(n))
             {
                 flag=false;
                 cout<<i<<endl;
                 break;
             }
             n+=p;
        }
        if(flag)
        {
            cout<<-1<<endl;
        }
    }
    
    


}