#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
  
int main() {
    int T;
    cin>>T;
      
    while (T--) {
        long ans = 0, k;
        string p, q;
         
        cin>>k>>p>>q;
          
        int n = (int) p.size();
        long *currk = new long [2*n+1]();
        auto st = new long [2*n+1][2]();
        long lcs[n+1][n+1];
        memset(lcs, 0, sizeof(lcs[0][0]) * (n+1) * (n+1));
          
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                currk[i-j+n] = 0;
                if (i >= j) {
                    st[i-j+n][0] = i-j+1;
                    st[i-j+n][1] = 1;
                } else {
                     st[i-j+n][0] = 1;
                     st[i-j+n][1] = j-i+1;
                }
            }
        }
          
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                 
                //Longest Common Substring DP
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;
                    currk[i-j+n] = 0;
                } else if (p[i-1] == q[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else if (p[i-1] != q[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                    currk[i-j+n]++;
                }
                  
                //Sliding Window technique
                if (currk[i-j+n] > k) {
                    long l, m, ctr = 0, flag = 0;
                      
                    for(l=st[i-j+n][0], m=st[i-j+n][1]; l<i && m<j; l++, m++) {
                        ctr++;
                        if (p[l-1] != q[m-1]) {
                            flag = 1;
                            break;
                        }
                    }
                      
                    if (flag) {
                        lcs[i][j] = lcs[i-1][j-1] - ctr + 1;
                        st[i-j+n][0] = l+1;
                        st[i-j+n][1] = m+1;
                        currk[i-j+n]--;
                    }
                }
                  
                if (lcs[i][j] > ans) {
                    ans = lcs[i][j];
                }
            }
        }
          
        printf("%ld\n",ans);
    }
     
    return 0;
}
