#include <bits/stdc++.h>
using namespace std;




bool check(string s1,string s2)
{
    int count=0;
    for(int i = 0 ; i  <min(s1.size(),s2.size());i++)
    {
        if(s1[i]>s2[i])
        {
            count++;
            if(count==2)
            {
                cout<<"---"<<endl;
                return;
            }
            bool done=false;
            for(int j = i+1;j<s1.size();j++)
            {
                if(s1[j]<s2[i])
                {
                    done=true;
                    char temp=s1[i];
                    s1[i]=s1[j];
                    s1[j]=temp;
                }
            }
            if(done==false)
            {
                for(int j = i+1;j<s1.size();j++)
                {
                    if(s1[j]==s2[i])
                    {
                        if(j>=s1.size())
                    }
                }
            }
        }
        
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
    }
}