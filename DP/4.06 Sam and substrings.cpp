#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;

int main() {
    string s;
    cin >> s;
    long long pw[s.length() + 1];
    pw[0] = 1;
    for (int i = 1; i <= (int)s.length(); ++i) {
        pw[i] = pw[i - 1] * 10 % mod;
    }
    long long sum[s.length() + 1];
    sum[0] = pw[0];
    for (int i = 1; i <= (int)s.length(); ++i) {
        sum[i] = sum[i - 1] + pw[i];
        sum[i] %= mod;
    }
    long long ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        ans += (s[i] - '0') * (i + 1) * sum[n - 1 - i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
