// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    long long ans = 1;
    int p = 1;

    for (int i = 2; i <= n; i++) {
        int r = min(n, i - 1 + p);
        int len = r - i + 1;

        int t = 0;
        int x = 1;

        while (x < len) {
            x *= 2;
            t++;
        }

        long long ans2 = a[r] - (2 * a[i - 1]);

        if (i - 2 > t) {
            ans2++;
        }

        ans = max(ans, ans2);

        if (p <= n) {
            p *= 2;
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}