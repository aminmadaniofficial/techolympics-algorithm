// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 300005;
ll a[MAXN];
ll pref[MAXN];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    if (!(cin >> n)) return 0;

    int m = n - 1;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    if (n <= 1) {
        cout << 1 << "\n";
        return 0;
    }

    pref[0] = 0;
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    ll ans = a[0];

    for (int l = 1; l < m; l++) {
        ll p = pref[l];

        ll s1 = (l - 1 >= 60 ? (1LL << 60) : (1LL << (l - 1)));
        ll r1 = min((ll)m - 1, l + s1 - 1);
        if (r1 >= l) {
            ll w1 = pref[r1 + 1] - pref[l];
            ans = max(ans, w1 + 1 - p);
        }

        ll s2 = (l >= 60 ? (1LL << 60) : (1LL << l));
        ll r2 = min((ll)m - 1, l + s2 - 1);
        if (r2 >= l) {
            ll w2 = pref[r2 + 1] - pref[l];
            ans = max(ans, w2 - p);
        }
    }

    cout << max(1LL, ans) << "\n";

    return 0;
}