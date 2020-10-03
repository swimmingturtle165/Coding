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
      long n;
      cin>>n;
      int arr[n];
      map<int,int>mpe;
      set<int> pend;
      vector<int> left;
      for(int i = 0 ; i <n;i++)
      {
          cin>>arr[i];
          if(arr[i]%2==0)
          {
            //   vector<int> temp;
            //   temp.push_back(i);
              mpe[arr[i]]++;
              if(pend.count(arr[i])==0)
              {
                  left.pb(arr[i]);
                  pend.insert(arr[i]);
              }
          }

      }
      sort(left.begin(),left.end());

//       for(int i = left.size()-1 ; i >=0;i--)
// {
//     cout<<left[i]<<" ";
// }
// cout<<endl;
      ll ans=0;
      for(int i = left.size()-1 ; i >=0;i--)
      {
          int curr=left[i];
          if(pend.count(curr/2)==0 &&(curr/2)%2==0)
          {
              left.pb(curr/2);
              pend.insert(curr/2);
            //  sort(left.begin(),left.end());
             
             mpe[curr/2]+=mpe[curr];
             left[i]=left[i]/2;

                i++;
          }
          else if((curr/2)%2!=1)
          {              
              mpe[curr/2]+=mpe[curr];
          }
          
          
          ans++;
        //   cout<<curr<<" "<<ans<<endl;
      }
      cout<<ans<<endl;
        
    }
    return 0;
}