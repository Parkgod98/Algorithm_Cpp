#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int mx = -2000000000;
int mn = 2000000000;
vector<int> op,v;
int N;
void Solve(int res, int idx) {
	if (idx == N) {
		mn = min(mn, res);
		mx = max(mx, res);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) 
				Solve(res + v[idx], idx + 1);
			else if (i == 1) 
				Solve(res - v[idx], idx + 1);
			else if (i == 2) 
				Solve(res*v[idx], idx + 1);
			else
				Solve(res / v[idx], idx + 1);
			op[i]++;
		}
	}
}
int main(void) {
	cin >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	op = vector<int>(4);
	cin >> op[0] >> op[1] >> op[2] >> op[3];
	Solve(v[0], 1);
	cout << mx << "\n" << mn << "\n";
}
