#include <bits/stdc++.h>
using namespace std;
int dp[2005]; 
int main() {
    int a; cin >> a;
    for (int g=0;g<a; g++)
        {memset(dp,0,sizeof(dp)); 
        int b,c; cin >> b >> c; vector <int> t;
        for (int y=0;y<b; y++){int d; cin >> d;t.push_back(d);}
        dp[0]=1; int r=0; 
        for (int g=1; g<=c; g++)
            {
            for (int y=0;y<t.size(); y++)
                {
                if (t[y]>g) continue; if (dp[g-t[y]]) dp[g]=1; 
            }
            if (dp[g]) r=g; 
        }
        cout << r << '\n'; 
    }
    return 0;
}
