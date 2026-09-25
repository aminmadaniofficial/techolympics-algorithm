// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> L(n, 0);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            L[i] = L[i - 1] + 1;
        }
    }

    vector<int> R(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            R[i] = R[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (L[i] > 0 && R[i] > 0) {
            cout << min(L[i], R[i]) << ' ';
        }
        
        else {
            cout << max(L[i], R[i]) << ' ';
        }
    }
    
    cout << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}