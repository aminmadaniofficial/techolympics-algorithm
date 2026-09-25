// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int K;
ll S[55][55], fact[55];

struct Mat {
    int a[4][4][55];
    Mat() { memset(a, 0, sizeof(a)); }
};

Mat mul(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                for (int p = 0; p <= K; p++) {
                    if (!A.a[i][k][p]) continue;
                    for (int q = 0; p + q <= K; q++) {
                        C.a[i][j][p + q] = (C.a[i][j][p + q] + 1LL * A.a[i][k][p] * B.a[k][j][q]) % MOD;
                    }
                }
            }
        }
    }
    return C;
}

ll qpow(ll b, ll p) {
    ll res = 1;
    b %= MOD;
    while (p > 0) {
        if (p & 1) res = res * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    if (!(cin >> n >> K)) return;

    Mat T, res;
    for (int i = 0; i < 4; i++) res.a[i][i][0] = 1;

    T.a[0][0][0] = 3; T.a[0][1][0] = 1; T.a[0][2][0] = 1; T.a[0][3][0] = 1;
    T.a[1][1][0] = 4; T.a[1][2][0] = 1; T.a[1][3][0] = 1;
    T.a[2][1][0] = 1; T.a[2][2][0] = 4; T.a[2][3][0] = 1;
    T.a[3][1][0] = 1; T.a[3][2][0] = 1; T.a[3][3][0] = 4;
    if (K >= 1) {
        T.a[1][2][1] = 1;
        T.a[1][3][1] = 1;
        T.a[2][3][1] = 1;
    }

    ll p = n;
    while (p > 0) {
        if (p & 1) res = mul(res, T);
        T = mul(T, T);
        p >>= 1;
    }

    ll sum_g_k = 0;
    for (int j = 0; j <= K; j++) {
        ll total = 0;
        for (int i = 0; i < 4; i++) total = (total + res.a[0][i][j]) % MOD;
        ll term = S[K][j] * fact[j] % MOD * total % MOD;
        sum_g_k = (sum_g_k + term) % MOD;
    }

    ll inv3 = qpow(3, MOD - 2);
    ll ans = sum_g_k * qpow(inv3, n % (MOD - 1)) % MOD;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    S[0][0] = 1;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= i; j++) {
            S[i][j] = (1LL * j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= 50; i++) fact[i] = fact[i - 1] * i % MOD;

    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}