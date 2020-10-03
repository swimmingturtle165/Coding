#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long sum=0;
        int flag=0;
        int flag1=false;
        for(int i = 0 ; i <s.size();i++)
        {
            sum+=s[i]-'0';
            if((s[i]-'0')%2==0 &&s[i]!='0')
            {
                flag1++;
            }
           
            
        }
        for(int i = 0 ; i <s.size();i++)
        {            
            
            if(s[i]=='0')
            {
                flag++;
            }
            
        }
        // cout<<s<<" -- "<<flag<<"  "<<flag1<<endl;
        if(sum%3==0 &&flag>0 &&(flag1+flag)>=2)
        {
            cout<<"red"<<endl;
        }
        else
        {
            cout<<"cyan"<<endl;
        }
        
    }
}