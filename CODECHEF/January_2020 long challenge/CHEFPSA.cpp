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

long long power(int n)
{
    if(n==1)
    {
        return 2;
    }
    if(n==0)
    {
        return 1;

    }
    else if(n%2==1)
    {
        long long val=power(n/2);
        val=val%MOD;
        val*=val;
        val=val%MOD;
        val*=2;
        val=val%MOD;
        return val;
    }
    else
    {
        long long val=power(n/2);
        val=val%MOD;
        val*=val;
        val=val%MOD;
        return val;

    }
    
    
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
       map<int,int> cnt;
       long long sum=0;
       vector<int> dup;
       if(n==1)
       {
           long long val1,val2;
           cin>>val1>>val2;
           if(val1==val2)
           {
               cout<<1<<endl;
           }
           else
           {
               cout<<0<<endl;
           }
           continue;
           
       }
       for(int i = 0 ; i <2*n;i++)
       {
           int curr;
           cin>>curr;
           cnt[curr]++;
           sum+=curr;
           if(cnt[curr]==2 )
           {
               dup.pb(curr);
           }           
       }
       
       sum=sum/(n+1);
    //    cout<<sum<<endl;
       cnt[sum]-=2;
       vector<int> div;
    //    int maxi=0;
       for(int i = 0 ; i <dup.size();i++)
       {
        //    if(dup[i]==sum)
        //    {
        //     //    if(cnt[sum]>1 &&div[i]<=sum/2)
        //     //    {
        //     //        div.pb(sum);
        //     //     //    maxi=max(maxi,cnt[dup[i]]);

        //     //    }
        //    }
            if(dup[i]<=sum/2)
           {
            //    maxi=max(maxi,cnt[dup[i]]);
               div.pb(dup[i]);
           }
           
       }
    //    dispvector<int>(div);
    //    sort(div.begin(),div.end());
       long long ans=1;
       ans*=power(n-1-(sum%2==0?cnt[sum]:0));
       ans=ans%MOD;
       
       long long values[n+1];
       values[0]=values[1]=1;
       for(int i = 2 ; i <=n;i++)
       {
           values[i]=values[i-1]*i;
           values[i]=values[i]%MOD;
       }
       ans*=values[n-1];
       ans=ans%MOD;
    //    if(ans==0)
    //    {
    //        ans=MOD;
    //    }
        sort(div.begin(),div.end());
       long long temp1=1,done=0;
       if(sum%2==0 &&div[div.size()-1]== sum/2)
       {
           div.pop_back();
       }
       
       for(int i = 0;i<div.size() ;i++)
       {
        //    cout<<values[cnt[div[i]]] <<" ** "<<cnt[div[i]]<<" && ";
           temp1*=values[cnt[div[i]]] ;
           temp1=temp1%MOD;
           done+=cnt[div[i]];
        //    cout<<temp1<<" ** "<<endl;
       }
    //    cout<<ans<<" "<<ans/temp1<<endl;
       ans=ans/temp1;
       
       cout<<ans<<endl;
       

       
        
    }
    return 0;
}