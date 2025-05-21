#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int N, K;
int Garo(vector<vector<int>>& v) {
	int res = 0;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			int cnt = 0;
			for(int s = j; s < j + K && s < N; ++s) {
				if(v[i][s] == 0)
					break;
				++cnt;
			}
			if(cnt == K) {
				bool f1, f2;
				f1 = f2 = false;
				if(j - 1 >= 0) {
					if(v[i][j - 1] == 0)
						f1 = true;
				}
				else
					f1 = true;
				if(j + K < N) {
					if(v[i][j + K] == 0)
						f2 = true;
				}
				else
					f2 = true;

				if(f1 && f2)
					res++;
			}
		}
	}

	return res;
}

int Sero(vector<vector<int>>& v) {
	int res = 0;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			int cnt = 0;
			for(int s = j; s < j + K && s < N; ++s) {
				if(v[s][i] == 0)
					break;
				++cnt;
			}
			if(cnt == K) {
				bool f1, f2;
				f1 = f2 = false;
				if(j - 1 >= 0) {
					if(v[j-1][i] == 0)
						f1 = true;
				}
				else
					f1 = true;
				if(j + K < N) {
					if(v[j+K][i] == 0)
						f2 = true;
				}
				else
					f2 = true;

				if(f1 && f2)
					res++;
			}
		}
	}

	return res;
}



int main() {

	int T;
	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;

		vector<vector<int>> v(N, vector<int>(N, 0));
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j)
				cin >> v[i][j];
		}
		int res = Garo(v) + Sero(v);
		cout << "#" << tc << " " << res << "\n";
	}
}