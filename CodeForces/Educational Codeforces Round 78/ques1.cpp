#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int>& src,vector<int>&dst)
{
    for(int i = 0 ; i <26;i++)
    {
        if(src[i]!=dst[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1==s2)
        {
            cout<<"YES"<<endl;

        }
        else
        {
            vector<int> input(26,0),output(26,0);
        
            for(int i = 0 ; i <s1.size();i++)
            {
                input[s1[i]-'a']++;
                output[s2[i]-'a']++;
            }
            bool flag=checker(input,output);
                if(flag==true)
                {
                cout<<"YES"<<endl;
                continue;
                } 
            for(int j = s1.size() ; j <s2.size();j++)
            {
               
                output[s2[j]-'a']++;
                output[s2[j-s1.size()]-'a']--;
                 flag=checker(input,output);
                if(flag==true)
                {
                break;
                } 

            }  
            if(flag==true)
            {
                cout<<"YES"<<endl;

            } 
            else
            {
                cout<<"NO"<<endl;
            }
            
        }       
        
    }
}