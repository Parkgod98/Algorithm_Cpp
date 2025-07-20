#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int K;
vector<deque<int>> v;

void PrintV(vector<deque<int>> &v) {
	cout << "\n";

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j)
			cout << v[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

}
void Check(int num) {
	int prev = num - 1;
	int nxt = num + 1;

	if (prev >= 0) {

	}
}

void Rotate(deque<int> &dq, int dir) {
	if (dir == 1) {
		int top = dq.back();
		dq.pop_back();
		dq.push_front(top);
	}
	else {
		int back = dq.front();
		dq.pop_front();
		dq.push_back(back);
	}
}

int main(void) {
	v = vector<deque<int>>(4);
	for (int i = 0; i < 4; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; ++j)
			v[i].push_back(s[j]-'0');
		for (int j = 0; j < 2; ++j) {
			v[i].push_front(v[i].back());
			v[i].pop_back();
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int num, dir;
		cin >> num >> dir;
		--num;

		vector<int> check(4);
		check[num] = dir;
		int tmp = dir;
		for (int start = num; start > 0; --start) {
			if (v[start][0] == v[start - 1][4])
				break;
			else {
				check[start - 1] = -tmp;
				tmp *= -1;
			}
		}
		tmp = dir;
		for (int start = num; start < 3; ++start) {
			if (v[start][4] == v[start + 1][0])
				break;
			else {
				check[start + 1] = -tmp;
				tmp *= -1;
			}
		}

		for (int j = 0; j < 4; ++j) {
			if (check[j] != 0) {
				Rotate(v[j], check[j]);
			}
		}
	}

	int sum = 0;
	int weight = 1;
	for (int i = 0; i < 4; ++i) {
		if (v[i][2] == 1) {
			sum += weight;
		}
		weight *= 2;
	}

	cout << sum << "\n";
}
