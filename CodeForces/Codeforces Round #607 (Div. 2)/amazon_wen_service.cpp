#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2,sorted;
        cin>>s1>>s2;
        map<char,int> mp;
        for(int i = 0 ; i <s1.size();i++)
        {
            sorted+=s1[i];
            mp[s1[i]]=i;
        }
        sort(sorted.begin(),sorted.end());
  
        for(int i = 0 ; i <s1.size();i++)
        {
            if(s1[i]!=sorted[i])
            {
                swap(s1[i],s1[mp[sorted[i]]]);
                break;
            }
        }
        if(s1<s2)
        {
            cout<<s1<<endl;
        }
        else
        {
            cout<< "---" <<endl;
        }
        
    }
}