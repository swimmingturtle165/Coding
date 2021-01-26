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



        int arr[1000001];

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
        ll n;
        cin>>n;
        vector<ll> inp(2*n);

        FOR(i,0,2*n) cin>>inp[i];
        
        sort(inp.begin(),inp.end());

        memset(arr,0,sizeof(arr));
        vector<int> ans(2*n);
            bool flg=true;
        FOR(j,0,2*n-1)
        {
            FOR(i,0,2*n) arr[inp[i]]=0;

            FOR(i,0,2*n) arr[inp[i]]++;
            
            flg=true;
            ll x=inp[2*n-1];
            ans[0]=inp[2*n-1];
            ans[1]=inp[j];
            arr[inp[j]]--;
            arr[inp[2*n-1]]--;
            ans[0]=inp[2*n-1];
            ans[1]=inp[j];
            int curr=inp[2*n-1];
            FOR(i,1,n)
            {
                while(curr!=0 && arr[curr]==0)
                {
                    curr--;
                }
                
                ll first=curr;
                ll sec=x-first;

                if(arr[first]<=0 || arr[sec]<=0 ||(sec==first && arr[first]<2))
                {
                    flg=false;

                    break;
                }
                else
                {
                    ans[2*i]=first;
                    ans[2*i+1]=sec;
                    x=max(first,sec);
                    arr[first]--;
                    arr[sec]--;
                }
                
            }
            if(flg)
            {
                cout<<"YES"<<endl;
                cout<<ans[0]+ans[1]<<endl;
                FOR(i,0,n)
                {
                     cout<<ans[2*i]<<" "<<ans[2*i+1]<<endl;
                }
                break;
            }
            


        }
        if(!flg)
        {
            cout<<"NO"<<endl;
        }

        
                
        
    }
    return 0;
}
