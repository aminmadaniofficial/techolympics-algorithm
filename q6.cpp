// Coded By Mohammad Davoudi & Amin Madani

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    sort(a.begin(), a.end());
    
    long long maximum = a[n - 1];
    sum -= maximum;

    vector<long long> dp(n, 0);
    vector<int> q(n, 0);
    
    int head = 0, tail = 1;

    for (int i = 1; i < n; i++) {
        long long x = a[i - 1];
        
        while (tail - head >= 2) {
            int j1 = q[head];
            int j2 = q[head + 1];

            if (dp[j2] - (j2 * x) <= dp[j1] - (j1 * x)) {
                head++;
            } 
            else {
                break;
            }
        }

        int j = q[head];
        dp[i] = dp[j] + maximum + ((i - j - 1) * x);

        while (tail - head >= 2) {
            int j1 = q[tail - 2];
            int j2 = q[tail - 1];

            double slope1 = 1.0 * (dp[j2] - dp[j1]) / (j2 - j1);
            double slope2 = 1.0 * (dp[i] - dp[j2]) / (i - j2);
            
            if (slope1 >= slope2) {
                tail--;
            } 
            
            else {
                break;
            }
        }
        
        q[tail++] = i;
    }

    long long ans = dp[n - 1] - sum;
    cout << ans << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}