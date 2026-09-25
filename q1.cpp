// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int b1, b2, b3;
    cin >> b1 >> b2 >> b3;

    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    int x = a1 + (2 * a2) + a3;
    int y = b1 + (2 * b2) + b3;
    int z = c1 + (2 * c2) + c3;

    int maximum = max({x, y, z});

    if (x == maximum) {
        cout << 1 << '\n';
    }

    else if (y == maximum) {
        cout << 2 << '\n';
    }

    else {
        cout << 3 << '\n';
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}