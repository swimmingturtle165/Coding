#include <bits/stdc++.h>
using namespace std;

void re_evaluate(vector<int>&indexes,vector<int>&inp)
{

    for(int i = 1 ; i < inp.size() ; i ++)
        {
            indexes[inp[i]]=i;
        }

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> inp(n+1,-1);
         vector<int> indexes(n+1,-1);
        for(int i = 1 ; i <= n ; i ++)
        {
            cin>>inp[i];
            indexes[inp[i]]=i;
        }
        int k=n-1, i = 1;
        vector<bool> trns(n+1,false);
        bool flag=true;
        while (k>0 && i<=n)
        {
            if(indexes[i]!=i && k>0)
            {
                int diff=abs(indexes[i]-i);
                int curr=indexes[i];
                while (k>0 && curr!=i  && trns[curr-1]==false)
                {
                    int t1=inp[curr-1],t2=inp[curr];
                    swap(inp[curr-1],inp[curr]);
                    k--;
                    trns[curr-1]=true;
                    indexes[t1]++;
                    indexes[t2]--;
                    curr--;
                }
                
            }
            i++;

        }
        for(int i = 1;i<=n;i++)
        {
            cout<<inp[i]<<" ";
        }
        cout<<endl;
        
    }
}