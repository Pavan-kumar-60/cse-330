#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 52;

int Q;
int N;
int val[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int main()
{
    cin >> Q;
    for (int test = 0; test < Q; test++)
    {

    cin >> N;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                val[i][j][k] = dp[i][j][k] = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                cin >> val[i][j][k];
                dp[i][j][k] = val[i][j][k];
            }

    for (int i = 1; i <= N; i++)
    {
        int ans = 0;
        for (int j = 0; j <= N - i; j++)
            for (int k = 0; k <= N - i; k++)
                for (int l = 0; l <= N - i; l++)
                {
                    if (dp[j][k][l] == i) ans++;

                    for (int m = 0; m < 2; m++)
                        for (int n = 0; n < 2; n++)
                            for (int o = 0; o < 2; o++)
                                dp[j][k][l] = max (dp[j][k][l], dp[j+m][k+n][o+l]);
                
                }

        cout << ans;
        if (i < N)
            cout << " ";
    }
    cout << "\n";
    }
    return 0;
}
