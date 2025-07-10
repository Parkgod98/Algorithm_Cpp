#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define N 19
int arr[N][N] = { 0 };

int Garo(int y, int x) {
	int cur = arr[y][x];
	for (int i = x; i < x + 5; ++i) {
		if (cur != arr[y][i]) {
			return 0;
		}
	}
	if (x - 1 >= 0 && arr[y][x - 1] == cur)
		return 0;
	if (x + 5 < N && arr[y][x + 5] == cur)
		return 0;
	return cur;
}

int Sero(int y, int x) {
	int cur = arr[y][x];
	for (int i = y; i < y + 5; ++i) {
		if (cur != arr[i][x]) {
			return 0;
		}
	}
	if (y - 1 >= 0 && arr[y-1][x] == cur)
		return 0;
	if (y + 5 < N && arr[y + 5][x] == cur)
		return 0;
	return cur;
}

int Diagonal(int y, int x) {
	int cur = arr[y][x];
	for (int i = 0; i < 5; ++i) {
		if (cur != arr[i + y][x + i]) {
			return 0;
		}
	}
	if (y - 1 >= 0 && x - 1 >= 0 && arr[y - 1][x - 1] == cur)
		return 0;
	if (y + 5 < N && x + 5 < N && arr[y + 5][x + 5] == cur)
		return 0;
	return cur;
}

int Diagonal2(int y, int x) {
	int cur = arr[y][x];
	for (int i = 0; i < 5; ++i) {
		if (cur != arr[i + y][x - i])
			return 0;
	}
	if (y - 1 >= 0 && x + 1 < N && arr[y - 1][x + 1] == cur)
		return 0;
	if (y + 5 < N && x - 5 < N && arr[y + 5][x - 5] == cur)
		return 0;
	return cur;
}

int main()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 4; ++j) {
			if (arr[i][j] == 0)
				continue;
			int res = Garo(i, j);
			if (res) {
				cout << res << "\n";
				cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < N - 4; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 0)
				continue;
			int res = Sero(i, j);
			if (res) {
				cout << res << "\n";
				cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < N - 4; ++i) {
		for (int j = 0; j < N - 4; ++j) {
			if (arr[i][j] == 0)
				continue;
			int res = Diagonal(i, j);
			if (res) {
				cout << res << "\n";
				cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < N-4; ++i) {
		for (int j = N - 1; j >= 4; --j) {
			if (arr[i][j] == 0)
				continue;
			int res = Diagonal2(i, j);
			if (res) {
				cout << res << "\n";
				cout << i + 5 << " " << (j + 1)-4 << "\n";
				return 0;
			}

		}
	}

	cout << 0 << "\n";
}