#include<bits/stdc++.h>
#include<math.h>
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

bool mycmp(pair<int,pair<int,pair<int,int>>>a,pair<int,pair<int,pair<int,int>>>b)
{
    if(a.first!=b.first)
     return a.first<b.first;
    
    else if(a.second.first!=b.second.first) 
     return a.second.first<b.second.first;
    
    else
     return a.second.second.first<b.second.second.first;
}
signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long n;
    cin>>n;
    map<int,map<int,vector<int>>> pai;
    vector<pair<int,pair<int,pair<int,int>>>> pts;
    for(int i = 0 ; i <n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pair<int,pair<int,pair<int,int>>>temp={a,{b,{c,i+1}}};
        pts.pb(temp);
    }
    sort(pts.begin(),pts.end(),mycmp);
    vector<pair<int,pair<int,pair<int,int>>>> pts2;
    
    for(int i = 0 ; i <pts.size();i++)
    {
        if(i<pts.size()-1 &&pts[i].first==pts[i+1].first &&pts[i].second.first==pts[i+1].second.first)
        {
            cout<<pts[i].second.second.second<<" "<<
            pts[i+1].second.second.second<<endl;
            i++;
        }
        else
        {
            pts2.push_back(pts[i]);
        }
        
    }
    sort(pts2.begin(),pts2.end(),mycmp);

    vector<pair<int,pair<int,pair<int,int>>>> pts3;

    for(int i = 0 ; i <pts2.size();i++)
    {
        if( i <pts2.size()-1 && pts2[i].first==pts2[i+1].first)
        {
            cout<<pts2[i].second.second.second<<" "<<
            pts2[i+1].second.second.second<<endl;

            i++;
        }
        else
        {
            pts3.pb(pts2[i]);
        }
        
    }
    sort(pts3.begin(),pts3.end(),mycmp);

    for(int i = 0 ; i <pts3.size();i=i+2)
    {
        cout<<pts3[i].second.second.second<<" "<<
            pts3[i+1].second.second.second<<endl;

           
    }
    return 0;
}