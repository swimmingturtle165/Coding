#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int u,d,l,r;
        u=d=l=r=0;
        for(int i = 0 ; i <s.size();i++)
        {
            if(s[i]=='L')
            {
                l++;
            }
            else if(s[i]=='R')
            {
                r++;
            }
            else if(s[i]=='U')
            {
                u++;
            }
            else
            {
                d++;
            }
            
        }
        int v=min(u,d);
        int h=min(l,r);
        if(v==0 && h==0)
        {
            cout<<0<<endl;
            cout<<endl;
        }
        else if(v==0 || h==0)
        {
            if(v==0)
            {
                cout<<2<<endl;
                cout<<"LR"<<endl;

            }
            else
            {
                cout<<2<<endl;
                cout<<"UD"<<endl;
            }
            
        }
        else
        {
            cout<<2*(v+h)<<endl;
            string ans="";
            for(int i = 0;i<v;i++)
            {
                ans+='U';
            }
            for(int i = 0 ; i <h;i++)
            {
                ans+="L";
            }
            for(int i = 0;i<v;i++)
            {
                ans+='D';
            }
            for(int i = 0 ; i <h;i++)
            {
                ans+="R";
            }
            cout<<ans<<endl;
        }
        
    }
}