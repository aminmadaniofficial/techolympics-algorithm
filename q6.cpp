// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

struct Line {
    ll m, c;
    ll eval(ll x) const {
        return m * x + c;
    }
};

// Returns true if l2 is redundant given l1 and l3
// l1.m > l2.m > l3.m
// intersect(l1, l2) >= intersect(l2, l3)
// (l2.c - l1.c) / (l1.m - l2.m) >= (l3.c - l2.c) / (l2.m - l3.m)
bool is_redundant(const Line& l1, const Line& l2, const Line& l3) {
    return (i128)(l2.c - l1.c) * (l2.m - l3.m) >= (i128)(l3.c - l2.c) * (l1.m - l2.m);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n <= 1) {
        cout << 0 << "\n";
        return;
    }
    
    sort(a.begin(), a.end());
    ll M = a[n - 1];
    
    // Convex Hull Trick for query min:
    // slopes m = -j are strictly decreasing (0, -1, -2, ...)
    // queries x = a[i-1] are strictly increasing
    vector<Line> dq;
    dq.reserve(n);
    
    auto add_line = [&](ll m, ll c) {
        Line cur = {m, c};
        while (dq.size() >= 2 && is_redundant(dq[dq.size() - 2], dq.back(), cur)) {
            dq.pop_back();
        }
        dq.push_back(cur);
    };
    
    int head = 0;
    auto query = [&](ll x) -> ll {
        while (head + 1 < (int)dq.size() && dq[head + 1].eval(x) <= dq[head].eval(x)) {
            head++;
        }
        return dq[head].eval(x);
    };
    
    // Base line: j = 0 => m = 0, c = dp[0] = 0
    add_line(0, 0);
    
    vector<ll> dp(n, 0);
    for (int i = 1; i < n; ++i) {
        ll x = a[i - 1];
        dp[i] = M + (ll)(i - 1) * x + query(x);
        add_line(-i, dp[i]);
    }
    
    ll sum_all_except_M = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum_all_except_M += a[i];
    }
    
    ll ans = dp[n - 1] - sum_all_except_M;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}