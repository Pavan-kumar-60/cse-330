#include <stdio.h>
#include <string.h>

#define NMAX 101
#define VMAX 10001

int A[NMAX];
char ok[VMAX];
int N, G, i, j, sum;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &G);
		for (sum = 0, i = 1; i <= N; i++) {
			scanf("%d", &(A[i]));
			sum += A[i];
		}

		memset(ok, 0, sizeof(ok));
		ok[0] = 1;
		for (i = 1; i <= N; i++)
			for (j = VMAX - 1 - A[i]; j >= 0; j--)
				if (ok[j]) ok[j + A[i]] = 1;

		for (i = 0; i < VMAX; i++)
			if (ok[i] && i <= G && (sum - i) <= G) {
				printf("YES\n");
				break;
			}

		if (i == VMAX)
			printf("NO\n");
	}

	return 0;
}
