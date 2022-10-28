/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st;
long dp[3050][3050],mpref[3050],msuf[3050];
long n;
long ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
n=st.size();
for (int r=0;r<n;r++)
{
 for (int l=r;l>=0;l--)
 {
  if (l==r-1)
  dp[l][r]=(st[l]==st[r]);
  dp[l][r]=max(dp[l][r],n-(n-1));
  dp[l][r]=max(dp[l][r],dp[l+1][r]);
  dp[l][r]=max(dp[l][r],dp[l][r-1]);
  if (st[l]==st[r]&&l<r)
   dp[l][r]=max(dp[l][r],dp[l+1][r-1]+2);
 }
}
/*
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
     cout<<dp[i][j]<<" ";
    cout<<endl;
}*/

for (int i=0;i<n;i++)
{
 for (int j=0;j<=i;j++)
  mpref[i]=max(mpref[i],dp[j][i]);
 for (int j=i;j<n;j++)
  msuf[i]=max(msuf[i],dp[i][j]);
}

for (int i=1;i<n;i++)
 mpref[i]=max(mpref[i],mpref[i-1]);
for (int i=n-2;i>=0;--i)
 msuf[i]=max(msuf[i],msuf[i+1]);

ans=0;
for (int i=0;i<n;i++)
 ans=max(ans,mpref[i]*msuf[i+1]);
cout<<ans<<endl;


cin.get();cin.get();
return 0;}
