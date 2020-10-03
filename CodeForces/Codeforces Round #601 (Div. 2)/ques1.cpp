#include<bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int dif=abs(a-b);
        
        int ans=dif/5;

        if(dif%5!=0 &&dif%5<=2)
        {
            ans++;
        }
        else if(dif%5!=0 &&dif%5>2)
        {
            ans+=2;
        }
        
        
        
        cout<<ans<<endl;
        
    }
}
