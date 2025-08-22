#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long Reverse(long long n) {
	long long res = 0;
	while (n != 0) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	int N;
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		v[i] = Reverse(v[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		cout << v[i] << "\n";
	}
} 