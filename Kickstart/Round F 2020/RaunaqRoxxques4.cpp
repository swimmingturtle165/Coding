/*
    ThunderClap and Flash
    Raunaq Singh
*/
#include "bits/stdc++.h" 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define ThunderClap ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
#define debugg(something)   cout<<#something<<" - "<<something<<"\n";
#define vi vector
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define LB lower_bound
#define UB upper_bound
#define mp make_pair
#define pb push_back
#define in insert
#define s second
#define f first
#define pQueue priority_queue
#define maxElement *max_element
#define minElement *min_element
#define MAX 100000LL
#define mod 1000000007LL
#define inf 1000000000000000000LL
#define mI2 500000004LL
inline ll add(ll a, ll b){ return ((a%mod) + (b%mod))%mod;}
inline ll mul(ll a, ll b){ return ((a%mod) * (b%mod))%mod;}
inline ll sub(ll a, ll b){ return ((a%mod) - (b%mod) + mod)%mod;}

vector <pll> dxyOdd ({{0, 1}, {0, -1}, {1, 1}});
vector <pll> dxyEven ({{0, 1}, {0, -1}, {-1, -1}});

bool check(ll x, ll y, ll S, vector <vector <bool>> &vis) {
    if (x > S || x < 1) {
        return true;
    }
    if (y > (2 * x - 1) || y < 1) {
        return true;
    }
    return vis[x][y];
} 

ll findAns(ll x1, ll y1, ll x2, ll y2, bool turn, ll didntMove, ll S, vector <vector <bool>> &vis, ll fCnt, ll sCnt) {
    //cout<<turn<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    if (didntMove == 2) {
        return (fCnt - sCnt);
    }
    ll ret, cnt = 0;
    ll nx, ny;
    vector <pll> dxy;
    if (turn) {
        ret = -1 * inf;
        if (y1 & 1) {
            dxy = dxyOdd;
        } else {
            dxy = dxyEven;
        }
        for (ll i = 0; i < 3; i++) {
            nx = x1 + dxy[i].f, ny = y1 + dxy[i].s;
            if (!check(nx, ny, S, vis)) {
                ++cnt;
                vis[nx][ny] = true;
                ret = max(ret, findAns(nx, ny, x2, y2, turn ^ 1, 0, S, vis, fCnt + 1, sCnt));
                vis[nx][ny] = false;
            }
        }
        if (cnt == 0) {
            ret = max(ret, findAns(x1, y1, x2, y2, turn ^ 1, didntMove + 1, S, vis, fCnt, sCnt));
        }
    } else {
        ret = inf;
        if (y2 & 1) {
            dxy = dxyOdd;
        } else {
            dxy = dxyEven;
        }
        for (ll i = 0; i < 3; i++) {
            nx = x2 + dxy[i].f, ny = y2 + dxy[i].s;
            if (!check(nx, ny, S, vis)) {
                ++cnt;
                vis[nx][ny] = true;
                ret = min(ret, findAns(x1, y1, nx, ny, turn ^ 1, 0, S, vis, fCnt, sCnt + 1));
                vis[nx][ny] = false;
            }
        }
        if (cnt == 0) {
            ret = min(ret, findAns(x1, y1, x2, y2, turn ^ 1, didntMove + 1, S, vis, fCnt, sCnt));
        }
    }
    return ret;
}

void Flash(){
    ll S, xa, ya, xb, yb, c;
    cin>>S>>xa>>ya>>xb>>yb>>c;
    vector <vector <bool>> vis (S + 1, vector <bool> (2 * S, false));
    ll xi, yi;
    for (ll i = 0; i < c; i++) {
        cin>>xi>>yi;
        vis[xi][yi] = true;
    }
    vis[xa][ya] = vis[xb][yb] = true;
    ll ans = 0;
    ans = findAns(xa, ya, xb, yb, true, 0, S, vis, 1, 1);
    cout<<ans<<"\n";
}

int main(int argc, char const *argv[]){ 
    ThunderClap;
    ll t = 1;
    cin>>t;
    for(ll i = 1; i <= t; i++){
        cout<<"Case #"<<i<<": ";
        Flash();
    }
    return 0;
}
