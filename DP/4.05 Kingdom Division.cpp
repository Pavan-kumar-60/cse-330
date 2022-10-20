
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define MOD 1000000007
#define MAXN 100010

using namespace std;

typedef long long ll;
typedef vector < int > vi;

ll dp[MAXN][2];
vector < vi > adj;

void Solve(int node, int isdiff, int pre) {
    if (dp[node][isdiff] != -1LL) return;
    
    for (int i=0; i<adj[node].size(); i++) if (adj[node][i] != pre) {
        Solve(adj[node][i], 0, node);
        Solve(adj[node][i], 1, node);
    }
    
    ll retval = 1LL;
    for (int i=0; i<adj[node].size(); i++) if (adj[node][i] != pre)
        retval = (retval * (dp[adj[node][i]][1] + dp[adj[node][i]][0])%MOD)%MOD;
    
    ll del = 0LL;
    if (isdiff) {
        del = 1LL;
        for (int i=0; i<adj[node].size(); i++) if (adj[node][i] != pre)
            del = (del * (dp[adj[node][i]][1])%MOD)%MOD;
    }
    
    retval = (retval + MOD - del)%MOD;
    
    dp[node][isdiff] = retval;
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    adj.assign(n+2, vi());
    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solve(1, 1, -1);
    cout << (dp[1][1]+dp[1][1])%MOD << endl;
    return 0;
}

