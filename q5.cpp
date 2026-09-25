// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    int k;
    if (!(cin >> n >> k)) return;

    const int MOD = 1e9 + 7;

    auto power = [&](long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
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

    long long trans[4][4][55] = {};
    long long res[4][4][55] = {};

    for (int i = 0; i < 4; i++) {
        res[i][i][0] = 1;
    }

    for (int last = 0; last < 4; last++) {
        trans[last][last][0] += 3;
        for (int next_digit = 1; next_digit <= 3; next_digit++) {
            trans[last][next_digit][0] += 1;
            if (last > 0 && next_digit > last) {
                trans[last][next_digit][1] += 1;
            }
        }
    }

    auto multiply = [&](long long A[4][4][55], long long B[4][4][55]) {
        long long C[4][4][55] = {};
        for (int i = 0; i < 4; i++) {
            for (int mid = 0; mid < 4; mid++) {
                for (int j = 0; j < 4; j++) {
                    for (int d1 = 0; d1 <= k; d1++) {
                        if (A[i][mid][d1] == 0) continue;
                        for (int d2 = 0; d1 + d2 <= k; d2++) {
                            C[i][j][d1 + d2] = (C[i][j][d1 + d2] + A[i][mid][d1] * B[mid][j][d2]) % MOD;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int d = 0; d <= k; d++) {
                    A[i][j][d] = C[i][j][d];
                }
            }
        }
    };

    long long steps = n;
    while (steps > 0) {
        if (steps % 2 == 1) {
            multiply(res, trans);
        }
        multiply(trans, trans);
        steps /= 2;
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

    long long total = power(3, n % (MOD - 1));
    long long inv = power(total, MOD - 2);
    ans = (ans * inv) % MOD;

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