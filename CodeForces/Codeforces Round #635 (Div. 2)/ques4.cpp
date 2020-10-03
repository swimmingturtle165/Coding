#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FORE(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i > a; i--)
#define FORDE(i, b, a) for (ll i = b; i >= a; i--)
#define debug(x) cout << '>' << #x << " : " << x << "\n";
#define debug2(x, y)                         \
    cout << '>' << #x << " : " << x << "\n"; \
    cout << '>' << #y << " : " << y << "\n";
#define debug3(x, y, z)                      \
    cout << '>' << #x << " : " << x << "\n"; \
    cout << '>' << #y << " : " << y << "\n"; \
    cout << '>' << #z << " : " << z << "\n";
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define in insert
#define s second
#define f first
#define nn cout << "\n"
#define pb push_back
#define testcase \
    int t;       \
    cin >> t;    \
    while (t--)
#define gcd(a, b) __gcd(a, b)
#define maxv INT_MAX
#define minv INT_MIN
#define MOD 1000000007
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define here cout << "I'm here\n";
#define flush fflush(stdout);
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll nCrModpDP(ll n, ll r)
{

    ll C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;
    for (ll i = 1; i <= n; i++)
    {

        for (ll j = min(i, r); j > 0; j--)

            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[r];
}
struct custom_hash
{

    static uint64_t splitmix64(uint64_t x)
    {
        x = 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll ntopowermandMod(ll n, ll m, ll mod_v)
{
    if (m == 0)
    {
        return 1;
    }
    if (m == 1)
    {
        return n;
    }
    else
    {
        ll val = ntopowermandMod(n, m / 2, mod_v);
        val = val % mod_v;
        val = val * val;
        val = val % mod_v;
        if (m % 2 == 1)
        {
            val = val * n;
            val = val % mod_v;
        }
        return val;
    }
}
ll ntopowerm(ll n, ll m)
{
    if (m == 0)
    {
        return 1;
    }
    if (m == 1)
    {
        return n;
    }
    else
    {
        ll val = ntopowerm(n, m / 2);
        val = val * val;
        if (m % 2 == 1)
        {
            val = val * n;
        }
        return val;
    }
}
template <class T>
void dispvector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    nn;
}
template <class T>
void disparray(T *v, int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    nn;
}
template <class T>
int sizeofarr(T *v) { return sizeof(v) / sizeof(T); }

signed main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FastIO;
    long t;
    cin >> t;
    while (t--)
    {
        ll na, nb, nc;
        cin >> na >> nb >> nc;
        vector<ll> red(na), green(nb), blue(nc);
        FOR(i, 0, na)
            cin >> red[i];
        FOR(i, 0, nb)
            cin >> green[i];
        FOR(i, 0, nc)
            cin >> blue[i];

        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());

        ll ans = INT64_MAX;

        FOR(i, 0, na)
        {
            ll mini1 = INT_MAX;
            ll mini2 = INT_MAX;

            ll lower = lower_bound(green.begin(), green.end(), red[i]) - green.begin();

            ll upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, nb - 1);
            // debug3(red[i], green[lower], green[upper]);
            mini1 = red[i] - green[lower];
            if (abs(red[i] - green[upper]) < abs(mini1))
            {
                mini1 = red[i] - green[upper];
            }

            lower = lower_bound(blue.begin(), blue.end(), red[i]) - blue.begin();
            upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, nc - 1);

            // debug3(red[i], blue[lower], blue[upper]);

            mini2 = red[i] - blue[lower];

            if (abs(red[i] - blue[upper]) < abs(mini2))
            {
                mini2 = red[i] - blue[upper];
            }

            ll mini3 = mini1 - mini2;

            ll tmp = ntopowerm(mini1, 2) + ntopowerm(mini2, 2) + ntopowerm(mini3, 2);
            ans = min(ans, tmp);
        }
        // cout << ans << endl;

        FOR(i, 0, nb)
        {
            ll mini1 = INT_MAX;
            ll mini2 = INT_MAX;

            ll lower = lower_bound(blue.begin(), blue.end(), green[i]) - blue.begin();
            ll upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, nc - 1);
            // debug3(green[i],blue[lower],blue[upper]);

            mini1 = green[i] - blue[lower];
            if (abs(green[i] - blue[upper]) < abs(mini1))
            {
                mini1 = green[i] - blue[upper];
            }

            lower = lower_bound(red.begin(), red.end(), green[i]) - red.begin();
            upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, na - 1);
            // debug3(green[i],red[lower],red[upper]);

            mini2 = green[i] - red[lower];
            if (abs(green[i] - red[upper]) < abs(mini2))
            {
                mini2 = green[i] - red[upper];
            }

            ll mini3 = mini1 - mini2;
            // debug3(mini1,mini2,mini3);
            ll tmp = ntopowerm(mini1, 2) + ntopowerm(mini2, 2) + ntopowerm(mini3, 2);
            ans = min(ans, tmp);
        // cout << ans <<" ** "  << tmp <<endl;

        }
        // cout << ans << endl;

        FOR(i, 0, nc)
        {
            ll mini1 = INT_MAX;
            ll mini2 = INT_MAX;

            ll lower = lower_bound(green.begin(), green.end(), blue[i]) - green.begin();
            ll upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, nb - 1);

            // debug3(blue[i],green[lower],green[upper]);

            mini1 = blue[i] - green[lower];
            if (abs(blue[i] - green[upper]) < abs(mini1))
            {
                mini1 = blue[i] - green[upper];
            }

            lower = lower_bound(red.begin(), red.end(), blue[i]) - red.begin();
            upper = lower;
            lower--;
            lower = max(lower, 0ll);
            upper = min(upper, na - 1);
            // debug3(blue[i],red[lower],red[upper]);


            mini2 = blue[i] - red[lower];

            if (abs(blue[i] - red[upper]) < abs(mini2))
            {
                mini2 = blue[i] - red[upper];
            }

            ll mini3 = mini1 - mini2;

            ll tmp = ntopowerm(mini1, 2) + ntopowerm(mini2, 2) + ntopowerm(mini3, 2);
            ans = min(ans, tmp);
        }

        cout << ans << endl;
    }
    return 0;
}