// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    int k;
    if (!(cin >> n >> k)) return;

    const int MOD = 1e9 + 7;

    auto power = [&](long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    };

    long long S[55][55] = {};
    long long fact[55] = {1};
    S[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        for (int j = 1; j <= i; j++) {
            S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }

    long long T[4][4][55] = {};
    long long res[4][4][55] = {};

    for (int i = 0; i < 4; i++) {
        res[i][i][0] = 1;
    }

    for (int u = 0; u < 4; u++) {
        T[u][u][0] += 3;
        for (int d = 1; d <= 3; d++) {
            T[u][d][0] += 1;
            if (u > 0 && d > u) {
                T[u][d][1] += 1;
            }
        }
    }

    auto multiply = [&](long long A[4][4][55], long long B[4][4][55]) {
        long long C[4][4][55] = {};
        for (int i = 0; i < 4; i++) {
            for (int m = 0; m < 4; m++) {
                for (int j = 0; j < 4; j++) {
                    for (int p = 0; p <= k; p++) {
                        if (A[i][m][p] == 0) continue;
                        for (int q = 0; p + q <= k; q++) {
                            C[i][j][p + q] = (C[i][j][p + q] + A[i][m][p] * B[m][j][q]) % MOD;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int p = 0; p <= k; p++) {
                    A[i][j][p] = C[i][j][p];
                }
            }
        }
    };

    long long p = n;
    while (p > 0) {
        if (p % 2 == 1) {
            multiply(res, T);
        }
        multiply(T, T);
        p /= 2;
    }

    long long ans = 0;
    for (int j = 0; j <= k; j++) {
        long long ways = 0;
        for (int i = 0; i < 4; i++) {
            ways = (ways + res[0][i][j]) % MOD;
        }
        long long term = (S[k][j] * fact[j]) % MOD;
        term = (term * ways) % MOD;
        ans = (ans + term) % MOD;
    }

    long long total_codes = power(3, n % (MOD - 1));
    long long inv_codes = power(total_codes, MOD - 2);
    ans = (ans * inv_codes) % MOD;

    cout << ans << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}