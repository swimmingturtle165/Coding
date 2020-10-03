#include <bits/stdc++.h>
using namespace std;


string convert (long long val,long long base)
{
    //converts a number into n-base 

    string ans="";
    while(val>0)
    {
        long long temp=val%base;

        char ch=temp<=9?temp+'0':temp-10+'A';

        ans=ch+ans;

        val=val/base;

    }
    return ans;
}

vector<string> get_values(long long val)
{
    //gives string of values of a particular number in each base from 2-36
    vector <string> list;
    if(val>1000000000000)
    {
        return list;
    }
    for(int i = 0 ; i < 2;i++)
    {
        list.push_back("**");
    }
    for(int i = 2;i<=36;i++)
    {
        string  temp=convert(val,i);
        
        list.push_back(temp);
    }
   
     return list;
}
int main()
{
    long long n;
    cin>>n;
    vector<string> values=get_values(n);
    for(int i = 0 ; i < values.size();i++)
    {
        cout<<-1<<" "<<values[i]<<endl;
    }
}