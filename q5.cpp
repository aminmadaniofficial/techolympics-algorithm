// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXK = 55;

int S[MAXK][MAXK];
ll fact[MAXK];

ll qpow(ll b, ll p) {
    ll res = 1;
    b %= MOD;
    while (p > 0) {
        if (p & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        p >>= 1;
    }
    return res;
}

struct Poly {
    int deg;
    int c[MAXK];

    Poly() {
        deg = 0;
        memset(c, 0, sizeof(c));
    }
};

Poly add(const Poly& A, const Poly& B, int K) {
    Poly res;
    res.deg = min(K, max(A.deg, B.deg));
    for (int i = 0; i <= res.deg; i++) {
        res.c[i] = A.c[i] + B.c[i];
        if (res.c[i] >= MOD) res.c[i] -= MOD;
    }
    return res;
}

Poly mul(const Poly& A, const Poly& B, int K) {
    Poly res;
    res.deg = min(K, A.deg + B.deg);
    for (int i = 0; i <= A.deg; i++) {
        if (!A.c[i]) continue;
        for (int j = 0; j <= B.deg && i + j <= K; j++) {
            res.c[i + j] = (res.c[i + j] + 1LL * A.c[i] * B.c[j]) % MOD;
        }
    }
    return res;
}

struct Mat {
    Poly m[4][4];
};

Mat mat_mul(const Mat& A, const Mat& B, int K) {
    Mat res;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                Poly prod = mul(A.m[i][k], B.m[k][j], K);
                res.m[i][j] = add(res.m[i][j], prod, K);
            }
        }
    }
    return res;
}

Mat mat_pow(Mat A, ll p, int K) {
    Mat res;
    for (int i = 0; i < 4; i++) {
        res.m[i][i].deg = 0;
        res.m[i][i].c[0] = 1;
    }
    while (p > 0) {
        if (p & 1) res = mat_mul(res, A, K);
        A = mat_mul(A, A, K);
        p >>= 1;
    }
    return res;
}

void precompute() {
    S[0][0] = 1;
    for (int i = 1; i < MAXK; i++) {
        for (int j = 1; j <= i; j++) {
            S[i][j] = (1LL * j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < MAXK; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    ll n;
    int k;
    if (!(cin >> n >> k)) return;

    Mat T;
    T.m[0][0].c[0] = 3;
    T.m[0][1].c[0] = 1;
    T.m[0][2].c[0] = 1;
    T.m[0][3].c[0] = 1;

    T.m[1][1].c[0] = 4;
    T.m[1][2].c[0] = 1; if (k >= 1) { T.m[1][2].c[1] = 1; T.m[1][2].deg = 1; }
    T.m[1][3].c[0] = 1; if (k >= 1) { T.m[1][3].c[1] = 1; T.m[1][3].deg = 1; }

    T.m[2][1].c[0] = 1;
    T.m[2][2].c[0] = 4;
    T.m[2][3].c[0] = 1; if (k >= 1) { T.m[2][3].c[1] = 1; T.m[2][3].deg = 1; }

    T.m[3][1].c[0] = 1;
    T.m[3][2].c[0] = 1;
    T.m[3][3].c[0] = 4;

    Mat Tn = mat_pow(T, n, k);

    Poly total;
    for (int j = 0; j < 4; j++) {
        total = add(total, Tn.m[0][j], k);
    }

    ll sum_g_k = 0;
    for (int j = 0; j <= k; j++) {
        ll term = 1LL * S[k][j] * fact[j] % MOD;
        term = (term * total.c[j]) % MOD;
        sum_g_k = (sum_g_k + term) % MOD;
    }

    ll inv3 = qpow(3, MOD - 2);
    ll inv_3n = qpow(inv3, n % (MOD - 1));
    ll ans = (sum_g_k * inv_3n) % MOD;

    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}