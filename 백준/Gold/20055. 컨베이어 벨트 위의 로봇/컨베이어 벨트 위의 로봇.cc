#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N, K;
vector<pair<int, bool>> v;

int CountZero(vector<pair<int,bool>> &v) {
	int cnt = 0;
	for (int i = 0; i < 2 * N; ++i) {
		if (v[i].first == 0)
			++cnt;
	}
	return cnt;
}

void ResolveBelt() {
	pair<int, bool> tmp = v[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; --i) {
		if (i - 1 == N - 2 && i == N - 1) {
			v[i] = v[i - 1];
			v[i].second = false;
		}
		else
			v[i] = v[i - 1];
	}
	v[0] = tmp;
}
// 0 -> 올리는 칸, N-1 내리는 칸
void ShiftRobot() {
	for (int i = N - 2; i >= 0; --i) {
		if (v[i].second == true) { // 로봇이 있는데
			if ((i + 1) == (N - 1)) { // 다음칸이 내리는 칸 일때
				if (v[i + 1].first >= 1) { // 내구도가 남아있다면
					v[i + 1].first--;
					v[i].second = false;
				}
			}
			else {//다음 칸이 내리는 칸이 아닐때.
				if (v[i + 1].first >= 1 && v[i + 1].second == false) { // 내구도가 남아있고, 다음칸에 로봇이 없다면.
					v[i].second = false;
					v[i + 1].second = true;
					v[i + 1].first--;
				}
			}
		}
	}
}

void UpRobot() {
	if (v[0].first >= 1 && v[0].second == false) {
		v[0].second = true;
		v[0].first--;
	}
}

int main() {
	cin >> N >> K;

	v = vector<pair<int, bool>>(2 * N);
	for (int i = 0; i < 2*N; ++i) {
		int n;
		cin >> n;
		v[i] = { n,false };
	}

	int cnt = 0;
	while (CountZero(v) < K) {
		ResolveBelt();
		ShiftRobot();
		UpRobot();
		++cnt;
	}
	cout << cnt << "\n";

}