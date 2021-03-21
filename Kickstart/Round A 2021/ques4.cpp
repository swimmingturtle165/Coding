#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef     unsigned long long int ull;
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
#define     FastIO           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            fflush(stdout);
#define endl '\n'         
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  
 
// ll factorialNumInverse[300000 + 1]; 
  
// // array to precompute inverse of 1! to N! 
// ll naturalNumInverse[300000 + 1]; 
  
// // array to store factorial of first N numbers 
// ll fact[300000 + 1]; 
  
// // Function to precompute inverse of numbers 
// void InverseofNumber(ll p=MOD) 
// { 
//     naturalNumInverse[0] = naturalNumInverse[1] = 1; 
//     for (int i = 2; i <= 300000; i++) 
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
// } 
// // Function to precompute inverse of factorials 
// void InverseofFactorial(ll p=MOD) 
// { 
//     factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
//     // precompute inverse of natural numbers 
//     for (int i = 2; i <= 300000; i++) 
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
// } 
  
// // Function to calculate factorial of 1 to N 
// void factorial(ll p=MOD) 
// { 
//     fact[0] = 1; 
  
//     // precompute factorials 
//     for (int i = 1; i <= 300000; i++) { 
//         fact[i] = (fact[i - 1] * i) % p; 
//     } 
// } 
  
// // Function to return nCr % p in O(1) time 
// ll Binomial(ll N, ll R, ll p=MOD) 
// { 
//     // n C r = n!*inverse(r!)*inverse((n-r)!) 
//     ll ans = ((fact[N] * factorialNumInverse[R]) 
//               % p * factorialNumInverse[N - R]) 
//              % p; 
//     return ans; 
// } 
   
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
ll ntopowermandMod(ll n,ll m,ll mod_v)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowermandMod(n,m/2,mod_v);
        val=val%mod_v;
        val=val*val;
        val=val%mod_v;
        if(m%2==1)
        {
        val=val*n;
        val=val%mod_v;
        }
        return val;

    }
    
}
ll ntopowerm(ll n,ll m)
{
    if(m==0)
    {
        return 1;

    }
    if(m==1)
    {
        return n;
    }
    else
    {
        ll val=ntopowerm(n,m/2);
        val=val*val;
        if(m%2==1)
        {
        val=val*n;
        }
        return val;

    }
    
}
vector<int> pi;
 
void prefix_function(string s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}
template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}



    void initialize( vector<ll>&Arr,vector<ll>&size, int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i;
        size[ i ] = 1;
    }
}

// O(log*N) ==> recursive log log log log .....(log N)
// finding root of an element.
// modified root function.
int root (vector<ll>&Arr ,int i)
{
    if(i<0 || i>=Arr.size()) return -2;
    
    if(Arr[ i ] != i)    //chase parent of current element until it reaches root.
    {
        Arr[ i ] = root(Arr, Arr[ i ] ) ;  //path compression
    }
    return  Arr[i];
}
    void weighted_union(vector<ll>&Arr,vector<ll>&size,int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(root_A==root_B) return;
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    
        
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
        // size[root_B]=size[root_A];
    }
}

bool find(vector<ll>&Arr,int A,int B)
{
    if( root(Arr,A)==root(Arr,B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}

ll n;
ll left1;


bool precalculation( vector<vector<pll>>& strg)
{
        vector<ll> rows(n,0);
        vector<ll> cols(n,0);
        vector<ll> col1(n,0);
        vector<ll> row1(n,0);
        bool flg=false;
        bool ve=false;
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                if(strg[i][j].first==-1)
                {
                    rows[i]++;
                    cols[j]++;
                    col1[j]=i;
                    row1[i]=j;
                    ve=true;
                }
            }
        }
        if(!ve) return false;
        // cout<<"%%"<<endl;
        // dispvector<ll>(rows);
        // dispvector<ll>(cols);

        FOR(i,0,n)
        {
            if(rows[i]==1)
            {
                ll x=i;
                ll y=row1[i];
                strg[x][y].first=1;
                flg=true;
            }
        }
        if(flg)
        return flg;

        FOR(i,0,n)
        {
            if(cols[i]==1)
            {
                ll x=cols[i];
                ll y=i;
                strg[x][y].first=1;
                flg=true;

            }
        }
        return flg;
}


