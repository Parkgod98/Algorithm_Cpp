#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n, m, q;
vector<deque<int>> circle;

void PrintC() {

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << circle[i][j] << " ";
		}
		cout << "\n";
	}
}

void UnitRotate(int x, int dir, int k) {

	if (dir == 0) {
		for (int i = 0; i < k; ++i) {
			int back = circle[x].back();
			circle[x].pop_back();
			circle[x].push_front(back);
		}
	}
	else {
		for (int i = 0; i < k; ++i) {
			int front = circle[x].front();
			circle[x].pop_front();
			circle[x].push_back(front);
		}
	}
}

void Rotate(int x, int dir, int k) {
	// x의 배수가 되는 원판을 싹다 회전
	for (int i = 1; i*x <= n; ++i) {
		UnitRotate(i*x, dir,k);
	}
}
struct Point {
	int i, j;

	bool operator <(const Point &other) const {
		if (i != other.i)
			return i < other.i;
		return j < other.j;
	}
};
bool Delete() {
	set<Point> remove_list;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) { // 동일 써클 내 인접 찾기
			if (circle[i][j] == 0)
				continue;
			if (j == 0) {
				if (circle[i][j] == circle[i][m-1]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,m - 1 });
				}
				if (circle[i][j] == circle[i][j + 1]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,j + 1 });
				}
			}
			else if (j == m - 1) {
				if (circle[i][j] == circle[i][j - 1]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,j - 1 });
				}
				if (circle[i][j] == circle[i][0]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,0 });
				}
			}
			else {
				if (circle[i][j] == circle[i][j - 1]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,j - 1 });
				}
				if (circle[i][j] == circle[i][j + 1]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i,j + 1 });
				}
			}
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (circle[i][j] == 0)
				continue;
			if (i == 1) {
				if (circle[i][j] == circle[i+1][j]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i+1,j });
				}
			}
			else if (i == n) {
				if (circle[i][j] == circle[i-1][j]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i-1,j});
				}
			}
			else {
				if (circle[i][j] == circle[i+1][j]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i+1,j });
				}
				if (circle[i][j] == circle[i-1][j]) {
					remove_list.insert({ i,j });
					remove_list.insert({ i-1,j });
				}
			}
		}
	}

	if (remove_list.size() == 0)
		return false;

	for (auto it : remove_list) {
		int y = it.i;
		int x = it.j;
		circle[y][x] = 0;
	}
	return true;
}

void normalize() {

	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (circle[i][j] == 0)
				continue;
			++cnt;
			sum += circle[i][j];
		}
	}

	if (cnt == 0)
		return;
	double avg = sum / (double)cnt;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (circle[i][j] == 0)
				continue;

			if (circle[i][j] > avg)
				--circle[i][j];
			else if (circle[i][j] < avg)
				++circle[i][j];
		}
	}
}

int Sum() {
	int sum = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j)
			sum += circle[i][j];
	}
	return sum;
}

int main(void) {
	cin >> n >> m >> q;
	circle = vector<deque<int>>(n + 1);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r;
			cin >> r;
			circle[i].push_back(r);
		}
	}


	for (int i = 0; i < q; ++i) {
		int x, d, k;
		cin >> x >> d >> k;
		Rotate(x, d, k);
		//PrintC();

		if (!Delete()) {
			//PrintC();

			normalize();
			//PrintC();
		}
		//PrintC();

	}

	cout << Sum() << "\n";
}