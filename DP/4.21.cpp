#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef ONLINE_JUDGE
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#else
#define Eo(x)
#endif

typedef long long int64;
const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
typedef double real;
const real eps = 1e-6;
typedef pair<int,int> pip;

template <typename A,typename B>
ostream& operator<<(ostream& os, const pair<A,B>& p) {
    return os << p.first << "," << p.second;
}

template <typename A>
ostream& operator<<(ostream& os, const vector<A>& v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ';';
    }
    return os;
}

template <typename A, typename B>
ostream& operator<<(ostream& os, const map<A,B>& m) {
  for (typename map<A,B>::const_iterator it = m.begin(); it != m.end(); ++it) {
    os << it->first << ":" << it->second << ";";
  }
  return os;
}

int64 gcd(int64 a, int64 b) {
    return a ? gcd(b%a,a) : b;
}

const int maxn = 52;
vector<int> g[maxn];
int n,k;
int64 res[maxn][maxn];
int64 d2[maxn][maxn];
int64 part[maxn][maxn];

void dfs(int v, int par) {
    //Eo(pip(v,par));
    for (int i = 0; i < g[v].size(); i++) {
        int p = g[v][i];
        if (p == par) continue;
        dfs(p,v);
    }
    int z = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int p = g[v][i];
        if (p == par) continue;
        for (int j = 0; j <= n; j++) {
            part[z][j] = res[p][j];
        }
        z++;
    }
    for (int i = 0; i <= z; i++) {
        for (int j = 0; j <= n; j++) {
            d2[i][j]=0;
        }
    }
    d2[0][0]=1;
    for (int i = 0; i < z; i++) {
        for (int j = 0; j <= n; j++) if (d2[i][j]) {
            d2[i+1][j+1] += d2[i][j];
            for (int k = 0; k+j <= n; k++) {
                d2[i+1][j+k] += d2[i][j]*part[i][k];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        res[v][i] = d2[z][i];
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x,y; scanf("%d%d",&x,&y);
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0,-1);
    int64 sum = 1;
    for (int i = 0; i <= k; i++) {
        sum += res[0][i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i <= k-1; i++) {
            sum += res[j][i];
        }
    }
    cout << sum << endl;
#if 0
    for (int i =0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ",int(res[i][j]));
        }
        puts("");
    }
#endif
    return 0;
}
