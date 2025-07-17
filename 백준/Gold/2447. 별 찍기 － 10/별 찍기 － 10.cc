#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<char>> v;

void Solve(int y, int x, int SZ) {
	if (SZ == 1) {
		v[y][x] = '*';
		return;
	}

	int weight = SZ / 3;
	for (int dy = 0; dy < 3; ++dy) {
		for (int dx = 0; dx < 3; ++dx) {
			if (dy == 1 && dx == 1)
				continue;
			Solve(y + dy * weight, x + dx * weight, SZ / 3);
		}
	}
}

int main() {
	cin >> N;

	v = vector<vector<char>>(N, vector<char>(N,' '));

	Solve(0, 0, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << v[i][j];
		cout << "\n";
	}

}
