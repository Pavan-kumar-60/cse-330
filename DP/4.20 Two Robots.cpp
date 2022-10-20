#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int Infinity = 1000000007;
const int NotInit = -1;

struct Query {
	int from, to, dist;

	Query(int from = 0, int to = 0, int dist = 0)
		: from(from),
		  to(to),
		  dist(dist) {}

	void scan() {
		scanf("%d%d", &from, &to);
		dist = abs(from - to);
	}
};

vector<Query> queries;
vector<vector<int>> dp;

int minDistance(int x, int y) {
	if (dp[x][y] != NotInit)
		return dp[x][y];
	int result = Infinity;
	auto queryId = max(x, y);
	auto& query = queries[queryId];
	if (min(x, y) + 1 < queryId) {
		result = x == queryId 
			? minDistance(x - 1, y) 
			: minDistance(x, y - 1);
		result += query.dist;
		result += abs(queries[queryId - 1].to - query.from);
	}
	else {
		for (int i = 0; i < queryId-1; ++i) {
			int prevDistance = x == queryId 
				? minDistance(i, y) 
				: minDistance(x, i);
			int newDistance = i == 0 ? 0 : abs(query.from - queries[i].to);
			result = min(result, prevDistance + newDistance + query.dist);
		}
	}
	dp[x][y] = result;
	return result;
}

void solve() {
	int n, m;
	scanf("%d%d", &m, &n);
	queries.resize(n+1);
	for (int i = 1; i <= n; ++i) {
		queries[i].scan();
	}

	dp.resize(n+1);
	for (int i = 0; i <= n; ++i) {
		dp[i].assign(n+1, NotInit);
	}
	dp[0][1] = queries[1].dist;
	dp[1][0] = queries[1].dist;

	int ans = Infinity;
	for (int i = 0; i <= n; ++i) {
		ans = min(ans, minDistance(i, n));
		ans = min(ans, minDistance(n, i));
	}
	printf("%d\n", ans);
}

int main(void) {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);
	while(t --> 0) {
		solve();
	}

	return 0;
}
