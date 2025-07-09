#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> v;
vector<vector<int>> ans;

int main()
{
	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (v[i][k] && v[k][j]) {
					v[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}