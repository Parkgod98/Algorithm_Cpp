#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int K;
vector<deque<int>> v(4);
void Input() {
	cin >> K;
	for (int i = 0; i < 4; ++i) {
		v[i].clear();
		for (int j = 0; j < 8; ++j) {
			int n;
			cin >> n;
			v[i].push_back(n);
		}
	}
}
// 1은 시계, -1은 반시계
void Rotate(int num, int dir) {
	vector<pair<int, int>> r_list;
	int n_dir = dir;
	for (int i = num + 1; i < 4; ++i) {
		n_dir *= -1;
		if (v[i - 1][2] != v[i][6]) {
			r_list.push_back({ i,n_dir });
		}
		else
			break;
	}
	n_dir = dir;
	for (int i = num - 1; i >= 0; --i) {
		n_dir *= -1;
		if (v[i + 1][6] != v[i][2]) {
			r_list.push_back({ i,n_dir });
		}
		else {
			break;
		}
	}
	r_list.push_back({ num,dir });
	int sz = r_list.size();
	for (int i = 0; i < sz; ++i) {
		int idx = r_list[i].first;
		n_dir = r_list[i].second;

		if (n_dir == 1) {
			v[idx].push_front(v[idx].back());
			v[idx].pop_back();
		}
		else {
			v[idx].push_back(v[idx].front());
			v[idx].pop_front();
		}
	}
	
}

void PrintV() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

int Calculate() {
	int s = 1;
	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		if (v[i][0] == 1) {
			sum += s;
		}
		s *= 2;
	}

	return sum;
}

void GetRotate() {
	for (int i = 0; i < K; ++i) {
		int num, dir;
		cin >> num >> dir;
		Rotate(num - 1, dir);
		//PrintV();
	}
}


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		GetRotate();

		cout << "#" << tc << " " << Calculate() << "\n";
	}

}