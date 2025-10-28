#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

using namespace std;

char star[3100][7000];//세로 N, 가로 2N-1

void Solve(int x, int y, int n) {
	//기본 별찍기
	if (n == 3) {
		star[x][y] = '*';

		star[x + 1][y - 1] = '*';
		star[x + 1][y + 1] = '*';

		for (int i = -2; i <= 2; ++i)
			star[x + 2][y+i] = '*';
	}
	else {
		Solve(x, y, n / 2);
		Solve(x + n / 2, y - n / 2, n / 2);
		Solve(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 3100; ++i) {
		for (int j = 0; j < 7000; ++j)
			star[i][j] = ' ';
	}

	Solve(0, N - 1, N);//x좌표, y좌표, N값

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
	return 0;
}