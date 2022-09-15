#include<bits/stdc++.h>
using namespace std;
bool isPrime (int);
bool isPrime(int n)
{
if(n<=1)
{
return false;
}
if(n<=3)
{
return true;
}
if(n%2==0 || n%3==0)
{
return false;
}
for(int i=5;i*i<=n;i=i+6)
{
if(n%i==0 || n%(i+2)==0)
{
return false;
}
}
return true;
}
string solve (int N) 
{
if(N<=3)
return "No";

bool num= isPrime(N);
if(num)
return "No";
else
return "Yes";

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;

        string out_;
        out_ = solve(N);
        cout << out_;
        cout << "\n";
    }
}
