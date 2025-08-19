#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> v;
int main() {
	cin >> N >> L;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		if (v[i] <= L)
			++L;
	}

	cout << L << "\n";
}