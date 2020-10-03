#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
        int s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        if(w1==w2 &&w2==w3)
        {
            if(s>=3*w1)
            {
                cout<<1<<endl;
            }
            else if(s>=2*w1)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<3<<endl;
            }
            
        }
        else
        {
            int ans=1;
            vector<int> v{w1,w2,w3};
            // v.push_back(w1,w2,w3);
            int curr=s;
            int ind=0;
            while(ind<3&&curr>=v[ind])
            {
                curr-=v[ind];
                ind++;
                if(ind<3 && curr<v[ind])
                {
                    ans++;
                    curr=s;
                }
            }
            cout<<ans<<endl;
        }
        
    }
}