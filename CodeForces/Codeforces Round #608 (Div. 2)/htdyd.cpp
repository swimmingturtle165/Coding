#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    vector<int> blocks (n,0);
    int count=0;
    vector<int> ones,zeroes;
    // cout<<s<<endl;
    for(int i = 0 ; i <n;i++)
    {
        if(s[i]=='B')
        {
            // cout<<i<<" __ "<<res<<" ";
            count++;
            blocks[i]=1;
            
            res++;
            res=res%2;
            // cout<<res<<endl;
            ones.push_back(i);
        }
        else
        {
            zeroes.push_back(i);
        }
        
        
    }
    // for(int i = 0 ; i <ones.size();i++)
    // {
    //     cout<<s[ones[i]]<<"  "<<ones[i]<<endl;
    // }
    // cout<<res<<endl;
    if(n%2==0 &&(ones.size()%2==1 || zeroes.size()==1))
    {
        cout<<-1<<endl;
    }
    else if(count==0 || count==n)
    {
        cout<<0<<endl;
    }
    else if(ones.size()%2==0)
    {
        int count_step=0;
        vector<int> steps;
        for(int i = 0;i<ones.size()-1;i=i+2)
        {
            int st=ones[i];
            int en=ones[i+1];
            // cout<<st<<" __ "<<en<<endl;
            int diff=en-st;
            
                
                for(int j = st;j<en;j++)
                {
                    steps.push_back(j);
                    count_step++;
                }
            
            
        }
        if(count_step<=3*n)
        {
            cout<<count_step<<endl;
            for(int i = 0 ; i <steps.size();i++)
            {
                cout<<steps[i]+1<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
    else if(zeroes.size()%2==0)
    {
        ones=zeroes;
        int count_step=0;
        vector<int> steps;
        for(int i = 0;i<ones.size()-1;i=i+2)
        {
            int st=ones[i];
            int en=ones[i+1];
            // cout<<st<<" __ "<<en<<endl;
            int diff=en-st;
            
                
                for(int j = st;j<en;j++)
                {
                    steps.push_back(j);
                    count_step++;
                }
            
            
        }
        if(count_step<=3*n)
        {
            cout<<steps.size()<<endl;
            for(int i = 0 ; i <steps.size();i++)
            {
                cout<<steps[i]+1<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
    
    
    
}