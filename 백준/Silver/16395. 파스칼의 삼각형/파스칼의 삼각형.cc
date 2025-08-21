#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, k;

int main() {
	cin >> n >> k;
	n--;
	k--;
	long long res = 1;
	k = min(k, n - k);
	for (int i = 0; i < k; ++i) {
		res *= n;
		n--;
	}
	long long bottom = 1;
	for (int i = 1; i <= k; ++i)
		bottom *= i;

	cout << res / bottom << "\n";
}