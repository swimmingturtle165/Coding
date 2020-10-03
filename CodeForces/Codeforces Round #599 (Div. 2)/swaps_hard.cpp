#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        string s1,s2;
        cin>>n>>s1>>s2;

        
        vector<int> count(26,0);
        for(int i = 0 ; i <n;i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']++;

        }
        bool mid_test=true;
        for(int i = 0 ; i <26;i++)
        {
            if(count[i]%2==1)
            {
                mid_test=false;
                break;
            }
        }
        if(mid_test==false)
        {
            cout<<"NO"<<endl;
        } 
        else
        {
             vector<vector<int>> str1(26,vector<int>()),str2(26,vector<int>());
             for(int i = 0 ; i<s1.size();i++)
             {
                 if(s1[i]!=s2[i])
                 {
                 str1[s1[i]-'a'].push_back(i);
                 str2[s2[i]-'a'].push_back(i);
                 }
             }

                    int count=0;
             for(int i = 0 ; i <s1.size();i++)
             {
                 if(s1[i]==s2[i])
                 {
                     continue;
                 }
                 else
                 {
                     if(str2[s1[i]-'a'].size()==0)
                     {

                     }
                     else
                     {
                         int temp=str2[s1[i]-'a'][str2[s1[i]-'a'].size()-1];
                         // finding required character in string 2
                         str2[s1[i]-'a'].erase(str2[s1[i]-'a'].begin+str2[s1[i]-'a'].size()-1);
                         // deleting th last occurance of the 
                         char ch=s2[s2.size()-1];
                         

                     }
                     
                 }
                 
             }
        }
        
    }
}