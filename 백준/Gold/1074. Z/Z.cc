#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N, r, c;
int cnt;
bool Find = false;
void DFS(int y, int x, int SZ) {
	if (SZ == 1) {
		return;
	}
	int half = SZ / 2;
	int block_sz = half * half;
	if(r < y +half && c < x + half)
		DFS(y, x, SZ / 2);
	else if (r < y + half && c >= x + half) {
		cnt += block_sz;
		DFS(y, x + SZ / 2, SZ / 2);
	}
	else if (r >= y + half && c < x + half) {
		cnt += block_sz*2;
		DFS(y + SZ / 2, x, SZ / 2);
	}
	else {
		cnt += block_sz*3;
		DFS(y + SZ / 2, x + SZ / 2, SZ / 2);
	}

}
int main() {
	cin >> N >> r >> c;

	int sz = pow(2, N);
	DFS(0, 0, sz);
	cout << cnt << "\n";
}
