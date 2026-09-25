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
    
    int first = 0;
    int last = 1;

    for (int i = 1; i < n; i++) {
        long long x = a[i - 1];
        
        while (last - first >= 2) {
            int j1 = q[first];
            int j2 = q[first + 1];

            if (dp[j2] - (j2 * x) <= dp[j1] - (j1 * x)) {
                first++;
            } 

            else {
                break;
            }
        }

        int j = q[first];
        dp[i] = dp[j] + maximum + ((i - j - 1) * x);

        while (last - first >= 2) {
            int j1 = q[last - 2];
            int j2 = q[last - 1];

            long long y1 = dp[j2] - dp[j1];
            long long x1 = j2 - j1;
            
            long long y2 = dp[i] - dp[j2];
            long long x2 = i - j2;
            
            if (y1 * x2 >= y2 * x1) {
                last--;
            } 

            else {
                break;
            }
        }
        
        q[last++] = i;
    }

    long long ans = dp[n - 1] - sum;
    cout << ans << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    solve();
    return 0;
}