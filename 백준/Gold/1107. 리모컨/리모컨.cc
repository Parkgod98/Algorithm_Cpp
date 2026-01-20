#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N, M;
vector<int> defect(10);

bool Check(int n) {
	if (n == 0) {
		if (defect[n])
			return false;
		return true;
	}

	while (n != 0) {
		int k = n % 10;
		if (defect[k]) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int k;
		cin >> k;
		defect[k] = 1;
	}

	int direct = abs(N - 100);

	int mn = 1;
	int mx = 1;
	bool Find1, Find2;
	Find1 = Find2 = false;
	for (int i = N; i >= 0; --i) {
		if (Check(i)) {
			mn = i;
			Find1 = true;
			break;
		}
	}
	int mn_cnt;
	if (Find1)
		mn_cnt = abs(N - mn) + to_string(mn).size();
	else
		mn_cnt = 10000000;

	for (int i = N; i <= N+mn_cnt; ++i) {
		if (mn_cnt < mx) {
			break;
		}
		if (Check(i)) {
			mx = i;
			Find2 = true;
			break;
		}
	}
	int mx_cnt;
	if (Find2)
		mx_cnt = abs(mx - N) + to_string(mx).size();
	else
		mx_cnt = 10000000;

	cout << min(direct, min(mn_cnt, mx_cnt)) << "\n";

}