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
        double sum=0;
        for(int i = 0 ; i <n;i++ )
        {
            int temp;
            cin>>temp;
            sum+=temp;
        }
        sum=sum/n;
        if(sum-(int)sum!=0)
        {
            sum++;
        }
        int ans=sum;
        cout<<ans<<endl;
    }
}