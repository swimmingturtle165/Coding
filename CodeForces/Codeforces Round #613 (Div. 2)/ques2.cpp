#include<bits/stdc++.h>
using namespace std;

typedef     long long    ll;
typedef     long double      ld;
typedef     pair<ll,ll>      pll;
#define     FOR(i,a,b)       for(ll i=a;i<b;i++)
#define     FORE(i,a,b)      for(long long i=a;i<=b;i++)
#define     FORD(i,b,a)      for(long long i=b;i>a;i--)
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
#define     testcase         long long t;cin>>t;while(t--)
#define     gcd(a,b)         __gcd(a,b)
#define     maxv             long long_MAX
#define     minv             long long_MIN
#define     MOD              1000000007
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);

// struct custom_hash {
//     static ulong long64_t splitmix64(ulong long64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(ulong long64_t x) const {
//         static const ulong long64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

template<class T> void dispvector(vector<T> v){for(long long i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, long long n){for(long long i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> long long sizeofarr(T *v){return sizeof(v)/sizeof(T);}

int main(int argc, char** argv)
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
        long long n;
        cin>>n;
        long long arr[n];
        long long sum[n+1];
        sum[0]=0;
        long long sum_t=0,compar=INT_MIN;
        vector<long long> neg,ele;
        // neg.pb(0);
        // ele.pb(0);
        long long build_up=0;
      
        vector<int> indx;
        for(long long i = 0 ; i <n;i++)
        {
            long long temp;
            cin>>temp;
            arr[i]=temp;
            // sum_t+=temp;
            sum[i+1]=sum_t;
            if(temp<0)
            {
                indx.pb(i);
            }
            sum_t+=temp;   
        }
        if(indx.size()==0 &&sum_t>0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            bool falg=true;
            for(int i = 0 ; i <indx.size();i++)
            {
            long long val1=sum[indx[i]+1];
        
            long long val2=indx[i]!=n-1?sum_t-val1-arr[indx[i]]:INT_MIN;
            // cout<<val1<<" "<<val2<<" "<<sum_t<<endl;
            if(val1>=sum_t || val2>=sum_t &&sum_t>0)
            {
                falg=false;
                break;
            }
            }
            if(falg &&sum_t>0)
            {
                cout<<"YES"<<endl;
                
            }
            else
            {
                cout<<"NO"<<endl;

            }
            
        }
        

    }
        
       
    return 0;
}