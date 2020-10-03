#include<bits/stdc++.h>
#include <stdint.h>
using namespace std;



signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    unsigned long long  n,p,w,d;
    cin>>n>>p>>w>>d;   
   
        bool flg=false;
        for(unsigned long long y =0;y<w;y++)
        {
           unsigned long long temp=(p-y*d);
            if(temp%w!=0)
            {
                continue;
            }
            else
            {
               unsigned long long x=temp/w;
                if(x+y<=n)
                {
                    cout<<x<<" "<<y<<" "<<n-x-y<<endl;
                     flg=true;
                    break;
                }
            }

            
        }
        if(!flg)
            {
               cout<<"-1";
                return 0;
                
            }
    
    
    
}





