#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt;
vector<int> v;
void Solve(int n, int depth) {
	if (n == depth) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		v[depth] = i; // depth행 i열에 배치
		bool can = true;
		for (int j = 0; j < depth; ++j) {
			if (v[depth] == v[j] || (depth - j == abs(v[depth] - v[j]))) { // 같은 열에 있거나, 대각선에 있으면
				can = false;
				break;
			}
		}
		if (can)
			Solve(n, depth + 1);

	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		v = vector<int>(n);
		Solve(n, 0);
		cout << "#" << tc << " " << cnt << "\n";
		cnt = 0;
	}

}