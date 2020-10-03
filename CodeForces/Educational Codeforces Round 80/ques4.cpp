#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp> 
#include <stdio.h> 
#include <math.h> 
#include <vector>
#include <algorithm>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
   const long long M = 300200;
long long n, l , r, t, m;
vector<pair<int,int>> valid;
int a[M][9];
int all1 = 1;
pair<int,int> check(int mid) {
	map<int,int> exist;
	for (int i = 1; i <= n; i++) {
		int stat = 0;
		for (int j = 0; j < m; j++) {
			int current = 0;
			if (a[i][j] >= mid) {
				current = 1;
			} 
			stat = (stat << 1) | current;
		}
		exist[stat] = i;
	}
	for (auto i: valid) {
		if (exist[i.first] > 0 && exist[i.second] > 0) {
			return {exist[i.first], exist[i.second]};
		}
	}
	return {-1,-1};
}
int main()
{   
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 2; i <= m; i++) {
		all1 = (all1 << 1) | 1;
	}
	for (int i = 0; i <= all1; i++) {
		for (int j = i; j <= all1; j++) {
			if ((i|j) == all1) 
				valid.push_back({i,j});
		}
	}
	int left = 0;
	int right = pow(10, 9);
	int mid = (left + right + 1) / 2;
	pair<int,int> ans;
	while (left < right) {
		mid = (left + right + 1) / 2;
		ans = check(mid);
		if (ans.first == -1) {
			right = mid - 1;
		} else {
			left = mid;
		}
	}
	ans = check((left + right + 1) / 2);
	
	cout << ans.first <<" " << ans.second;
    return 0;
}