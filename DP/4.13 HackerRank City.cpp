#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) (((s)&(1<<(i)))>0)
#define Two(x) (1<<(x))
const int MOD = 1000000007;
const int nmax = 1000100;
const double E = 1e-8;
const double PI = acos(-1);
typedef long long LL;
typedef pair<int,int> pii;
int N,m,stest;

LL s[nmax], n[nmax];
LL a, f[nmax];
LL l[nmax];

int main() {
  //freopen("input.txt","r",stdin);
  s[0] = 0;
  n[0] = 1;
  l[0] = 0;
  f[0] = 0;
  cin >> N;
  For(i,1,N) {
    cin >> a;

    n[i] = (4 * n[i-1] + 2) % MOD;

    l[i] = ( 2 * l[i-1] + 3 * a ) % MOD;

    f[i] = (
      f[i-1] +
      l[i-1] + a +
      (f[i-1] + ( 2 * a + l[i-1] ) * n[i-1]) % MOD +
      l[i-1] + 2 * a +
      ( f[i-1] + ( 3 * a + l[i-1] ) * n[i-1] ) * 2 % MOD
    ) % MOD;

    s[i] = (
      4 * s[i-1] +
      ( f[i-1] * n[i-1] * 2 % MOD + n[i-1] * n[i-1] * 2 % MOD * a % MOD) * 2 +
      ( f[i-1] * n[i-1] * 2 % MOD + n[i-1] * n[i-1] * 3 % MOD * a % MOD) * 4 +
      ( f[i-1] + a * n[i-1] ) * 4 +
      ( f[i-1] + a * 2 * n[i-1] ) * 4 +
      a
    ) % MOD;
  }
  cout << s[N] << endl;
  return 0;
}
