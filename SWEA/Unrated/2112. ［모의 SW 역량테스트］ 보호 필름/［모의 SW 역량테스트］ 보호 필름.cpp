#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
int N, M, K;
vector<vector<int>> v;
vector<int> tmp;
vector<vector<int>> medicine_cases;
bool Finish = false;

void PrintV() {
	cout << "\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void Input() {
	medicine_cases.clear();
	Finish = false;
	cin >> N >> M >> K;
	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}
}

void Comb(int idx, int k) {
	if (tmp.size() == k) {
		medicine_cases.push_back(tmp);
		return;
	}

	for (int i = idx; i < N; ++i) {
		tmp.push_back(i);
		Comb(i + 1, k);
		tmp.pop_back();
	}
}

void GetAllCases() {
	for (int i = 1; i <= N; ++i) {
		Comb(0, i);
	}
}

bool ColumnCheck(int c) {
	int cnt = 1;
	for (int i = 1; i < N; ++i) {
		int cur = v[i][c];
		if (cur == v[i - 1][c]) {
			++cnt;
		}
		else
			cnt = 1;
		if (cnt >= K)
			return true;
	}
	return false;
}

void InjectMedicine(int r, int mode) {

	for (int i = 0; i < M; ++i) {
		v[r][i] = mode;
	}
}

bool FullCheck() {
	for (int i = 0; i < M; ++i) {
		if (!ColumnCheck(i)) {
			return false;
		}
	}
	return true;
}

void Comb2(int idx,int tar, int k) {
	if (idx == k) {
		//PrintV();
		if (FullCheck())
			Finish = true;
		return;
	}
	for (int i = 0; i < 2; ++i) {
		vector<int> tmp = v[medicine_cases[tar][idx]];
		InjectMedicine(medicine_cases[tar][idx],i);
		//PrintV();
		Comb2(idx + 1, tar, k);
		v[medicine_cases[tar][idx]] = tmp;
		//PrintV();
	}
}

int Simulate() {
	if (FullCheck()) {
		return 0;
	}

	int sz = medicine_cases.size();
	for (int i = 0; i < sz; ++i) {
		Comb2(0, i, medicine_cases[i].size());
		if (Finish)
			return medicine_cases[i].size();
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		GetAllCases();
		int res = Simulate();

		cout << "#" << tc << " " << res << "\n";
	}
}


