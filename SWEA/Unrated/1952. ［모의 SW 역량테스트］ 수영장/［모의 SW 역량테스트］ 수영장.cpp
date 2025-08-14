#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
#define INF 999999999
int T;
vector<int> v(13);
vector<int> num(5);
vector<int> minimal_3_month(13);
int mn = INF;

void DFS(int idx, int money) {
	if (idx >= 13) {
		mn = min(money, mn);
		return;
	}
	if (v[idx] == 0) {
		DFS(idx + 1, money);
	}
	else {
		DFS(idx + 1, money + v[idx] * num[1]);
		DFS(idx + 1, money + num[2]);
		DFS(idx + 3, money + num[3]);
		DFS(idx + 12, money + num[4]);
	}
}
int main() {
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int year = 0;
		for (int i = 1; i <= 4; ++i)
			cin >> num[i];
		for (int i = 1; i <= 12; ++i) {
			cin >> v[i];
			year += v[i];
		}

		DFS(1, 0);
		cout << "#" << tc << " " << mn << "\n";
		mn = INF;
	}
}


