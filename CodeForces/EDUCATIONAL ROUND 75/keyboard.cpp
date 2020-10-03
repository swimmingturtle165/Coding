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

        bool inp[26],work[26];
        for(int i = 0 ; i < 26;i++)
        {
            inp[i]=false;
            work[i]=false;
        }
        for(int i = 0 ; i < s.size();i++)
        {
            inp[s[i]-'a']=true;
        }

        int i = 0 ;

        while(i<s.size())
        {
            int temp=1;
            while(s[i]==s[i+temp])
            {
                temp++;
            }
            
            if(temp%2==1)
            {
                work[s[i]-'a']=true;
            }
            i=i+temp;            
        }
        vector<char> sep;
        for(int i = 0 ; i < 26;i++)
        {
            if(inp[i] && work[i])
            {
                sep.push_back(i+'a');
            }
        }
        for(int i = 0 ; i <sep.size();i++)
        {
            cout<<sep[i];
        }
        cout<<endl;
    }


}