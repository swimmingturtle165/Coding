#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        long count=0;
        for(int i = 0 ;i<str.size();i++)
        {
            if(str[i]=='1')
            {
                count++;
            }
        }
        if(count%2==0)
        {
            cout<<"LOSE"<<endl;
        }
        else
        {
            cout<<"WIN"<<endl;
        }
        
    }
}