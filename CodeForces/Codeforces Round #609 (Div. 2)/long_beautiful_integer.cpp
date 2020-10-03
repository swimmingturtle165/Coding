#include <bits/stdc++.h>
using namespace std;
string increment(string temp)
{
    for(int i = temp.size()-1;i>=0;i--)
    {
        if(temp[i]=='9')
        {
            temp[i]='0';
        }
        else
        {
            temp[i]++;
            return temp;
        }
        
    }
    return temp;
}


bool check(long long k,string s)
{
    for(long long i = 0 ; i <s.size()-k;i++)
    {
        if(s[i]!=s[i+k])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(check(k,s))
    {
        cout<<n<<endl;
        cout<<s<<endl;
    }
    else
    {
        string temp=s.substr(0,k);
        string ans1="";
        for(int i = 0 ; i <n/k;i++)
        {
            ans1+=temp;
        }
        if(n%k!=0)
        {
            ans1+=temp.substr(0,n%k);
        }
        if(ans1>=s)
        {
            cout<<n<<endl;
            cout<<ans1<<endl;
            return 0;
        }
        else
        {
            
            temp=increment(temp);
            ans1="";
                for(int i = 0 ; i <n/k;i++)
            {
                ans1+=temp;
            }
            if(n%k!=0)
            {
                ans1+=temp.substr(0,n%k);
                // ans1+=temp;
            }
            cout<<n<<endl;

            cout<<ans1<<endl;

        }
        

        
    }
    

}