bool precalculation1( vector<vector<pll>>& strg,ll x,ll y)
{
        vector<ll> rows(n,0);
        vector<ll> cols(n,0);
        vector<ll> col1(n,0);
        vector<ll> row1(n,0);
        bool flg=false;
        bool ve=false;
        FOR(i,0,n)
        {
            
                if(strg[i][y].first==-1)
                {
                    rows[i]++;
                    cols[y]++;
                    col1[y]=i;
                    row1[i]=y;
                    ve=true;
                }
            
        }
        FOR(i,0,n)
        {
            
                if(strg[x][i].first==-1)
                {
                    rows[x]++;
                    cols[i]++;
                    col1[i]=x;
                    row1[x]=i;
                    ve=true;
                }
            
        }
        if(!ve) return false;
        // cout<<"%%"<<endl;
        // dispvector<ll>(rows);
        // dispvector<ll>(cols);

        FOR(i,0,n)
        {
            if(rows[i]==1)
            {
                ll x=i;
                ll y=row1[i];
                if(strg[x][y].first!=-1)
                {
                    continue;
                }
                strg[x][y].first=1;
                strg[x][y].second=0;
                left1--;


               while(precalculation1(strg,x,y))
               {

               }
                flg=true;
            }
        }
        if(flg)
        return flg;

        FOR(i,0,n)
        {
            if(cols[i]==1)
            {
                ll x=cols[i];
                ll y=i;
                left1--;
                if(strg[x][y].first!=-1)
                {
                    continue;
                }
                strg[x][y].first=1;
                strg[x][y].second=0;

                while(precalculation1(strg,x,y))
                {
                    
                }

                flg=true;

            }
        }
        return flg;
}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long v=0;
    long t=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<vector<pll>> strg(n,vector<pll>(n));
        vector<ll> row(n);
        vector<ll> col(n);
        v++;
        cout<<"Case #"<<v<<": ";

        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                cin>>strg[i][j].first;
            }
        }
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                cin>>strg[i][j].second;
                if(strg[i][j].second==0 && strg[i][j].first==-1)
                {
                    strg[i][j].first=1;
                }
            }
        }
        FOR(i,0,n)
        {
            cin>>row[i];
        }
        FOR(i,0,n)
        {
            cin>>col[i];
        }

        ll ans=0;
        ll mini=0;

        left1=0;

        // cout<<left<<endl;
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                if(strg[i][j].first!=-1)
                {
                    precalculation1(strg,i,j);
                }
            }
        }
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
               if(strg[i][j].first==-1)
               {
                   left1++;
               }
            }
        }
        while(left1>0)
        {
            //  cout<<left<<" ";

            mini=INT_MAX;
            left1=0;
            ll x1, y1; 
            FOR(i,0,n)
            {
                FOR(j,0,n)
                {
                    if(strg[i][j].first==-1)
                    {
                        left1++;
                        if(mini>strg[i][j].second)
                        {
                            x1=i;
                            y1=j;
                            mini=strg[i][j].second;
                        }
                    }
                }
            }
            //  cout<<left<<endl;

            if(left1==0)
            {
                break;
            }
            ans+=mini;
            strg[x1][y1].first=1;
            left1--;
            if(left1==0)
            {
                break;
            }
            bool dlf=true;
            while(dlf)
            {
                dlf=precalculation1(strg,x1,y1);
                // do nothing
            }
             left1=0;
                FOR(i,0,n)
                {
                    FOR(j,0,n)
                    {
                        if(strg[i][j].first==-1)
                        {
                            left1++;
                        }
                    }
                }
        cout<<ans<<endl;
        
        


    }
    return 0;
}
