#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());
	for (int &n : v) {
		cout << n << "\n";
	}
}
