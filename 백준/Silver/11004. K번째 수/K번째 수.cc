#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<long long> v(N);
	for (int i = 0; i < N; ++i) {
		long long k;
		cin >> k;
		v[i] = k;
	}
	sort(v.begin(), v.end());
	cout << v[K-1] << "\n";

}