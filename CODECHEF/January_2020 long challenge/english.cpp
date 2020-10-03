#include<bits/stdc++.h>
using namespace std;

typedef     long long int    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(int i=a;i<=b;i++)
#define     FORD(i,b,a)      for(int i=b;i>a;i--)
#define     FORDE(i,b,a)     for(ll i=b;i>=a;i--)
#define     debug(x)         cout<< '>'<<#x<<" : "<<x<<"\n";
#define     debug2(x,y)      cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";
#define     debug3(x,y,z)    cout<< '>'<<#x<<" : "<<x<<"\n"; cout<< '>'<<#y<<" : "<<y<<"\n";cout<< '>'<<#z<<" : "<<z<<"\n";
#define     umap             unordered_map
#define     uset             unordered_set
#define     lb               lower_bound
#define     ub               upper_bound
#define     mp               make_pair
#define     in               insert
#define     s                second
#define     f                first
#define     nn               cout<<"\n"
#define     pb               push_back
#define     testcase         int t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             INT_MAX
#define     minv             INT_MIN
#define     MOD              1000000007
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);

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

template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

ll evaluate(string s1,string s2)
{
    long long ans1=0,ans2=0;
    for(int i = 0 ; i <min(s1.size(),s2.size());i++)
    {
        if(s1[i]==s2[i])
        {
            ans1++;
        }
        else
        {
            break;
        }
        
    }
    for(int i = 0 ; i <min(s1.size(),s2.size());i++)
    {
        if(s1[min(s1.size(),s2.size())-1-i]==s2[min(s1.size(),s2.size())-1-i])
        {
            ans2++;
        }
        else
        {
            break;
        }
        
    }
    return min(ans1,ans2)*min(ans1,ans2);

}
signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       vector<string> inps(n," ");
       FOR(i,0,n)
       {
           cin>>inps[i];
       }
       sort(inps.begin(),inps.end());
       for(int i = 0 ; i <inps.size();i++)
       {
           cout<<inps[i]<<" **  "<<endl;
       }
    //    cout<<endl;
       long long ans=0;
       long long minima=LONG_LONG_MAX;
       for(int i = 0 ; i <n-1;i++)
       {
           ll curr=evaluate(inps[i],inps[i+1]);           
            ans+=curr;
            cout<<curr<<" ** "<<endl;
            minima=min(minima,curr);
       }
       if(n%2==1)
       {
           cout<<ans-minima<<endl;
       }
       else
       {
           cout<<ans<<endl;
       }
       
       


        
    }
    return 0;
}