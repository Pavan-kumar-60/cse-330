#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000007

int memo[102][102][302] ;
int solve(int D,int x,int M)
{
 if(x <= 0 || x > D) return 0 ;
 if(M == 0) return 1 ;
 if(memo[D][x][M] != -1) return memo[D][x][M] ;
 return memo[D][x][M] = (solve(D,x - 1,M - 1) + solve(D,x + 1,M - 1)) % MOD ;
}

int n,x[10],D[10] ;
int ncr[302][302],memo2[10][302] ;
int solve2(int k,int M)
{
 if(k == n) return M == 0 ? 1 : 0 ;
 if(memo2[k][M] != -1) return memo2[k][M] ;
 int ret = 0 ;
 for(int i = 0;i <= M;i++)
 {
  long long cret = 1LL * solve(D[k],x[k],i) * ncr[M][i] % MOD ;
  ret += cret * solve2(k + 1,M - i) % MOD ;
  if(ret >= MOD) ret -= MOD ;
 }
 return memo2[k][M] = ret ;
}

int brute(int M)
{
 if(M == 0) return 1 ;
 int ret = 0 ;
 for(int i = 0;i < n;i++)
 {
  x[i]-- ;
  if(x[i] >= 1) ret += brute(M - 1) ;
  x[i] += 2 ;
  if(x[i] <= D[i]) ret += brute(M - 1) ;
  x[i]-- ;
 }
 return ret ;
}

int main()
{
 for(int i = 0;i < 302;i++)
 {
  ncr[i][0] = ncr[i][i] = 1 ;
  for(int j = 1;j < i;j++)
   ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD ;
 }
 memset(memo,255,sizeof memo) ;

 int runs ;
 scanf("%d",&runs) ;
 while(runs--)
 {
  int M ;
  scanf("%d%d",&n,&M) ;
  for(int i = 0;i < n;i++) scanf("%d",&x[i]) ;
  for(int i = 0;i < n;i++) scanf("%d",&D[i]) ;
  memset(memo2,255,sizeof memo2) ;
  int ret = solve2(0,M) ;
//  int retB = brute(M) ;
  
//  printf("%d\n",retB) ;
  printf("%d\n",ret) ;
 }
 return 0 ;
}
