#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
 
 
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pii >
#define I insert 
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl "\n"
 
 
// const int mod=1e9+7;
// inline int mul(int a,int b){return (a*1ll*b)%mod;}
// inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
// inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
// inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline int inv(int a){return power(a,mod-2);}
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 
 
 
void solve(){
	int N; cin>>N;
	vi sz;
	vi v(N);
	int tot=0;
	for(int i=0;i<N;i++){
		cin>>v[i];
		if(i==0 || __gcd(v[i], v[i-1])==1){
			sz.pb(1); tot++;
		}
		else sz[tot-1]++;
	}
	bool full = 0;
	if(tot>1 && (__gcd(v[0], v.back())>1) ) { sz[0]+=sz.back(); sz.pop_back(); }
	if(tot==1 && (__gcd(v[0], v.back())>1)) full =1;
	vi ans(N+1, 0);
	for(auto z:sz){
		for(int i=2; i<=z;i++){
			ans[i] += (z-1)/(i-1);
			if(full) ans[i]++;
		}
	}
	for(int i=2;i<=N;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int T; cin>>T;
	while(T--) solve();	
}