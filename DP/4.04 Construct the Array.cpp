
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int Inv(int a)
{
    int res = 1;
    int p = mod - 2;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int main() {
    int n;
    int k;
    int x;
    cin >> n >> k >> x;
    int res1 = 1, res0 = 0;
    for (int i = 1; i < n; i++) {
        int nres1 = res0;
        int nres0 = (ll(res1) * (k - 1) + ll(res0) * (k - 2)) % mod;
        res1 = nres1; res0 = nres0;
    }
    if (x == 1) printf("%d\n", res1);
    else {
        int res = ll(res0) * Inv(k - 1) % mod;
        printf("%d\n", res);
    }
    return 0;
}

