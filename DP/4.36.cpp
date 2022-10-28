#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <complex>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define mp(a,b) make_pair(a,b)
#define LL long long
#define S(n) scanf("%d", &n)
#define Sa(n,i) scanf("%d", n+i)
#define N 100000
#define MOD 1000000007
#define EPS 0.00000001

LL a[N], b[N], d[N];

int main(){
    
    int n;
    LL C;
    cin >> n >> C;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n) d[i] = min(a[i], C) - b[i];
    int s = max_element(d, d + n) - d;
    LL t = 0, need = 0;
    forn(i, n){ t += a[(s + i) % n]; if(t > C) t = C; t -= b[(s + i) % n]; if(t < 0){ cout << 0; return 0;} }
    int res = 1;
    forn(i, n - 1){
        int cur = s - 1 - i;
        if(cur < 0) cur += n;
        if(d[cur] >= need) res += 1, need = 0;
        else{ assert(need + b[cur] <= C); need = need + b[cur] - a[cur]; }
    }
    cout << res;
    
    return 0;
}
