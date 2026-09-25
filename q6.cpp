// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;

const int MAXN = 300005;

ll a[MAXN];
ll dp[MAXN];

ll K[MAXN];
ll B[MAXN];
int ptr = 0;
int sz = 0;

bool is_bad(int l1, int l2, int l3) {
    return (i128)(B[l2] - B[l1]) * (K[l2] - K[l3]) >= (i128)(B[l3] - B[l2]) * (K[l1] - K[l2]);
}

void add_line(ll k, ll b) {
    K[sz] = k;
    B[sz] = b;
    while (sz - ptr >= 2 && is_bad(sz - 2, sz - 1, sz)) {
        K[sz - 1] = K[sz];
        B[sz - 1] = B[sz];
        sz--;
    }
    sz++;
}

ll get_min(ll x) {
    while (ptr + 1 < sz && K[ptr + 1] * x + B[ptr + 1] <= K[ptr] * x + B[ptr]) {
        ptr++;
    }
    return K[ptr] * x + B[ptr];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    sort(a, a + n);
    ll mx = a[n - 1];

    add_line(0, 0);

    for (int i = 1; i < n; i++) {
        ll x = a[i - 1];
        dp[i] = mx + 1LL * (i - 1) * x + get_min(x);
        add_line(-i, dp[i]);
    }

    ll sum_vals = 0;
    for (int i = 0; i < n - 1; i++) {
        sum_vals += a[i];
    }

    cout << dp[n - 1] - sum_vals << "\n";

    return 0;
}