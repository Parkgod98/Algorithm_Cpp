#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int T;
int N, M;
vector<vector<int>> v;
int main(){
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		v = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> v[i][j];
			}
		}

		int mx = 0;
		for (int i = 0; i < N - M + 1; ++i) {
			for (int j = 0; j < N - M + 1; ++j) {

				int sum = 0;
				for (int s = i; s < i + M; ++s) {
					for (int e = j; e < j + M; ++e) {
						sum += v[s][e];
					}
				}
				mx = max(sum, mx);
			}
		}

		cout << "#" << tc << " " << mx << "\n";
	}


}
