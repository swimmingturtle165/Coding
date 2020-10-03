#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
        long a,b,c;
         cin>>a>>b>>c;
        long a1,b1,c1;
        a1=min(a,min(b,c));
         c1=max(a,max(b,c));
         b1=a+b+c-a1-b1;
         a=a1;
         b-b1;
         c=c1;
        if(a==b && b==c )
        {
            cout<<0<<endl;
        }
        else if(a==b)
        {
            if(c-a>1)
            {
            a++;
            b++;
            }
            c--;
            cout<<2*abs(c-a)<<endl;
        }
        else if(b==c)
        {
            if(b-a>1)
            {
                b--;
                c--;
            }
            
            a++;
            cout<<2*abs(c-a)<<endl;
        }
        else if(abs(a-b)==1 && abs(c-b)==1)
        {
            cout<<0<<endl;
        }
        else
        {

            if(abs(a-b)==1 )
            {
                b++;
            }
            else 
            b--;
            
            a++;
            
            c--;
            // cout<<a<<b<<c<<endl;
            
            
            //   cout<<a<<b<<c<<endl;
            cout<<abs(c-a)+abs(c-b)+abs(a-b)<<endl;
        }
        
        
    }
}