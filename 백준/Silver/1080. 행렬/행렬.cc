#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> A, B;

int main(){
	cin >> N >> M;
	A = B = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
			A[i][j] = s[j]-'0';
	}
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
			B[i][j] = s[j]-'0';
	}

	int cnt = 0;
	for (int i = 0; i < N-2; ++i) {
		for (int j = 0; j < M-2; ++j) {
			if (A[i][j] != B[i][j]) {
				++cnt;
				for (int k = i; k < i + 3; ++k) {
					for (int p = j; p < j + 3; ++p) {
						A[k][p] = !A[k][p];
					}
				}
			}
		}
	}

	for(int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != B[i][j]) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	cout << cnt << "\n";
}