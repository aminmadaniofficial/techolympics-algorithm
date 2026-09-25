// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, h, c;
    cin >> n >> h >> c;

    long long first = h + c;

    if (n <= first) {
        cout << n * n << '\n';
        return;
    }

    long long remaining = n - first;
    long long dor = remaining / (2 * h);
    long long last = (remaining % (2 * h)) / 2;

    long long ans = (first * first) + (dor * h * h) + (last * last);

    cout << ans << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}