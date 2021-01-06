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

vector<int> prefix_fn(string str)
{
    
    vector<int> strg(str.size(),0);
    for(int i= 1 ; i <str.size();i++){
        int j=strg[i-1];
        while(j!=0 && str[j]!=str[i]){
            j=strg[j-1];
        }
        if(str[j]==str[i]){
            j++;
        }
        strg[i]=j;
    }
    return strg;

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
        
    }
    return 0;
}
