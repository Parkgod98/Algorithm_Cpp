#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<long long> v;
int N;
int main() {
	cin >> N;
	v = vector<long long>(N + 1);
	v[1] = 1;
	if(N>=2)
		v[2] = 1;
	for (int i = 3; i <= N; ++i) {
		v[i] = v[i - 2] + v[i - 1];
	}
	cout << v[N] * 4 + v[N - 1] * 2 << "\n";
}