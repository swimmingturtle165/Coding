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
  
class sgmt{

    public:
    ll start;
    ll end;
    ll winners;

    sgmt(ll a,ll b,ll c)
    {
        start=a;
        end=b;
        winners=c;
    }
    sgmt()
    {

    }

};

unordered_map<ll,ll> strg;

void build(ll curr,ll idx,string& str,vector<sgmt>& arr)
{

    ll lft=2*curr+1;

    ll rgt=2*curr+2;

    if(idx>=str.size())
    {
        arr[curr].start=1;
        arr[curr].end=1;
        arr[curr].winners=1;

        return;
    }

    build(rgt,2*idx+1,str,arr);

    build(lft,2*idx+2,str,arr);
    
    if(str[idx]=='0')
    {
        arr[curr].winners=arr[lft].winners;
    }
    else if(str[idx]=='1')
    {
        arr[curr].winners=arr[rgt].winners;
    }
    else
    {
        arr[curr].winners=arr[lft].winners+arr[rgt].winners;
    }

    strg[idx]=curr;
    // cout<<idx<<" "<<curr<<endl;

    return;

}

void update(ll curr,ll idx,char val,bool upd,string& str,vector<sgmt>& arr)
{
    if(curr<0)
    {
        return;
    }
    if(upd==true)
    {
        str[idx]=val;
    }
    ll lft=2*curr+1;

    ll rgt=2*curr+2;

    if(str[idx]=='0')
    {
        arr[curr].winners=arr[lft].winners;
    }
    else if(str[idx]=='1')
    {
        arr[curr].winners=arr[rgt].winners;
    }
    else
    {
        arr[curr].winners=arr[lft].winners+arr[rgt].winners;
    }
    ll parent=(curr-1)/2;
    ll p2=(idx-1)/2;
    if(curr==0 || parent<0 || p2<0)
    {
        return;
    }
    // cout<<parent<<" ^^ "<<endl;
    update(parent,p2,val,false,str,arr);
    return;
    
}
// void update(ll curr,ll idx,ll upd_idx,char val,string& str,vector<sgmt>& arr)
// {


//     ll lft=2*curr+1;

//     ll rgt=2*curr+2;

   

//     if(upd_idx==idx)
//     {
//         str[idx]=val;
//     }
//     else
//     {

//         if(idx>upd_idx)
//         {
//             return;
//         }

//         update(rgt,2*idx+1,upd_idx,val,str,arr);

//         update(lft,2*idx+2,upd_idx,val,str,arr);

//     }
        
//     if(str[idx]=='0')
//     {
//         arr[curr].winners=arr[lft].winners;
//     }
//     else if(str[idx]=='1')
//     {
//         arr[curr].winners=arr[rgt].winners;
//     }
//     else
//     {
//         arr[curr].winners=arr[lft].winners+arr[rgt].winners;
//     }
//     return;

// }


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
        ll k;
        cin>>k;
        ll v1=2ll*pow(2ll,k)-1ll;
        vector<sgmt> arr(v1,sgmt());
        string str;
        cin>>str;
        reverse(str.begin(),str.end());
        build(0,0,str,arr);
        ll q;
        cin>>q;
        ll v2=2ll*pow(2ll,k)-1ll;
        ll prev=0;
        ll curr=0;
        
        while (q--)
        {
            ll idx;
            char ch;
            cin>>idx>>ch;

            // idx--;
            // cout<<idx<<" &&  "<<str.size()-idx<<endl;
            // cout<<strg[str.size()-idx]<<" "<<str.size()-idx<<endl;
            update(strg[str.size()-idx],str.size()-idx,ch,true,str,arr);
            cout<<arr[0].winners<<endl;
            // ll prev=0;
            // FOR(i,0,k)
            //  {
            //     curr=0;
            //     while(prev+curr<pow(2,i+1)-1)
            //     {
            //         cout<<arr[prev+curr].winners<<" ";
            //         curr++;
            //     }
            //     cout<<endl;
            //     prev+=curr;
            // }
        }
        


    }
    return 0;
}
