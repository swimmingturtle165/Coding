#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

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
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>


ll nCrModpDP(ll n, ll r) 
{ 
    
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    { 
        
        for (ll j = min(i, r); j > 0; j--) 
  
            
            C[j] = (C[j] + C[j-1])%MOD; 
    } 
    return C[r]; 
} 
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
template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}

// *************************************GLOBAL VARIABLE************************************

    ll sfsdf=ntopowerm(10,9);



// *************************************GLOBAL VARIABLE************************************



void evaluate(string tokens)
{ 
    int i; 
      
    stack <int> values,curr_x,curr_y; 
    curr_x.push(1);
    curr_y.push(1);
    values.push(1);

      
      
    for(i = 0; i < tokens.length(); i++)
    { 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i] == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i] == '(')
        { 
           
            curr_x.push(0);
            curr_y.push(0);
        } 
          
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(tokens[i]>='2' && tokens[i]<='9')
        { 
            int val = tokens[i]-'0';            
           
              
            values.push(val); 
        } 
          
        
        else if(tokens[i] == ')') 
        { 
            ll  v1=curr_x.top();
            ll  v2=curr_y.top();
            ll val=values.top();
            
            curr_x.pop();
            curr_y.pop();
            values.pop();

            v1*=val;
            v2*=val;

            ll  v1_t=curr_x.top();
            ll  v2_t=curr_y.top();  
            v1+=v1_t;
            v2+=v2_t;
                    while(v1<=0)
            {
                v1+=sfsdf;

            }
            while(v2<=0)
            {
                v2+=sfsdf;
            }
            while(v1>sfsdf)
            {
                v1-=sfsdf;
            }
            while(v2>sfsdf)
            {
                v2-=sfsdf;
            }   
            curr_x.pop();
            curr_y.pop();
            curr_x.push(v1);
            curr_y.push(v2);        

            
        } 
          
        else
        { 
            if(tokens[i]=='N')
            {

                ll v=curr_x.top();
                curr_x.pop();
                v--;
                curr_x.push(v);
            }
            if(tokens[i]=='S')
            {

                ll v=curr_x.top();
                curr_x.pop();
                v++;
                curr_x.push(v);
                // cout<<"**"<<endl;
            }
            if(tokens[i]=='E')
            {

                ll v=curr_y.top();
                curr_y.pop();
                v++;
                curr_y.push(v);
                // cout<<"**"<<endl;

            }
            if(tokens[i]=='W')
            {

                ll v=curr_y.top();
                curr_y.pop();
                v--;
                curr_y.push(v);
            }
             
              
           
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    ll x=0,y=0;
    while(!curr_x.empty())
    { 
        x+= curr_x.top(); 
        curr_x.pop(); 
                  
         y+= curr_y.top(); 
        curr_y.pop();                
         
    } 
    while(x<=0)
    {
        x+=sfsdf;

    }
    while(y<=0)
    {
         y+=sfsdf;
    }
    while(x>sfsdf)
    {
         x-=sfsdf;
    }
    while(y>sfsdf)
    {
        y-=sfsdf;
    }
      cout<<y<<" "<<x<<endl;
    // Top of 'values' contains result, return it. 
     
} 


signed main(int argc, char** argv)
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    FastIO;
    long t;
    cin>>t;
    ll v=0;
    while(t--)
    {
        v++;
        string str;
        cin>>str;
        

        cout<<"Case #"<<v<<": ";   
        evaluate(str);

    }
    return 0;
}
