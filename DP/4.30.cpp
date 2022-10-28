#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int m,n;
char s[55][55];
int dp[2][55][55];
int last,now;

bool valid(int x,int y) {
	return (x>=0) && (x<n) && (y>=0) && (y<m) && (dp[last][x][y]>=0);
}

int haha(int x,int y,char c) {
	return (s[x][y]==c)?0:1;
}

void better(int &x,int y) {
	if ((x<0) || (x>y)) {
		x=y;
	}
}

int main() {
int i,j,t,x,y,ans;
	scanf("%d%d%d",&n,&m,&t);
	memset(dp[0],0xff,sizeof(dp[0]));
	for (i=0;i<n;++i) {
		scanf("%s",s[i]);
	}
	dp[0][0][0]=0;
	ans=(s[0][0]=='*')?0:(-1);
	for (last=0;t;--t) {
		memset(dp[now=1^last],0xff,sizeof(dp[now]));
		for (i=0;i<n;++i) {
			for (j=0;j<m;++j) {
				x=i-1;
				y=j;
				if (valid(x,y)) {
					better(dp[now][i][j],dp[last][x][y]+haha(x,y,'D'));
				}
				x=i+1;
				if (valid(x,y)) {
					better(dp[now][i][j],dp[last][x][y]+haha(x,y,'U'));
				}
				x=i;
				y=j-1;
				if (valid(x,y)) {
					better(dp[now][i][j],dp[last][x][y]+haha(x,y,'R'));
				}
				y=j+1;
				if (valid(x,y)) {
					better(dp[now][i][j],dp[last][x][y]+haha(x,y,'L'));
				}
				if ((s[i][j]=='*') && (dp[now][i][j]>=0)) {
					better(ans,dp[now][i][j]);
				}
			}
		}
		last=now;
	}
	printf("%d\n",ans);
	return 0;
}
