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
#define     SACHITJAGGI      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define     here             cout<<"I'm here\n";
#define     flush            cout.flush();
#define endl '\n'         
#define     all(x)           (x).begin(),(x).end()
#define     setcount(x)      __builtin_popcountll(x)
#define ordered_set_single tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set_pair;

inline int add(int a,int b) { return (a%MOD + b%MOD + MOD)%MOD; }
inline int mul(int a,int b) { return (a%MOD * b%MOD + MOD)%MOD; }
inline int sub(int a,int b) { return (a%MOD - b%MOD + MOD)%MOD; }

template<class T> void dispvector(vector<T> v){ for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n"; }

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
  



signed main(int argc, char** argv)
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    SACHITJAGGI
    long t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);

        vector<double> cnt(4,0);
        
        ll sum=0;
        FOR(i,0,n)
        {
         cin>>arr[i];
        //  sum+=arr[i];
         cnt[arr[i]]++;
        }
		
        double dp[n+1][n+1][n+1];
        double prob[n+1][n+1][n+1];

        FOR(i,0,n+1)
        {
            FOR(j,0,n+1)
            {
                FOR(k,0,n+1)
                {
                    prob[i][j][k]=0;
                    dp[i][j][k]=0;
                }    
            }    
        }
        prob[(ll)cnt[1]][(ll)cnt[2]][(ll)cnt[3]]=1;

        FORDE(i,cnt[3],0)
        {
            FORDE(j,n,0)
            {
                FORDE(k,n,0)
                {

                    // 3 transitions
                      if(i == 0 && j == 0 && k == 0) {
                    continue;
                    }
                    if(i + j +k > n) {
                        continue;
                    }

                    double p_waste=((double)(n)-(i+j+k))/(double)(n);
                    double p_waste_tot=((double)1)/((double)(1)-p_waste);
                    dp[k][j][i]+=p_waste_tot*prob[k][j][i];

                    if(i>0)
                    {
                        prob[k][j+1][i-1]+=(prob[k][j][i]*(double(i)/double(i+j+k)));
                        dp[k][j+1][i-1]+=(dp[k][j][i]*(double(i)/double(i+j+k)));
                    }    
                    if(j>0)
                    {
                        prob[k+1][j-1][i]+=(prob[k][j][i]*(double(j)/double(i+j+k)));
                        dp[k+1][j-1][i]+=(dp[k][j][i]*(double(j)/double(i+j+k)));
                  
                    }  
                    if(k>0)
                    {
                        prob[k-1][j][i]+=(prob[k][j][i]*(double(k)/double(i+j+k)));
                        dp[k-1][j][i]+=(dp[k][j][i]*(double(k)/double(i+j+k)));
                       
                    }  

                }   
            }   
        }
        cout<<setprecision(10);
        cout<<dp[0][0][0]<<endl;


    }
    return 0;
}
