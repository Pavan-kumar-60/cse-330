#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int fixedLengthPowerSum(int X, int N, int k, int min)
{
    float max = pow(X/k, 1.0f/N);
    if(k == 1)
    {
        int nthRoot = round(max);
        return nthRoot >= min && pow(nthRoot, N) == X  ? 1 : 0;
    }   
    // Otherwise, keep digging down
    int sum = 0;
    for(int i = min; i <= max; i++)
    {
        sum += fixedLengthPowerSum(X - pow(i, N), N, k-1, i + 1);
    }
    return sum;
}

int powerSum(int X, int N) 
{
    // One edge case
    if(X == 1)
    {
        return 1;
    }   
    int sum = 0;
    int i = 1;
    while(sum < X)
    {
        sum += pow(i, N);
        i++;
    }  
    sum = 0;
    for(int k = 1; k < i; k++)
    {
        sum+= fixedLengthPowerSum(X, N, k, 1);
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
