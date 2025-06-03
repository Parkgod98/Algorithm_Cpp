#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = N-1; i >= 0; --i) {
		cin >> v[i];
	}

	int cnt = 0;
	while (1) {
		int idx = max_element(v.begin(), v.end()) - v.begin();
		if (idx == N-1)
			break;
		else {
			v[idx]--;
			v[N-1]++;
			++cnt;
		}
	}
	cout << cnt << "\n";

}