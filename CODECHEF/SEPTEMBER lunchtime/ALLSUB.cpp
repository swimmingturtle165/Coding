#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t-->0)
    {
    string r,s,ans;

    cin>>s>>r;
    //cout<<"**********"<<r<<" ** "<<s<<endl;
    int arr[26];
    bool flag=true;
    for(int i = 0 ; i <26;i++)
    {
        arr[i]=0;
    }
    for(int i = 0 ; i < r.size();i++)
    {
        char ch=r[i];
        arr[ch-'a']++;
    }
    for(int i = 0 ; i < s.size();i++)
    {
        char ch=s[i];
        arr[ch-'a']--;
        if(arr[ch-'a']<0)
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        long count=1;
        for(int i = 0 ; i < s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        //cout<<count<<"************"<<endl;
        if(count==s.size() || arr[s[0]-'a']==0)
        {
            for(int i = 0 ; i <=s[0]-'a';i++)
            {
            char ch='a'+i;
            for(int j = 0 ; j < arr[i];j++)
                {
                ans+=ch;
                }
            }
         ans+=s;
            for(int i = s[0]-'a' +1; i <26;i++)
            {
            char ch='a'+i;
            for(int j = 0 ; j < arr[i];j++)
                {
                ans+=ch;
                }
            }
        }
        else
        {
            
            if(s[0]-'a' < s[count]-'a' )
            {
                        for(int i = 0 ; i <=s[0]-'a';i++)
                    {
                    char ch='a'+i;
                    for(int j = 0 ; j < arr[i];j++)
                        {
                        ans+=ch;
                        }
                    }
                ans+=s;
                    for(int i = s[0]-'a'+1 ; i <26;i++)
                    {
                    char ch='a'+i;
                    for(int j = 0 ; j < arr[i];j++)
                        {
                        ans+=ch;
                        }
                    }
            }
            else
            {
                    for(int i = 0 ; i <s[0]-'a';i++)
                {
                char ch='a'+i;
                for(int j = 0 ; j < arr[i];j++)
                    {
                    ans+=ch;
                    }
                }
                ans+=s;
                for(int i = s[0]-'a' ; i <26;i++)
                {
                char ch='a'+i;
                for(int j = 0 ; j < arr[i];j++)
                    {
                    ans+=ch;
                    }
                }
            }
            
        }
        
        cout<<ans<<endl;
    }
    else
    {
        cout<<"Impossible" <<endl;
    }
    

    }
}