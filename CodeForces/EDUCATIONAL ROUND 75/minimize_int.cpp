#include<bits/stdc++.h>
using namespace std;




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        queue<int> even,odd;

        for(int i = 0 ; i < s.size();i++)
        {
            int temp=s[i]-'0';

            if(temp%2==0)
            {
                even.push(temp);
            }
            else
            {
                odd.push(temp);
            }
            
        }   
        while(even.size()>0 && odd.size()>0)
        {
            if(even.front()>odd.front())
            {
                cout<<odd.front();
                odd.pop();
            }
            else
            {
                cout<<even.front();
                even.pop();
            }
            
        }
        while(even.size()>0)
        {
            cout<<even.front();
                even.pop();
        }
        while (odd.size()>0)
        {
             cout<<odd.front();
                odd.pop();
        }
        cout<<endl;
        
    }
}