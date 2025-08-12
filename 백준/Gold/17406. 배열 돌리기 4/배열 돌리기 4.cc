#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> v;
#define INF 999999999
struct Com {
	int r, c, s;
	bool operator<(const Com &other) {
		if (r != other.r) {
			return r < other.r;
		}
		if (c != other.c)
			return c < other.c;
		return s < other.s;
	}
};
vector<Com> com;

void Go() {
	for (int i = 0; i < K; ++i) {
		int r = com[i].r - 1;
		int c = com[i].c - 1;
		int s = com[i].s;

		for (int k = 0; k < s; ++k) {
			deque<int> dq;
			for (int j = c - s + k; j <= c + s - k; ++j) {
				dq.push_back(v[r - s + k][j]);
			}
			dq.pop_back();
			for (int i = r - s + k; i <= r + s - k; ++i) {
				dq.push_back(v[i][c + s - k]);
			}
			dq.pop_back();
			for (int j = c + s - k; j >= c - s + k; --j) {
				dq.push_back(v[r + s - k][j]);
			}
			dq.pop_back();
			for (int i = r + s - k; i >= r - s + k; --i) {
				dq.push_back(v[i][c - s + k]);
			}
			dq.pop_back();
			dq.push_front(dq.back());
			dq.pop_back();

			for (int j = c - s + k; j <= c + s - k; ++j) {
				v[r - s + k][j] = dq.front();
				if (j != c + s - k)
					dq.pop_front();
			}
			for (int i = r - s + k; i <= r + s - k; ++i) {
				v[i][c + s - k] = dq.front();
				if (i != r + s - k)
					dq.pop_front();

			}
			for (int j = c + s - k; j >= c - s + k; --j) {
				v[r + s - k][j] = dq.front();
				if (j != c - s + k)
					dq.pop_front();
			}
			for (int i = r + s - k; i > r - s + k; --i) {
				v[i][c - s + k] = dq.front();
				if (i != r - s + k) {
					dq.pop_front();
				}
			}
		}
	}

}

int Check() {
	int res = INF;
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = 0; j < M; ++j) {
			sum += v[i][j];
		}
		res = min(sum, res);
	}
	return res;
}


int main() {
	cin >> N >> M >> K;
	v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	}
	com = vector<Com>(K);
	for (int i = 0; i < K; ++i) {
		int r, c, s;
		cin >> r >> c >> s;
		com[i] = { r,c,s };
	}
	sort(com.begin(), com.end());

	int mn = INF;
	do {
		vector<vector<int>> tmp = v;
		Go();
		mn = min(Check(), mn);
		v = tmp;
	} while (next_permutation(com.begin(), com.end()));

	cout << mn << "\n";

}