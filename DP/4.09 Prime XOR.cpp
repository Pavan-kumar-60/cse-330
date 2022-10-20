#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,i,j,k,m,x;
ll primes[200005], b[200005], dp[2005][8505];
set<ll> f;
set<ll>::iterator itr;
int main()
{
 //freopen("input.txt","r",stdin);
 for (i = 2; i <= 10000; i++)
  primes[i] = 1;
 for (i = 2; i <= 10000; i++)
  if (primes[i])
  for (j = i*2; j <= 10000; j+=i)
   primes[j] = 0;
 ll q;
 cin >> q;
 while (q--)
 {
  cin >> n;
  for (i = 3500; i <= 4500; i++)
   b[i] = 0;
  for (i = 0; i < n; i++)
  {
   scanf("%lld",&x);
   b[x]++;
  }
  for (i = 0; i <= 1001; i++)
   for (j = 0; j <= 8192; j++)
    dp[i][j] = 0;
  dp[0][0] = 1;
  for (i = 0; i <= 1000; i++)
   for (j = 0; j < 8192; j++)
   {
    dp[i+1][j^(i+3500)] = (dp[i+1][j^(i+3500)] + dp[i][j]*((b[i+3500]+1)/2))%MOD;
    dp[i+1][j] = (dp[i+1][j] + dp[i][j]*(b[i+3500]/2+1))%MOD;
   }
  ll ans = 0;
  for (j = 0; j < 8192; j++)
   if (primes[j])
      ans += dp[1001][j];
  cout << ans%MOD << endl;
 }
 return 0;
}

