#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> position,order;

    for(int i = 0 ; i <n;i++)
    {
        int temp;
        cin>>temp;
        position.push_back(temp);
    }

    for(int i = 0 ; i <n;i++)
    {
        int temp;
        cin>>temp;
        order.push_back(temp);
    }
    vector <bool> done(n+1,false),ans; 
    stack <int> st;
    for(int i =n-1 ; i>=0;i--)
    {
        st.push(position[i]);
    }
    
    for(int i = 0 ; i <n;i++)
    {
        int curr=order[i];
        if(done[curr]==true)
        {
            cout<<0<<" ";
        }
        else
        {
            int del=0;
            int t=-1;
            
            while(t!=curr)
            {
                t=st.top();
                st.pop();
                // cout<<del<<" ";                
                done[t]=true;
                del++;
            }
            cout<<del<<" ";
            
        }
        
    }
    
    cout<<endl;
}