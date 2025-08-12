#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define INF 99999999
int N;
vector<vector<int>> v;
struct Human {
	int y, x;
	int can_go_stair_time;
	int mode;
	bool InStairQueue = false;
	bool InStair = false;
	bool Finish = false;
};
struct Stair {
	int y, x;
	int len;
	int arr[20] = { 0 };
};
vector<Human> human;
vector<Stair> stair;
vector<vector<int>> all_cases;
vector<int> tmp;
int human_size;
queue<Human> q1, q2;
int left_man = 0;
// 사용했음
void Input() {
	human.clear();
	stair.clear();
	all_cases.clear();
	q1 = queue<Human>();
	q2 = queue<Human>();

	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				human.push_back({ i,j,0 });
			}
			else if (v[i][j] > 1) {
				stair.push_back({ i,j,v[i][j] });
			}
		}
	}
	human_size = human.size();
} 
// 사용했음
void GetAllCases() {
	if (tmp.size() == human_size) {
		all_cases.push_back(tmp);
		return;
	}
	for (int i = 0; i < 2; ++i) {
		tmp.push_back(i);
		GetAllCases();
		tmp.pop_back();
	}
} 
// 소속팀 까지 정해준다. // 사용했음
void GetPeopleArriveTime(int mode, int idx) {
	if (mode == 0) {
		human[idx].can_go_stair_time = abs(stair[0].y - human[idx].y) + abs(stair[0].x - human[idx].x) + 1;
		human[idx].mode = 0;
		human[idx].InStairQueue = human[idx].InStair = false;
	}
	else {
		human[idx].can_go_stair_time = abs(stair[1].y - human[idx].y) + abs(stair[1].x - human[idx].x) + 1;
		human[idx].mode = 1;
		human[idx].InStairQueue = human[idx].InStair = false;
	}
} 

void EntryStairWaitQueue(int &time) {
	for (int i = 0; i < human_size; ++i) {
		if (human[i].can_go_stair_time == time && !human[i].InStairQueue) {
			if (human[i].mode == 0) {
				q1.push(human[i]);
				human[i].InStairQueue = true;
			}
			else {
				q2.push(human[i]);
				human[i].InStairQueue = true;
			}
		}
	}
}
int CheckInStairMan(int num) {
	int sum = 0;
	for (int i = 0; i < stair[num].len; ++i) {
		sum += stair[num].arr[i];
	}
	return sum;
}
void EntryStair() {
	int limit1 = 3-CheckInStairMan(0);
	int limit2 = 3-CheckInStairMan(1);

	for (int i = 0; i < limit1; ++i) {
		if (!q1.empty()) {
			auto it = q1.front();
			it.InStair = true;
			q1.pop();
			stair[0].arr[0]++;
		}
	}
	/*for (int i = 0; i < stair[0].len; ++i)
		cout << stair[0].arr[i] << " ";
	cout << "\n";*/

	for (int i = 0; i < limit2; ++i) {
		if (!q2.empty()) {
			auto it = q2.front();
			q2.pop();
			it.InStair = true;
			stair[1].arr[0]++;
		}
	}
	/*for (int i = 0; i < stair[1].len; ++i)
		cout << stair[1].arr[i] << " ";
	cout << "\n";*/
}
void ShiftStair() {
	for (int i = stair[0].len - 1; i >= 0; --i) {
		stair[0].arr[i + 1] = stair[0].arr[i];
		if (i + 1 == stair[0].len) {
			left_man += stair[0].arr[i];
		}
	}
	stair[0].arr[0] = 0;
	/*for (int i = 0; i < stair[0].len; ++i)
		cout << stair[0].arr[i] << " ";
	cout << "\n";*/
	for (int i = stair[1].len - 1; i >= 0; --i) {
		stair[1].arr[i + 1] = stair[1].arr[i];
		if (i + 1 == stair[1].len) {
			left_man += stair[1].arr[i];
		}
	}
	stair[1].arr[0] = 0;
	/*for (int i = 0; i < stair[1].len; ++i)
		cout << stair[1].arr[i] << " ";
	cout << "\n";*/
}
bool CheckFinish() {
	if (left_man == human_size)
		return true;
	return false;
}
int StairStart() {
	int time = 0;
	while (1) {
		EntryStairWaitQueue(time); // 현재 시간에 계단 앞에 도착할수 있는넘들 다 계단 대기열에 넣기
		ShiftStair();              // 현재 시간에 계단에서 나갈 수 있는 모든 사람 나가기.
		if (CheckFinish())         // 모든 사람이 나갔으면 Finish
			break;
		EntryStair();          // 현재 시간에 계단 안으로 들어갈 수 있는 모든 사람 들어가기
		++time;
	}

	return time;
}

void Init_Human_Stair() {
	left_man = 0;
	for (int i = 0; i < human_size; ++i) {

	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 20; ++j) {
			stair[i].arr[j] = 0;
		}
	}
}
int Solve() {
	int mn = INF;
	for (auto &ac : all_cases) {

		/* 모든 사람들의 계단 앞까지 도착 시간을 구했음.*/
		/*if (ac[0] == 0 && ac[1] == 0 && ac[2] == 0 && ac[3] == 1 && ac[4] == 1 && ac[5] == 1) {*/
			for (int i = 0; i < human_size; ++i) {
				GetPeopleArriveTime(ac[i], i);
				//cout << human[i].can_go_stair_time << "\n";
			}
			mn = min(mn, StairStart());
		//}
		left_man = 0;
		Init_Human_Stair();
	}

	return mn;

}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		Input();
		GetAllCases();
		cout << "#" << tc << " " << Solve() << "\n";
	}
}