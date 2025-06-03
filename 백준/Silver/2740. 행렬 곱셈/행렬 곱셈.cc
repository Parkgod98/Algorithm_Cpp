#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
int N, M, K;

vector<vector<int>> GetArr(vector<vector<int>> &arr1, vector<vector<int>> &arr2) {
	vector<vector<int>> res(N, vector<int>(K));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			int sum = 0;

			for (int k = 0; k < M; ++k) {
				sum += arr1[i][k] * arr2[k][j];
			}
			res[i][j] = sum;
		}
	}
	return res;
}

int main() {
	cin >> N >> M;

	vector<vector<int>> arr1(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> arr1[i][j];
	}

	cin >> M >> K;
	
	vector<vector<int>> arr2(M, vector<int>(K));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j)
			cin >> arr2[i][j];
	}

	vector<vector<int>> res = GetArr(arr1, arr2);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}