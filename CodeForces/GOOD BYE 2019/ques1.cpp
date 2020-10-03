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
            int n,k1,k2;
            cin>>n>>k1>>k2;
            // map<int,bool> mp1;
            bool ans1=false,ans2=false;
            int maxi1=-1,maxi2=-1;
            for(int i = 0 ; i <k1;i++)
            {
                int temp;
                cin>>temp;
                maxi1=max(maxi1,temp);
                
            }
            for(int i = 0 ; i <k2;i++)
            {
                
                int temp;
                cin>>temp;
                maxi2=max(maxi2,temp);
            }
            if(maxi1>maxi2) 
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
    }
}