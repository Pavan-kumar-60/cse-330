#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9
#define MAXN 1002
int n,s[MAXN],e[MAXN] ;

int bit[1 << 20] ;
int solve1()
{
 int ret = 0 ;
 for(int i = 1;i < 1 << n;i++)
 {
  bit[i] = bit[i / 2] + (i & 1) ;
  int valid = 1,occ[1002] = {} ;
  for(int j = 0;valid && j < n;j++)
   if(i & 1 << j)
    for(int k = s[j];k <= e[j];k++)
     if(++occ[k] > 2)
     {
      valid = 0 ;
      break ;
     }
  if(valid) ret = max(ret,bit[i]) ;
 }
 return ret ;
}

int memo[MAXN][MAXN],memo2[MAXN][MAXN],f[MAXN] ;
int solve2()
{
 if(n <= 2) return n ;

 for(int i = 0;i < n;i++)
  for(int j = i + 1;j < n;j++)
   if(s[i] > s[j])
   {
    swap(s[i],s[j]) ;
    swap(e[i],e[j]) ;
   }

 for(int i = 0;i < n;i++)
 {
  f[i] = n ;
  int low = i,high = n ;
  while(low + 1 < high)
  {
   int mid = low + (high - low) / 2 ;
   if(s[mid] > e[i]) high = mid ;
   else low = mid ;
  }
  f[i] = high ;
 }

 int ret = 2 ;
 memset(memo2,0,sizeof memo2) ;
 memset(memo,0,sizeof memo) ;
 for(int p1 = n - 2;p1 >= 0;p1--)
  for(int p2 = n - 1;p2 > p1;p2--)
  {
   int nstart = max(p2 + 1,min(f[p1],f[p2])) ;
   if(nstart == n) continue ;
   if(e[p1] < e[p2]) memo[p1][p2] = 1 + memo2[p2][nstart] ;
   else memo[p1][p2] = 1 + memo2[p1][nstart] ;
   memo2[p1][p2] = max(memo2[p1][p2 + 1],memo[p1][p2]) ;
   ret = max(ret,2 + memo[p1][p2]) ;
  }
 return ret ;
}

void gen()
{
 n = rand() % 15 + 1 ;
 for(int i = 0;i < n;i++)
 {
  s[i] = rand() % 20 + 1 ;
  e[i] = rand() % 20 + 1 ;
  if(s[i] > e[i]) swap(e[i],s[i]) ;
 }
}

void test()
{
 for(int t = 0;t < 10000;t++)
 {
  gen() ;
  int ret1 = solve1() ;
  int ret2 = solve2() ;
  cout << ret1 << " " << ret2 << endl ;
  if(ret1 != ret2)
  {
   cout << "failed on: " << t << endl ;
   cout << n << endl ;
   for(int i = 0;i < n;i++) cout << s[i] << " " << e[i] << endl ;
   while(1) ;
  }
 }
}

void generate()
{
 char in[] = "in .txt" ;
 for(int test = 0;test < 10;test++)
 {
  in[2] = test + '0' ;
  FILE * fout = fopen(in,"w") ;
  int runs = 100 ;
  fprintf(fout,"%d\n",runs) ;
  for(int t = 0;t < runs;t++)
  {
   int lim ;
   if(test < 2) n = rand() % 10 + 2,lim = rand() % 10 + 1 ;
   else if(test < 5) n = rand() % 100 + 2,lim = rand() % 100 + 1 ;
   else if(test < 8) n = 1000 - rand() % 100,lim = rand() % 1000000000 + 1 ;
   else n = 1000 - rand() % 100,lim = rand() % 1000 + 1 ;
   
   for(int i = 0;i < n;i++)
   {
    s[i] = rand() % lim + 1 ;
    e[i] = rand() % lim + 1 ;
    if(s[i] > e[i]) swap(s[i],e[i]) ;
   }

   fprintf(fout,"%d\n",n) ;
   for(int i = 0;i < n;i++)
   {
    fprintf(fout,"%d %d\n",s[i],e[i]) ;
   }
  }
 }
}

int main()
{
// test() ; return 0 ;
// generate() ; return 0 ;
 
 int runs ;
 scanf("%d",&runs) ;
 while(runs--)
 {
  scanf("%d",&n) ;
  if(n < 1 || n > 1000) while(1) ;
  for(int i = 0;i < n;i++)
  {
   scanf("%d%d",&s[i],&e[i]) ;
   if(s[i] < 1 || e[i] > (int)1e9 || s[i] > e[i]) { cerr << "bad interval" << endl ; while(1) ; }
  }
  int ret = solve2() ;
  printf("%d\n",ret) ;
 }

 return 0 ;
}
