#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int K;
vector<int> v;
int main() {
	cin >> K;

	for (int i = 1; i <= K; ++i) {
		cout << "Class " << i << "\n";
		int N;
		cin >> N;
		v = vector<int>(N);
		int mn = 101;
		int mx = -1;
		for (int j = 0; j < N; ++j) {
			cin >> v[j];
			mn = min(mn, v[j]);
			mx = max(mx, v[j]);
		}
		sort(v.begin(), v.end());
		int mx_gap = -1;
		for (int i = 1; i < N; ++i) {
			if (v[i] - v[i - 1] > mx_gap)
				mx_gap = v[i] - v[i - 1];
		}

		cout << "Max " << mx << ", " << "Min " << mn << ", " << "Largest gap " << mx_gap << "\n";
		
	}
}