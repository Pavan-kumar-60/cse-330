#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000;
const int Maxn = 3005;

int n, k;
int a[Maxn];
ll dp[Maxn][Maxn];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    fill((ll*)dp, (ll*)dp + Maxn * Maxn, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i && j <= k; j++) if (dp[i][j] < Inf) {
            int my = j, his = i - j;
            if (my < k) {
                ll add = ll(a[i]) * (his - (n - k - his));
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + add);
            }
            if (his < n - k) {
                ll add = ll(a[i]) * (my - (k - my));
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + add);
            }
        }
    printf("%lld\n", dp[n][k]);
    return 0;
}

