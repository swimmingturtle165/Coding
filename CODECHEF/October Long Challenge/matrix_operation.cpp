#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m,q;
        cin>>n>>m>>q;
        long long row[n];
        long long col[m];
        for(long long i = 0 ; i < n;i++)
        {
            row[i]=0;
        }

        for(long long i = 0 ; i < m;i++)
        {
            col[i]=0;
        }
        for(long long i = 0 ; i < q;i++)
        {
            long long x,y;
            cin>>x>>y;
            x--;
            y--;
            row[x]++;
            col[y]++;
        }
        long long even_row=0,even_col=0,odd_row=0,odd_col=0;
         for(long long i = 0 ; i < n;i++)
        {
            if(row[i]%2==0)
            {
                even_row++;
            }
            else
            {
                odd_row++;
            }
            
        }

        for(long long i = 0 ; i < m;i++)
        {
            if(col[i]%2==0)
            {
                even_col++;
            }
            else
            {
                odd_col++;
            }
            
        }
        long long ans=0;
        ans+=even_col*odd_row;
        ans+=even_row*odd_col;
        cout<<ans<<endl;
    }
}