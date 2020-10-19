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

const int N=200005;
const int S=450;
const int P=1000000007;

inline void add(int &a,int b){a+=b;if(a>=P)a-=P;}

inline void dec(int &a,int b){a-=b;if(a<0)a+=P;}

inline int  Pow(ll x, ll y, ll p=MOD) 
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
    return Pow(n, p-2, p); 
} 
  
int fac[N<<1],inv[N<<1];

int C(int &a,int &b)
{
	int rgt=fac[a]*1ll*inv[b]%P;

	 rgt=rgt*1ll*inv[a-b]%P;

	 return rgt;
}
int n,k;
int f[N],g[N];
int res[N];
void dp()
{
	f[0]=1;
	FORE(i,0,S){
		memset(g,0,sizeof g);
		FORE(j,0,k)if(f[j])
		{
			if(i+j+1<=k)
			{
				dec(g[i+j+1],f[j]);
				// g[i + j + 1] %= 2;
				// f[j] %= 2;
			}
			if(i&&(i+j<=k)){
			add(f[j+i],f[j]);
			// f[j] %= 2;
			// f[j+i] %= 2;
			}
		}
		FORE(j,0,k)
		{
			add(res[j], f[j]);
			f[j] = g[j];
			// f[j] %= 2;
			// g[j] %= 2;
		}
	}
	
	memset(f,0,sizeof f);
	FORE(i,0,k)f[i]=res[i];
	memset(res,0,sizeof res);
	FORE(i,0,k/n){
		memset(g,0,sizeof g);
		FORE(j,0,k)if(f[j])
		{
			if(i&&(i+j<=k))add(f[i+j],f[j]);
			if(j+n+1<=k)add(g[j+n+1],f[j]);
		}
		FORE(j,0,k)
		{
			add(res[j],f[j]);
		}
		FORE(j,0,k) {
		
			f[j]=g[j];
			
		}
		
	}
	ll ans=0;
	FORE(j,0,k)
	{
		res[j] % 2;
		int v1 = k - j + n - 1;
		int v2 = n - 1;
		ll ret=res[j]*1ll*C(v1,v2)%P;
		
		ans+=ret;
	}
	cout << ans%2<< endl;
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
	ll t;
	cin >> t;
	while (t--)
	{
		
    ll n, k;
    cin >> n >> k;

    ll total = n * (n - 1) / 2;
    if (k < 0 || k > total) /// k is out of range
    {
        cout << 0<<endl;
       
    }

    k=max(k,n);
    int f[n + 1][k + 1];
    f[0][0] = 1; /// base case f[n][0] = 1
    for (int i = 1; i <= n; ++i) f[0][i] = 0; /// base case f[0][k] = 0
    for (int i = 1; i <= n; ++i)
    {
        bool cur = i & 1; /// current
        bool pre = !cur;  /// previous

        f[cur][0] = 1; /// base case f[n][0] = 1
        for (int j = 1; j <= k; ++j)
        {
            f[cur][j] = (f[cur][j - 1] + f[pre][j]) % MOD;
            if (j >= i)
                f[cur][j] = (f[cur][j] - f[pre][j - i] + MOD) % MOD;
        }
    }

	cout << f[n][k] << endl;
	}
	
	
	
	return 0;
}
	
    
