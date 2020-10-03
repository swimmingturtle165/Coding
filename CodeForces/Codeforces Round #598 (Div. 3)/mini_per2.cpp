#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>inp;
        vector<int>mis_managed;
        for(int i = 0 ; i <n;i++)
        {
            int temp;
            cin>>temp;
            inp.push_back(temp);
            if(temp!=i+1)
            {
                mis_managed.push_back(i+1);
            }
        }
        if(mis_managed.size()>1)
        {
            bool falg=false;
            int temp1=-1;
            int mov_left=inp.size()-1;
            int val=-1;
            while(mov_left>0 && mis_managed.size()>0)
            {
                int temp=mis_managed[0];
                for(int i = 0 ; i <inp.size();i++)
                {
                    if(inp[i]==temp)
                    {
                        temp=i;
                        break;
                    }
                }
                int curr_ind=temp;
                int correct_pos=inp[curr_ind];
                if(correct_pos-curr_ind<mov_left)
                {
                    mov_left=mov_left-(correct_pos-curr_ind);
                    mis_managed.erase(inp.begin());

                }
                else
                {
                    falg=true;
                    val=mis_managed[0];
                    mis_managed.erase(inp.begin());
                    temp1=correct_pos-mov_left;
                }
                
            }
            if(mis_managed.size()==0)
            {
                       for(int i = 0 ; i <inp.size();i++)
                        {
                            cout<<i+1<<" ";
                        }
                        cout<<endl;
            }
            else
            {
                if(falg)
                {
                    for(int i = 1 ; i <val;i++)
                    {
                        cout<<i<<" ";
                    }
                    int prin=val-1;
                    for(int j=0;j<inp.size();j++ )
                    {
                        if(prin==temp1)
                        {
                            cout<<val<<" ";
                            prin++;
                            j--;
                        }
                        else if(inp[j]>=mis_managed[0])
                        {
                            cout<<inp[j]<<" ";
                        }
                    }
                }
                else
                {
                        for(int i = 1 ; i <mis_managed[0];i++)
                    {
                        cout<<i<<" ";
                    }
                    for(int i = 0 ; i <inp.size();i++)
                    {
                        if(inp[i]>=mis_managed[0])
                        {
                            cout<<inp[i]<<" ";
                        }
                    }
                }
                
                
                cout<<endl;
            }
            
        }
        else
        {
                for(int i = 0 ; i <inp.size();i++)
            {
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
        
        
        
    }
}