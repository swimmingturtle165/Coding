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
        bool ans1=true;
        if(s.size()==1)
        {
            if(s[0]=='?')
            {
                cout<<'a'<<endl;
                
            }
            else
            {
                cout<<s<<endl;
            }
            continue;
            
        }
        for(int i = 0 ; i <s.size()-1;i++)
        {
            if(s[i]==s[i+1] && s[i]!='?')
            {
                ans1=false;
                break;
            }
        }
        if(ans1==false)
        {
            cout<<-1<<endl;
        }
        
        else
        {
            // for(int i = 0 ; i <s.size();i++)
            // {
            //     if(s[i]=='?')
            //     {
            //         if(i==0)
            //         {
            //             if(s[i+1]=='?')
            //             {
            //                 s[i]='a';
            //             }
            //             else
            //             {
            //                 if(s[i+1]=='a')
            //                 {
            //                     s[i]='b';
            //                 }
            //                 if(s[i+1]=='b')
            //                 {
            //                     s[i+1]='a';
            //                 }
            //                 if(s[i+1]=='c')
            //                 {
            //                     s[i]='b';

            //                 }
            //             }
                        
            //         }
            //         else  if(i==s.size()-1)
            //         {
            //             if(s[i-1]=='a')
            //                 {
            //                     s[i]='b';
            //                 }
            //                 else if(s[i-1]=='b')
            //                 {
            //                     s[i+1]='a';
            //                 }
            //                 if(s[i-1]=='c')
            //                 {
            //                     s[i]='b';

            //                 }
            //         }
            //         else
            //         {
            //             if(s[i-1]=='a' && (s[i+1]=='b' || s[i+1]=='a'))
            //             {
            //                 s[i]='c';
            //             }
            //             else if(s[i-1]=='a' && s[i+1]=='c')
            //             {
            //                 s[i]='b';
            //             }
            //             else if(s[i-1]=='b' && (s[i+1]=='b' || s[i+1]=='a'))
            //             {
            //                 s[i]='c';
            //             }
            //             else if(s[i-1]=='b' && s[i+1]=='c')
            //             {
            //                 s[i]='a';
            //             }
            //             else if(s[i-1]=='c' && (s[i+1]=='c' || s[i+1]=='a'))
            //             {
            //                 s[i]='b';
            //             }
            //             else if(s[i-1]=='c' && s[i+1]=='b')
            //             {
            //                 s[i]='a';
            //             }
            //             else
            //             {
            //                 if(s[i-1]=='c')
            //                 {
            //                     s[i]='a';
            //                 }
            //                 else
            //                 {
            //                     s[i]=s[i-1]+1;
            //                 }
                            
            //             }

            //         }
                    
            //     }
            // }
            // for(int i = 0 ; i <s.size();i++)
            // {
            //     if(s[i]=='?')
            //     {
            //         if(i==0)
            //         {
            //             if(s[i+1]=='?')
            //             {
            //                 s[i]='a';
            //             }
            //             else
            //             {
            //                 if(s[i+1]=='a')
            //                 {
            //                     s[i]='b';
            //                 }
            //                 if(s[i+1]=='b')
            //                 {
            //                     s[i+1]='a';
            //                 }
            //                 if(s[i+1]=='c')
            //                 {
            //                     s[i]='b';

            //                 }
            //             }
            //         }
            //         else if(i!=s.size()-1 && (s[i+1]=='?' ||s[i-1]==s[i+1]))
            //         {
            //             if(s[i-1]=='c')
            //                 {
            //                     s[i]='a';
            //                 }
            //                 else
            //                 {
            //                     s[i]=s[i-1]+1;
            //                 }
            //         }
            //         else if(s[i+1]!=s[i-1])
            //         {
            //             int sum='a'+'b'+'c';
            //             int diff=s[i-1]+s[i+1];

            //             char ch=sum-diff;
            //             s[i]=ch;
            //             // cout<<s[i]<<endl;
            //         }
                    
                    
                    
            //     }
            // }
            int len=s.size();
            string ans='?'+s+'?';
            s=ans;
            for(int i = 1 ; i <ans.size()-1;i++)
            {
                if(s[i]=='?')
                {
                    if(s[i-1]=='a' || s[i-1]=='?')
                    {
                        s[i]='b';
                        if(s[i+1]=='b')
                        {
                            s[i]='c';
                        }
                    }
                    else if(s[i-1]=='b' || s[i-1]=='?')
                    {
                        s[i]='a';
                        if(s[i+1]=='a')
                        {
                            s[i]='c';
                        }
                    }
                    else if(s[i-1]=='c' || s[i-1]=='?')
                    {
                        s[i]='b';
                        if(s[i+1]=='b')
                        {
                            s[i]='a';
                        }
                    }
                }
            }
            ans=s.substr(1,len);
            cout<<ans<<endl;
        }
        
    }
}