#include <iostream>
#include <vector>
using namespace std;
int N;

int main() {
	cin >> N;


	int mx_idx = 0;
	int mx = 0;
	vector<int> v(1001);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
		if (v[a] > mx) {
			mx = v[a];
			mx_idx = a;
		}
	}

	int sum = 0;
	int cur_mx = 0;
	for (int i = 0; i < mx_idx; ++i) {
		if (v[i] > cur_mx) {
			cur_mx = v[i];
		}
		sum += cur_mx;
	}
	cur_mx = 0;
	for (int i = 1000; i >= mx_idx; --i) {
		if (v[i] > cur_mx) {
			cur_mx = v[i];
		}
		sum += cur_mx;
	}

	cout << sum << "\n";
}