#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

multiset<unsigned long long> s;
vector<unsigned long long> res;

int comb(int n, int k)
{
	if (k == 0)
		return 1;
	if (k > n / 2)
		k = n - k;

	int comb = n;
	for (int i = 2; i <= k; ++i) {
		comb *= (n - i + 1);
		comb /= i;
	}
	return comb;
}

void clean_s(int max_i, unsigned long long sum, int rem_elems){
	if (max_i == 0){
		sum += rem_elems * res[0];
		rem_elems = 0;
	}

	if (rem_elems == 0){
		s.erase(s.find(sum));
	}
	else {
		for (int i = 0; i <= rem_elems; ++i){
			clean_s(max_i - 1, sum + i*res[max_i], rem_elems - i);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		unsigned long long temp;
		s = multiset<unsigned long long>();
		int s_size = comb(n + k - 1, n - 1);
		for (int i = 0; i<s_size; ++i){
			cin >> temp;
			s.insert(temp);
		}

		res = vector<unsigned long long>();
		res.push_back(*s.begin() / k);
		s.erase(s.begin());

		for (int i = 1; i<n; ++i){
			res.push_back(*s.begin() - res[0] * (k - 1));
			for (int j = 1; j <= k; ++j){
				clean_s(i - 1, j*res[i], k - j);
			}
		}

		for (int i = 0; i < n; ++i){
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
