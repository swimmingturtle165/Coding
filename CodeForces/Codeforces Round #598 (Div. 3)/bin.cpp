#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <int> inp;
        for(int i = 0 ; i <s.size();i++)
        {
            if(s[i]=='0')
            {
                inp.push_back(i);
            }
        }
        int shifted=0;
        int index=-1;
        int shifted_by=-1;
        for(int i = 0 ; i <inp.size();i++)
        {
            if(inp[i]-shifted>=k)
            {
                shifted++;
                k=k-(inp[i]-shifted);
            }
            else if(k>0)
            {
                index=i;
                shifted_by=i-k;
                break;
            }
            
        }
        if(index!=-1)
        {
            int printed=0;
            for(int i = 0 ; i <shifted;i++)
            {
                printed++;
                cout<<'0';
            }
            for(int i = 0 ; i <s.size();i++)
            {
                if(printed==shifted_by)
                {
                    cout<<'0';
                    shifted++;
                    
                }
                if(s[i]=='0')
                {
                    if(shifted>0)
                    {
                        shifted--;
                    }
                    else
                    {
                        cout<<s[i];
                    }
                    
                }
                 else
                    {
                        cout<<s[i];
                    }
            }
        }
        else
        {
            for(int i = 0 ; i <shifted;i++)
            {
                cout<<'0';
            }
            for(int i = 0 ; i <s.size();i++)
            {
                if(s[i]=='0')
                {
                    if(shifted>0)
                    {
                        shifted--;
                    }
                    else
                    {
                        cout<<s[i];
                    }
                    
                }
                 else
                    {
                        cout<<s[i];
                    }
            }
        }
        cout<<endl;
        
    }
}