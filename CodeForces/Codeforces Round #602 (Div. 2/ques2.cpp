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
        vector<int> ans;
        stack<int> left; 
        unordered_set<int,custom_hash> done;
        int arr[n];
        FOR(i,0,n)
        {
            cin>>arr[i];
        }
        bool flag=true;
        FOR(i,0,n)
        {
            // cout<<arr[i]<<endl;
            if(arr[i]<i+1)
            {
                flag=false;
                break;
            }
            else if(arr[i]==i+1 &&done.count(arr[i])==0)
            {
                ans.pb(arr[i]);
                done.in(arr[i]);
            }
            else if(done.count(arr[i])==0)
            {
                ans.pb(arr[i]);
                if(done.count(i+1)==0)
                {
                left.push(i+1);
                }
                done.in(arr[i]);

            }
            else
            {
                if(left.size()==0)
                {
                    flag=false;
                    break;
                }
                else
                {
                    // cout<<left.top()<<endl;
                    ans.pb(left.top());
                    done.in(left.top());

                    left.pop();
                    if(done.count(i+1)==0)
                {
                left.push(i+1);
                }

                }
                
            }
            
            
        }
        if(flag&& left.size()<=1)
        {
            // cout<<left.size()<<endl;
            FOR(i,0,n)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        

    }
    return 0;
}