#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
vector<int> unit(4,0);

struct Node {
	int score;
	int nxt;
	int red = -1;
};

int mx = 0;
vector<int> mmove(10);

vector<Node> v = {
	{0,1},{2,2},{4,3},{6,4},{8,5},{10,6,7},{12,8},{13,25}, {14,9},{16,10},{18,11},{20,12,13},{22,14},{22,30}, {24,15},{26,16},{28,17},{30,18,19},
	{32,20},{28, 31}, {34,21},{36,22},{38,23},{40,24},{0,-1},
	{16,26},{19,27},{25,28},{30,29},{35,23},{24,27},{27,32},{26,27}
};

void DFS(int move_idx, int sum) {
	if (move_idx >= 10) {
		mx = max(mx, sum);
		return;
	}

	int shift = mmove[move_idx];

	for (int i = 0; i < 4; ++i) {

		int cur_location = unit[i];
		int nxt_location = unit[i];
		if (nxt_location == 24) // 이미 도착한 노드는 DFS돌리지 않는다.
			continue;
		if (v[nxt_location].red == -1) { // 다음이 빨간화살표가 없는 노드일떄
			for (int j = 0; j < shift; ++j) {
				nxt_location = v[nxt_location].nxt;
				if (nxt_location == 24)
					break;
			}
			bool Can = true;
			if (nxt_location != 24) {
				for (int j = 0; j < 4; ++j) {
					if (unit[j] == nxt_location) {
						Can = false;
						break;
					}
				}
			}
			if (Can) {
				unit[i] = nxt_location;
				DFS(move_idx + 1, sum + v[nxt_location].score);
				unit[i] = cur_location;
			}
		}
		else { // 다음이 빨간 화살표가 있는 노드일떄
			nxt_location = v[nxt_location].red; // 무조건 여기로 한번 가야하고.
			for (int j = 0; j < shift-1; ++j) {
				nxt_location = v[nxt_location].nxt;
				if (nxt_location == 24)
					break;
			}
			bool Can = true;
			if (nxt_location != 24) {
				for (int j = 0; j < 4; ++j) {
					if (unit[j] == nxt_location) {
						Can = false;
						break;
					}
				}
			}
			if (Can) {
				unit[i] = nxt_location;
				DFS(move_idx + 1, sum + v[nxt_location].score);
				unit[i] = cur_location;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		cin >> mmove[i];
	}


	DFS(0, 0);

	cout << mx << "\n";
	
}