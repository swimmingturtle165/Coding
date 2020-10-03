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

// bool mycmp(palindromic_occurances a,palindromic_occurances b)
// {
//     if(a.curr_i!=b.curr_i)
//     {
//         return a.curr_i<b.curr_i;
//     }
//     return a.curr_j<b.curr_j;
// }
// class palindromic_occurances{
//     public :
//     int curr_i=-1;
//     int curr_j=-1;
//     int starting_indx=-1;
//     int ending_indx=-1;

//     palindromic_occurances(int a,int b,int c,int d)
//     {
//         this->curr_i=a;
//         this->curr_j=b;
//         this->ending_indx=d;
//         this->starting_indx=c;
//     }
// };
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
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i = 0 ; i <n;i++)
        {
            for(int j = 0 ; j <m;j++)
            {
                cin>>arr[i][j];
            }
        }
        long long ans=n*m;
        // vector<palindromic_occurances> column,rows;
        for(int i = 1 ; i <n-1;i++)
        {
            for(int j = 1; j <m-1;j++)
            {
                int start_pos_x=i-1,ending_pos_x=i+1;
                int start_pos_y=j-1,ending_pos_y=j+1;
                while(
                    start_pos_x>=0 && start_pos_y>=0 
                &&ending_pos_x<n &&ending_pos_y<m 
                &&arr[start_pos_x][j]==arr[ending_pos_x][j]
                 && arr[i][start_pos_y]==arr[i][ending_pos_y])
                 {
                     ans++;
                     start_pos_x--;
                     ending_pos_x++;
                     start_pos_y--;
                     ending_pos_y++;
                 }

                

            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}