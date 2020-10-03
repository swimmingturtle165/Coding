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

template<class T> void dispvector(vector<T> v){for(int i=0;i<v.size();i++) cout<<v[i]<<" "; nn;}
template<class T> void disparray(T *v, int n){for(int i=0;i<n;i++) cout<<v[i]<<" "; nn;}
template<class T> int sizeofarr(T *v){return sizeof(v)/sizeof(T);}
vector<vector<ll>> pats;


// utility function for printing 
// the found path in graph 
void printpath(vector<ll> path) 
{ 
	pats.pb(path);
    dispvector<ll>(path);
} 

// utility function to check if current a
// vertex is already present in path 
int isNotVisited(ll x, vector<ll>& path) 
{ 
	int size = path.size(); 
	for (int i = 0; i < size; i++) 
		if (path[i] == x) 
			return 0; 
	return 1; 
} 

// utility function for finding pats in graph 
// from source to destination 
void findpats(vector<vector<ll> >&g, ll src, 
								ll dst, ll v) 
{ 
	
	queue<vector<ll> > q; 

	// path vector to store the current path 
	vector<ll> path; 
	path.push_back(src); 
	q.push(path); 
	while (!q.empty()) { 
		path = q.front(); 
		q.pop(); 
		int last = path[path.size() - 1]; 

		// if last vertex is the desired destination 
		// then print the path 
		if (last == dst) 
			printpath(path);		 

		// traverse to all the nodes connected to 
		// current vertex and push new path to queue 
		for (int i = 0; i < g[last].size(); i++) { 
			if (isNotVisited(g[last][i], path)) { 
				vector<ll> newpath(path); 
				newpath.push_back(g[last][i]); 
				q.push(newpath); 
			} 
		} 
	} 
} 





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
       ll n,a,b,m;
       vector<vector<ll>> graph;

       
       cin>>n>>a>>b>>m;
       FOR(i,0,n+1)
        {
            graph.pb(vector<ll>());
        }
        FOR(i,0,m)
        {
            ll st,en;
            cin>>st>>en;
            graph[st].pb(en);
            graph[en].pb(st);
        }
        
    }           
}