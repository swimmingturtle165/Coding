#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &inp,int i,int j)
{
    int temp=inp[i];
    inp[i]=inp[j];
    inp[j]=temp;
}

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
        for(int i = 0 ; i <n;i++)
        {
            int temp;
            cin>>temp;
            inp.push_back(temp);
        }
        int done = 0;
        int curr=0;
        while(done<inp.size() && curr<inp.size())
        {
            if(inp[curr]!=curr+1)
            {
                int curr_ind=-1;
                for(int j = curr ; j <inp.size();j++)
                {
                    if(inp[j]==curr+1)
                    {
                        curr_ind=j;
                        break;
                    }
                }
                int req=curr_ind-curr;
                // cout<<curr_ind<<" "<<curr<<" "<<done<<endl;
                if(req+done<inp.size())
                {
                    inp.erase(inp.begin()+curr_ind);
        //             for(int i = 0 ; i <inp.size();i++)
        // {
        //     cout<<inp[i]<<" ";
        // }
        // cout<<endl;
                    inp.insert(inp.begin()+curr,curr+1);   
                   
                    done+=req;
                }
                else
                {
                    inp.erase(inp.begin()+curr_ind);
                    int movesleft=inp.size()-done;
                    inp.insert(inp.begin()+curr_ind-movesleft,curr+1); 
                    done=INT_MAX;
                    break;
                }
                
            }
            curr++;
        }

        for(int i = 0 ; i <inp.size();i++)
        {
            cout<<inp[i]<<" ";
        }
        cout<<endl;
    }
}