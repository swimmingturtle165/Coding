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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);

        FOR(i,0,n) cin>>arr[i];

        sort(arr.begin(),arr.end());

        dispvector<int>(arr);

        bool flg=false;
      

        // 3 conditions
        // 0 is present
        // atleast 1 duplicate
        // arr[x]-arr[y]=arr[z]
        ll sum=0;
        FOR(i,0,n)
        {
            if(arr[i]==0)
            {
                // zero
                flg=true;

            }
            if(i>0 && arr[i]==arr[i-1])
            {
                // duplicate
                flg=true;
            }
            // sum+=arr[i];
        }
        cout<<sum<<endl;
        if(!flg)
        {
            unordered_map<int,int> strg;

            for(int i = 0 ; i < arr.size();i++) strg[arr[i]]=i;

            for(int i = 0 ; i < arr.size();i++) 
            {
                if(strg.find(2*arr[i])!=strg.end())
                {
                    flg=true;
                }
            }

            for(int i = 0 ; i < arr.size();i++)
            {
                for(int j = 0 ; j < arr.size();j++)
                {
                    
                    if(i!=j && strg.find(arr[i]-arr[j])!=strg.end() && strg[arr[i]-arr[j]]!=i && strg[arr[i]-arr[j]]!=j )
                    {
                        flg=true;
                    }
                     
        
                }   
            }
        }
        if(!flg)
        {
            vector<bool> trgt(1e6+10,false);    
           
            trgt[1e6+1+arr[0]]=true;
            

            for(int j = 1 ; j < n ; j++)
            {
                if(arr[j]<0)
                {

                    for(int i = 1e7+1;i>=0;i--)
                    {
                        
                        if(trgt[i]==true )
                        {
                            int val=i+arr[j];

                            trgt[val]=true;
                            
                        }
                    }
                }
                else
                {
                    for(int i = 0;i<=1e7+1;i++)
                    {
                        
                        if(trgt[i]==true )
                        {
                            int val=i+arr[j];

                            trgt[val]=true;
                            
                        }
                    }
                }
            }
               
            flg=trgt[1e6+1];
        }

        // FOR(m,0,1)
        // {
        //     // we will assign later

            
        //     FORE(i,-1e5,1e5)
        //     {
        //         vector<int> tmp(n);

        //         tmp[0]=i;
                
        //         unordered_set<int> strg;

        //         strg.insert(i);

        //         int idx=n-1;

        //         FOR(j,1,n)
        //         {
        //             if(idx==m)
        //             {
        //                 idx--;
        //             }

        //             bool tmp1=false;

        //             FOR(k,0,j)
        //             {
        //                 if(strg.count(tmp[k]+arr[idx])==1)
        //                 {
        //                     tmp1=true;
        //                 }
        //                 if(strg.count(tmp[k]-arr[idx])==1)
        //                 {
        //                     tmp1=true;
        //                 }
        //             }

        //             if(tmp1==false)
        //             {
        //                 tmp[j]=(i+arr[idx]);
        //             }
        //             else
        //             {
        //                 tmp[j]=(i+arr[m]);
        //                 flg=true;
        //             }

        //             strg.insert(tmp[j]);
        //             idx--;

        //         }
                
                
        //         FOR(j,0,n)
        //         {
        //             if(strg.count(tmp[j]-arr[m])==1)
        //             {
        //                 flg=true;
        //                 break;
        //             }
        //             if(strg.count(tmp[j]+arr[m])==1)
        //             {
        //                 flg=true;
        //                 break;
        //             }
        //         }
        //         if(flg)
        //         {     
        //             // cout<<idx<<" "<<m<<endl;
        //             // dispvector<int>(tmp);           
        //             break;
        //         }
        //     }
             
        // }
        if(flg)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
