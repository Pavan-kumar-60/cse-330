#include <bits/stdc++.h>
 
using namespace std;
 
 
 
#define max 10000000
 
bool prime[max] = { false };
 
 
 
void SieveOfEratosthenes(int maxm)
 
{
 
prime[0] = prime[1] = true;
 
for (int i = 2; i * i <= maxm; i++)
 
    {
 
if (!prime[i])
 
        {
 
for (int j = i * i; j <= maxm; j += i)
 
            {
 
prime[j] = true;
 
}
 
}
 
}
 
}
 
void print_nearest_prime(int arr[], int N)
 
{
 
int maxm = *max_element(arr, arr + N);
 
SieveOfEratosthenes(maxm);
 
 
 
vector<int> primes;
 
for (int i = 0; i < N; i++)
 
    {
 
if (!prime[arr[i]])
 
primes.push_back(i);
 
}
 
if (primes.size() == 0)
 
    {
 
for (int i = 0; i < N; i++)
 
        {
 
cout << -1 << " ";
 
}
 
return;
 
}
 
int curr = 0;
 
for (int i = 0; i < N; i++)
 
    {
 
if (curr == primes.size() - 1 || i <= primes[curr])
 
        {
 
cout << primes[curr]+1 << " ";
 
continue;
 
}
 
if (abs(primes[curr] - i) <= abs(primes[curr + 1] - i))
 
        {
 
cout << primes[curr]+1 << " ";
 
}
 
else
 
        {
 
curr++;
 
cout << primes[curr]+1 << " ";
 
}
 
}
 
}
 
int main()
 
{
 
    ios_base::sync_with_stdio(0);
 
    cin.tie(0);
 
    cout.tie(0);
 
int N;
 
    cin>>N;
 
    int arr[N];
 
    for(int i=0;i<N;i++)
 
     cin>>arr[i];
 
print_nearest_prime(arr, N);
 
return 0;
 
}
