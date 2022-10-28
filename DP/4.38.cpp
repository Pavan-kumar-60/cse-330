#include <stdio.h>

#define MOD 1000000007
#define NMAX 2501

long long cnt1[NMAX][NMAX], scnt1[NMAX][NMAX], cnt2[NMAX][NMAX];
int N, K, i, j;

int main() {
//	freopen("x.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	
	for (i = 0; i <= K; i++) {
		cnt1[2][i] = 1;
		scnt1[2][i] = i + 1;
	}

	for (i = 3; i <= N; i++)
		for (j = 0; j <= K; j++) {
			cnt1[i][j] = scnt1[i - 1][j];
			if (j - i >= 0) {
				cnt1[i][j] -= scnt1[i - 1][j - i];
				if (cnt1[i][j] < 0) cnt1[i][j] += MOD;
			}			
			scnt1[i][j] = cnt1[i][j];
			if (j > 0) {
				scnt1[i][j] += scnt1[i][j - 1];
				if (scnt1[i][j] >= MOD) scnt1[i][j] -= MOD;
			}
		}

	for (j = 0; j <= K; j++)
		cnt2[1][j] = 1;
	for (i = 2; i <= N; i++)
		for (j = 0; j <= K; j++) {
			cnt2[i][j] = cnt2[i - 1][j];
			if (j > 0) {
				cnt2[i][j] = (cnt2[i][j] + cnt2[i - 1][j - 1] * (long long) (i - 1)) % MOD;
			}
		}

		
	printf("%lld %lld\n", cnt1[N][K], cnt2[N][K]);
	return 0;
}
