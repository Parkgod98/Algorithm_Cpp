#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
vector<vector<int>> v(10, vector<int>(10));
int k;
// 0~3 0~3는 파랑
// 0~3 4~5는 옅은 빨강
//  0~3 6~9는 빨강
// 4~5 0~3은 옅노
// 6~9 0~3은 노랑
int dy[2] = { 0,1 }; // 0 : 오른쪽 , 1 : 아래
int dx[2] = { 1,0 };
int score = 0;

bool NotInRange(int y, int x) {
	return (y < 0 || y >= 10 || x < 0 || x >= 10);
}

void GoRight(int t, int y, int x) {
	if (t == 1) {
		int ny = y;
		int nx = x;

		while (!NotInRange(ny, nx) && v[ny][nx] == 0) {
			ny += dy[0];
			nx += dx[0];
		}
		ny -= dy[0];
		nx -= dx[0];
		v[ny][nx] = 1;
	}
	else if (t == 2) {
		int ny = y + dy[0];
		int nx = x + dx[0];

		while (!NotInRange(ny, nx) && v[ny][nx] == 0) {
			ny += dy[0];
			nx += dx[0];
		}
		ny -= dy[0]*2;
		nx -= dx[0]*2;
		v[ny][nx] = 1;
		v[ny + dy[0]][nx + dx[0]] = 1;
	}
	else {
		int ny = y;
		int nx = x;
		int uy = y + dy[1];
		int ux = x + dx[1];

		while (!NotInRange(ny, nx) && v[ny][nx] == 0 && !NotInRange(uy, ux) && v[uy][ux] == 0) {
			ny += dy[0];
			nx += dx[0];
			uy += dy[0];
			ux += dx[0];
		}
		ny -= dy[0];
		nx -= dx[0];
		uy -= dy[0];
		ux -= dx[0];
		v[ny][nx] = 1;
		v[uy][ux] = 1;
	}
}

void GoDown(int t, int y, int x) {
	if (t == 1) {
		int ny = y;
		int nx = x;

		while (!NotInRange(ny, nx) && v[ny][nx] == 0) {
			ny += dy[1];
			nx += dx[1];
		}
		ny -= dy[1];
		nx -= dx[1];
		v[ny][nx] = 1;
	}
	else if (t == 2) {
		int ny = y;
		int nx = x;
		int uy = y + dy[0];
		int ux = x + dx[0];

		while (!NotInRange(ny, nx) && v[ny][nx] == 0 && !NotInRange(uy, ux) && v[uy][ux] == 0) {
			ny += dy[1];
			nx += dx[1];
			uy += dy[1];
			ux += dx[1];
		}
		ny -= dy[1];
		nx -= dx[1];
		uy -= dy[1];
		ux -= dx[1];
		v[ny][nx] = 1;
		v[uy][ux] = 1;
		
	}
	else {
		int ny = y + dy[1];
		int nx = x + dx[1];

		while (!NotInRange(ny, nx) && v[ny][nx] == 0) {
			ny += dy[1];
			nx += dx[1];
		}
		ny -= dy[1] * 2;
		nx -= dx[1] * 2;
		v[ny][nx] = 1;
		v[ny + dy[1]][nx + dx[1]] = 1;
	}
}

bool CanPop(int col) {

	for (int r = 0; r <= 3; ++r) {
		if (v[r][col] != 1) {
			return false;
		}
	}
	return true;
}

void Shift(int start) {
	for (int r = 0; r <= 3; ++r) {
		v[r][start] = 0;
	}
	for (int r = 0; r <= 3; ++r) {
		for (int j = start-1; j >= 4; --j) {
			if (v[r][j] == 1) {
				v[r][j + 1] = v[r][j];
				v[r][j] = 0;
			}
		}
	}
}

void RedPop() {
	for (int c = 9; c >= 6; --c) {
		while (CanPop(c)) {
			++score;
			Shift(c);
		}
	}
}

bool CanYellowPop(int row) {

	for (int c = 0; c <= 3; ++c) {
		if (v[row][c] != 1) {
			return false;
		}
	}
	return true;
}

void YellowShift(int start) {
	for (int c = 0; c <= 3; ++c) {
		v[start][c] = 0;
	}
	for (int c = 0; c <= 3; ++c) {
		for (int j = start - 1; j >= 4; --j) {
			if (v[j][c] == 1) {
				v[j+1][c] = v[j][c];
				v[j][c] = 0;
			}
		}
	}
}
void YellowPop() {
	for (int r = 9; r >= 6; --r) {
		while (CanYellowPop(r)) {
			++score;

			YellowShift(r);
		}
	}
}

void PrintV() {
	cout << "\n";

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int weakRed() {
	int cnt = 0;
	for (int c = 4; c <= 5; ++c) {
		for (int r = 0; r <= 3; ++r) {
			if (v[r][c] == 1) {
				++cnt;
				break;
			}
		}
	}
	return cnt;
}

int weakYellow() {
	int cnt = 0;
	for (int r = 4; r <= 5; ++r) {
		for (int c = 0; c <= 3; ++c) {
			if (v[r][c] == 1) {
				++cnt;
				break;
			}
		}
	}
	return cnt;
}

void RErase(int num) {

	for (int c = 9; c > 9 - num; --c) {
		for (int r = 0; r <= 3; ++r)
			v[r][c] = 0;
	}

	for (int c = 9 - num; c >= 4; --c) {
		for (int r = 0; r <= 3; ++r) {
			if (v[r][c] == 1) {
				v[r][c + num] = v[r][c];
				v[r][c] = 0;
			}
		}
	}
}

void YErase(int num) {
	for (int r = 9; r > 9 - num; --r) {
		for (int c = 0; c <= 3; ++c)
			v[r][c] = 0;
	}

	for (int r = 9 - num; r >= 4; --r) {
		for (int c = 0; c <= 3; ++c) {
			if (v[r][c] == 1) {
				v[r + num][c] = v[r][c];
				v[r][c] = 0;
			}
		}
	}
}

int GetSum() {
	int sum = 0;
	for (int i = 0; i <= 3; ++i) {
		for (int j = 6; j <= 9; ++j) {
			sum += v[i][j];
		}
	}

	for (int i = 6; i <= 9; ++i) {
		for (int j = 0; j <= 3; ++j) {
			sum += v[i][j];
		}
	}

	return sum;
}

int main(void) {
	cin >> k;

	for (int i = 0; i < k; ++i) {
		int t, y, x;
		cin >> t >> y >> x;

		//PrintV();
		GoRight(t, y, x);
		//PrintV();

		GoDown(t, y, x);
		//PrintV();
		RedPop();
		YellowPop();
		//PrintV();


		int rcnt = weakRed();
		int ycnt = weakYellow();
		if (rcnt > 0) {
			RErase(rcnt);
		}
		if (ycnt > 0) {
			YErase(ycnt);
		}
		//PrintV();

		RedPop();
		YellowPop();
		//PrintV();

	}
	cout << score << "\n" << GetSum() << "\n";

}


