// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, h, c;
    cin >> n >> h >> c;

    if (n <= h + c) {
        cout << n * n << '\n';
        return;
    }

    long long total = (h + c) * (h + c);
    long long remaining = n - (h + c);
    
    total += (remaining / (2 * h)) * (h * h);
    
    long long last = (remaining % (2 * h)) / 2;
    total += last * last;

    cout << total << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}