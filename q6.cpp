// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;

const int MAXN = 300005;
ll a[MAXN], dp[MAXN];
ll m[MAXN], c[MAXN];
int head, tail;

bool bad(int l1, int l2, int l3) {
    return (i128)(c[l2] - c[l1]) * (m[l2] - m[l3]) >= (i128)(c[l3] - c[l2]) * (m[l1] - m[l2]);
}

void add(ll slope, ll intercept) {
    m[tail] = slope;
    c[tail] = intercept;
    while (tail - head >= 2 && bad(tail - 2, tail - 1, tail)) {
        m[tail - 1] = m[tail];
        c[tail - 1] = c[tail];
        tail--;
    }
    tail++;
}

ll query(ll x) {
    while (head + 1 < tail && m[head + 1] * x + c[head + 1] <= m[head] * x + c[head]) {
        head++;
    }
    return m[head] * x + c[head];
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

    add(0, 0);

    for (int i = 1; i < n; i++) {
        ll x = a[i - 1];
        dp[i] = mx + 1LL * (i - 1) * x + query(x);
        add(-i, dp[i]);
    }

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
    }

    cout << dp[n - 1] - sum << "\n";
    return 0;
}