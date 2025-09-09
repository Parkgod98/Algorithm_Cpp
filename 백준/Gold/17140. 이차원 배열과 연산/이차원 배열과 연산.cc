#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int r, c, k;
vector<vector<int>> v(3,vector<int>(3));
vector<int> cnt(101);
void PrintV() {
	cout << "\n";

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}
void LeftRotate() {

	int r_sz = v.size();
	int c_sz = v[0].size();
	vector<vector<int>> tmp(c_sz, vector<int>(r_sz));


	for (int i = 0; i < c_sz; ++i) {
		for (int j = 0; j < r_sz; ++j) {
			tmp[i][j] = v[j][i];
		}
	}
	v = tmp;

	return;
}

void RightRotate() {
	int r_sz = v.size();
	int c_sz = v[0].size();
	vector<vector<int>> tmp(c_sz, vector<int>(r_sz));


	for (int i = 0; i < c_sz; ++i) {
		for (int j = 0; j < r_sz; ++j) {
			tmp[i][j] = v[j][i];
		}
	}
	v = tmp;

	return;
}

bool cmp(int a, int b) {
	if (cnt[a] != cnt[b])
		return cnt[a] < cnt[b];
	return a < b;
}

void Simulate() {

	int r_sz = v.size();
	int c_sz = v[0].size();

	if (r_sz >= c_sz) {
		int mx_sz = 0;
		for (int i = 0; i < r_sz; ++i) {
			vector<int> &tmp = v[i];
			cnt = vector<int>(101);
			cnt[0] = 9999999;
			for (int j = 0; j < c_sz; ++j) {
				if (tmp[j] != 0)
					cnt[tmp[j]]++;
			}
			sort(tmp.begin(), tmp.end(), cmp);
			vector<int> n_tmp;
			vector<int> visited(101);
			int remain = 0;
			for (int j = 0; j < c_sz; ++j) {
				if (n_tmp.size() >= 100)
					break;
				if (tmp[j] != 0 && !visited[tmp[j]]) {
					n_tmp.push_back(tmp[j]);
					n_tmp.push_back(cnt[tmp[j]]);
					visited[tmp[j]] = 1;
				}
			}
			tmp = n_tmp;
			mx_sz = max(mx_sz, (int)n_tmp.size());
		}

		int r_sz = v.size();
		for (int i = 0; i < r_sz; ++i) {
			vector<int> &tmp = v[i];
			while (tmp.size() < mx_sz && tmp.size() < 100) {
				tmp.push_back(0);
				tmp.push_back(0);
			}
		}
	}
	else {
		LeftRotate();
		int mx_sz = 0;
		for (int i = 0; i < c_sz; ++i) {
			vector<int> &tmp = v[i];
			cnt = vector<int>(101);
			cnt[0] = 9999999;
			for (int j = 0; j < r_sz; ++j) {
				if (tmp[j] != 0)
					cnt[tmp[j]]++;
			}
			sort(tmp.begin(), tmp.end(), cmp);
			vector<int> n_tmp;
			vector<int> visited(101);
			for (int j = 0; j < r_sz; ++j) {
				if (n_tmp.size() >= 100)
					break;
				if (tmp[j] != 0 && !visited[tmp[j]]) {
					n_tmp.push_back(tmp[j]);
					n_tmp.push_back(cnt[tmp[j]]);
					visited[tmp[j]] = 1;
				}
			}
			tmp = n_tmp;
			mx_sz = max(mx_sz, (int)n_tmp.size());
		}

		int r_sz = v.size();
		for (int i = 0; i < r_sz; ++i) {
			vector<int> &tmp = v[i];
			while (tmp.size() < mx_sz && tmp.size() < 100) {
				tmp.push_back(0);
				tmp.push_back(0);
			}
		}
		RightRotate();
	}

	//PrintV();
}

void CutOff() {

	
}

int main() {
	cin >> r >> c >> k;
	r--;
	c--;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cin >> v[i][j];
	}

	if (r < v.size() && c < v[0].size() && v[r][c] == k) {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 1; i <= 100; ++i) {
		Simulate();
		if (r < v.size() && c < v[0].size() && v[r][c] == k) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}