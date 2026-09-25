#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << H << " "; dbg_out(T...); }
#else
#define dbg(...) 42
#endif

const ll INF = 1e18;
const int MOD = 1e9 + 7; // or 998244353

ll mod_exp(ll b, ll p, ll m = MOD) {
    ll res = 1;
    b %= m;
    while (p > 0) {
        if (p & 1) res = (__int128)res * b % m;
        b = (__int128)b * b % m;
        p >>= 1;
    }
    return res;
}

ll mod_inv(ll n, ll m = MOD) {
    return mod_exp(n, m - 2, m);
}

void solve() {
    // Problem solution here
    
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
