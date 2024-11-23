#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> divisor;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i * i != n) {
				divisor.push_back(i);
				divisor.push_back(n / i);
			}
			else
				divisor.push_back(i);
		}
	}

	sort(divisor.begin(), divisor.end());
	if (divisor.size() >= k)
		cout << divisor[k - 1];
	else
		cout << 0;

}