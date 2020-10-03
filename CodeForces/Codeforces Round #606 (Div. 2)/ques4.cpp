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

struct custoNEm_hash {
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
       long n,cnt=0,ones=0,zeroe=0,st_z=0,st_o=0;
       cin>>n;
    //    vector<string> inp (n,"");
    vector<int> type3,type4;
    /*
    type 1 -- 0xxx0
    type 2 -- 1xxx1
    type 3 -- 0xxx1
    type 4 -- 1xxx0 
 
    */
        // debug(n);
        vector<string> strg(n);
        set<string> stONE,stZERO;
       for(int i = 0 ; i <n;i++)
       {
           string  inp;
           cin>>inp;
            strg[i]=inp;

            // cout<<inp<<endl;

           int starting=inp[0]-'0',ending=inp[inp.size()-1]-'0';
        //    debug2(starting,ending);
           if(starting +ending==1)
           {
               cnt++;
               if(starting==1)
               {
                   st_o++;
                   type3.pb(i);
                   stONE.insert(strg[i]);
               }
               else
               {
                   st_z++;
                   type4.pb(i);
                   stZERO.insert(strg[i]);

               }
               
           }
           else if(starting+ending==2)
           {
               ones++;
           }
           else
           {
               zeroe++;
           }
        //    debug3(ones,zeroe,st_o);
        //     debug(st_z);
           
       }
       


        ll ans=0;
        
        if(ones!=0 && zeroe!=0 &&st_o+st_z==0)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            ans=max(st_o,st_z)-min(st_o,st_z);
            ans=ans/2;
            vector<ll> rev;
            if(st_o>st_z)
            {
                for(ll i = 0 ; i <st_o;i++)
                {
                    string te(strg[type3[i]]);
                    reverse(te.begin(),te.end());
                    if(stZERO.count(te)==0)
                    {
                        rev.pb(type3[i]+1);
                        stZERO.insert(te);
                    }
                }
            }
            else
            {

                   for(ll i = 0 ; i <st_z;i++)
                {
                     string te(strg[type4[i]]);
                    reverse(te.begin(),te.end());
                    if(stONE.count(te)==0)
                    {
                        rev.pb(type4[i]+1);
                        stONE.insert(te);

                    }
                } 
            }

            cout<<ans<<endl;
            for(ll i = 0 ; i <ans;i++)
            {
                cout<<rev[i]<<" ";
            }
            cout<<endl;
            
        }
        



        


    }      
    return 0;
}