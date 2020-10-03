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

        int count=0;
        vector<char> ch1,ch2;
        for(int i = 0 ; i <n;i++)
        {
            if(s1[i]!=s2[i])
            {
                ch1.push_back(s1[i]);
                ch2.push_back(s2[i]);
                count++;
            }
        }
        if(count>2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(ch1[0]==ch1[1] &&ch2[0]==ch2[1])
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