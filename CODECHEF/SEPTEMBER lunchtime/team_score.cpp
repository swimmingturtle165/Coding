#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int p1=0,p2=0;
        while(n-->0)
        {
            int c,t1,t2;
            cin>>c>>t1>>t2;
            if(c==1)
            {
                cout<<"YES"<<endl;
                p1=t1;
                p2=t2;
            }
            else
            {
                int mini=min(t1,t2);
                int maxi=max(p1,p2);
                if(maxi >mini )
                {
                    cout<<"YES"<<endl;
                    p1=max(t1,t2);
                    p2=min(t1,t2);
                }
                else if(t1==t2)
                {
                    p1=t1;
                    p2=t2;
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;

                }
                
            }
            
        }
    }
}