#include<iostream>
using namespace std; 
#define f_io     ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int Max = 1000005;
int sieve[Max];
int main()
{
	f_io
	sieve[0] = sieve[1] = 0;
	for(int i = 2; i < Max; i+=2)
	{
		sieve[i] = 2;
	}
	for(int i=3;i<Max;i+=2)
    {
		if(sieve[i]==0)
        {
            for(int j=i; j<Max; j+=i)
            {
                if(sieve[j]==0) sieve[j]=i;
            }
        }
	}
 
	int t; cin >> t; 
	while(t--)
	{
		int n;
		cin >> n; 
		cout << n - sieve[n]  << '\n';
	}
}
