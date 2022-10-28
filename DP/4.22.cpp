#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { ll B, T, F, P; };

unsigned MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int UNKO = INT_MAX;

int main() {
    int m, r, s; cin >> m >> r >> s;
    vector<int> x(m);
    for (int i = 0; i < m; i++)
        cin >> x[i];
    if ((r + s) % 2 || r < s) {
        cout << 0 << endl;
        return 0;
    }
    int A = (r + s) / 2, B = (r - s) / 2;
    vector<vector<ll> > dp(m + 1, vector<ll>(2001));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        vector<vector<ll> > _dp = dp;
        for (int j = 0; j + 1 <= m; j++)
            for (int k = 0; k + x[i] <= 2000; k++)
                _dp[j + 1][k + x[i]] = (_dp[j + 1][k + x[i]] + dp[j][k]) % MOD;
        dp = _dp;
    }
    ll a = 0, b = 0, ans = 0;
    for (int j = 1; j <= m; j++) {
        a = dp[j][A] % MOD;
        b = dp[j][B] % MOD;
        ans = (ans + a * b) % MOD;
    }
    cout << ans << endl;
}
