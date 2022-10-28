#include <iostream>
#include <vector>

using namespace std;
const int maxAllowed = 100000;

#define  MAX(a, b) ((a > b) ? (a) : (b))

vector<int> 
longestCommonSubseq(const vector<int> & arrayA, const vector<int> & arrayB)
{
    typedef vector<int>::size_type VecSz;
    VecSz m = arrayA.size(), n = arrayB.size();
    int i = 0, j = 0;
    vector<int> lcs;
    int ** LCS = new int *[m+1];

    for (i = 0; i <= m; ++i) {
        LCS[i] = new int[n+1];
        if (NULL == LCS[i]) {
            cout << "Failed to allocate memory" << endl;
            return lcs;
        }
    }

    for (j = 0; j <= n; ++j) LCS[0][j] = 0;
    for (i = 0; i <= m; ++i) LCS[i][0] = 0;
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (arrayA[i-1] == arrayB[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = MAX(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }
    i = m; j = n;
    while (i > 0 && j > 0) {
        if (arrayA[i-1] == arrayB[j-1]) {
            lcs.push_back(arrayA[i-1]);
            --i;
            --j;
        } else {
           if(LCS[i][j-1] > LCS[i-1][j]) --j;
           else --i;
        }
    }
    for (i = 0; i <= m; ++i) {
        delete[] LCS[i];
    }
    delete [] LCS;
    return lcs;
}

istream & 
readInput(istream & in, vector<int> & array, int M)
{
    int i = 0;
    while (i < M) {
        int x;
        in >> x;
        if (x > maxAllowed) {
            cout << "Invalid Input" << endl;
            break;
        }
        array.push_back(x);
        ++i;
    }
    return in;
}

int main(void)
{
    int M, N;

    cin >> M >> N;
    vector<int> arrayA;
    vector<int> arrayB;
    readInput(cin, arrayA, M);
    readInput(cin, arrayB, N);
    vector<int> lcs;

    lcs = longestCommonSubseq(arrayA, arrayB);
    if (lcs.size() > 0) {
        vector<int>::size_type i = lcs.size() - 1;
        for (; i != 0; --i) {
            cout << lcs[i] << " ";
        }
        cout << lcs[0] << endl;
    }
    return 0;
}
