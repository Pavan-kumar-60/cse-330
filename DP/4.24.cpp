#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;
int a[100000];
LL sum[100001];

int main() {
    scanf("%d", &tt);
    REP(test, tt) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", a + i);
        sort(a, a + n);
        sum[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum[i] = sum[i + 1] + a[i];
        }
        LL ans = 0;
        REP(i, n) {
            ans = max(ans, (i + 1) * sum[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
