#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];

		sort(v.begin(), v.end());

		cout << "#" << tc << " ";
		for (int &i : v)
			cout << i << " ";
		cout << "\n";
	}
}