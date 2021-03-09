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



 
vector<vector<ll>> ans;


void soln2(int start_r,int start_c,vector<string> &strg)
{
    ll pos1_x = -1;
    ll pos2_x = -1;

    ll pos1_y = -1;
    ll pos2_y = -1;

    ll left1_y = -1;
    ll left2_y = -1;

    ll left1_x = -1;
    ll left2_x = -1;

    FOR(i,start_r,start_r+2)
    {
        FOR(j,start_c,start_c+2)
        {
            if(strg[i][j]=='1')
            {
                if(pos1_x==-1)
                {
                    pos1_y = j;
                    pos1_x = i;

                }
                else
                {
                    pos2_x = i;
                    pos2_y = j;
                }
            }
            else
            {
                if(left1_x==-1)
                {
                    left1_x = i;
                    left1_y = j;
                }
                else
                {
                    left2_x = i;
                    left2_y = j;
                }
            }
        }
    }
    vector<ll> strg1 = {pos2_x + 1, pos2_y + 1, left2_x + 1, left2_y + 1, left1_x + 1, left1_y + 1};
    vector<ll> strg2 = {pos1_x + 1, pos1_y + 1, left2_x + 1, left2_y + 1, left1_x + 1, left1_y + 1};
    ans.pb(strg1);
    ans.pb(strg2);
    FOR(i, start_r, start_r + 2)
    {
        FOR(j,start_c,start_c+2)
        {
            strg[i][j] = '0';
        }
    }

}

void soln1(int start_r, int start_c,vector<string> &strg)
{
    FOR(i,start_r,start_r+2)
    {
        FOR(j,start_c,start_c+2)
        {
            if(strg[i][j]=='1')
            {
                ll v1 = i == start_r ? start_r + 1 : start_r;
                ll v2 = j == start_c ? start_c + 1 : start_c;
                // cout << v1 << " $$ " << v2 << endl;
                vector<ll> strg1;
                FOR(m, start_r, start_r + 2)
                {
                    FOR(q,start_c,start_c+2)
                    {
                        if(m!=v1 || q!=v2 )
                        {
                            strg1.pb(m + 1);
                            strg1.pb(q + 1);
                            if(strg[m][q]=='1')
                            {
                                strg[m][q] = '0';
                            }
                            else
                            {
                                strg[m][q] = '1';
                            }
                        }
                        // cout << strg[m][q] << " ";
                    }
                    // cout << endl;
                }
                // dispvector<ll>(strg1);
                ans.pb(strg1);
                soln2(start_r, start_c, strg);
                break;
            }
        }
    }
}



void soln3(int start_r,int start_c,vector<string> &strg)
{
    vector<ll> strg1;
    FOR(i, start_r, start_r + 2)
    {
        FOR(j,start_c,start_c+2)
        {
            if(strg[i][j]=='1')
            {
                strg1.pb(i + 1);
                strg1.pb(j + 1);

            }
        }
    }
    ans.pb(strg1);
    FOR(i, start_r, start_r + 2)
    {
        FOR(j,start_c,start_c+2)
        {
            strg[i][j] = '0';
        }
    }
}

void soln4(int start_r,int start_c,vector<string> &strg)
{
    vector<ll> strg1={start_r+1,start_c+1,start_r+2,start_c+1,start_r+1,start_c+2};
    ans.push_back(strg1);
    strg[start_r][start_c] = '0';
    strg[start_r+1][start_c] = '0';
    strg[start_r][start_c+1] = '0';
    soln1(start_r, start_c, strg);

}

signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    long t=1;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int n, m;
        cin >> n >> m;
        vector<string> strg(n);
        FOR(i, 0, n)
        {
        cin >> strg[i];
        }
        vector<ll> solve(5);
        solve[0] = 0;
        solve[1] = 3;
        solve[2] = 2;
        solve[3] = 1;
        solve[4] = 4;
        vector<ll> oper(4);
        oper[0] = 3;
        oper[1] = 2;
        oper[2] = 1;
        oper[3] = 4;

        
            FOR(i,0,n-1)
            {
                FOR(j,0,m)
                {
                    if(strg[i][j]=='1')
                    {
                        ll cnt = 0;
                        ll start_c = j == m - 1 ? j - 1 : j;
                        FOR(k, i, i + 2)
                        {
                            FOR(x,start_c,start_c+2)
                            {
                                if(strg[k][x]=='1')
                                {
                                    cnt++;
                                }
                            }
                        }
                         if (cnt == 1)
                        {
                            soln1(i, start_c,strg);
                        }
                        else if(cnt==2)
                        {
                            soln2(i, start_c,strg);
                        }
                        else if(cnt==3)
                        {
                            soln3(i, start_c,strg);

                        }
                        else if(cnt==4)
                        {
                            soln4(i, start_c, strg);
                        }

                    }
                }
            }
                // for (int j = 0; j < m;j+=2)
                // {
                //     ll start = j==m-1 ? j-1:j;
                //     ll end = start + 1;
                //     ll cnt = 0;
                //     FOR(i,start,end+1)
                //     {
                //         if(strg[n-1][i]=='1')
                //         {
                //             cnt++;
                //         }
                //          if(strg[n-2][i]=='1')
                //         {
                //             cnt++;
                //         }
                        
                //     }
                //     if (cnt == 1)
                //     {
                //         soln1(n - 2, start,strg);
                //     }
                //     else if(cnt==2)
                //     {
                //         soln2(n - 2, start,strg);
                //     }
                //     else if(cnt==3)
                //     {
                //         soln3(n - 2, start,strg);

                //     }
                //     else if(cnt==4)
                //     {
                //         soln4(n - 2, start, strg);
                //     }
                // }

        cout << ans.size() << endl;
        FOR(i,0,ans.size())
        {
            dispvector<ll>(ans[i]);
        }
    
    }
    return 0;
}
