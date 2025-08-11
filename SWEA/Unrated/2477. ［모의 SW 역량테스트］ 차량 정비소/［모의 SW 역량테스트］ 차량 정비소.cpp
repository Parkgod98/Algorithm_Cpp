#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K, A, B;
int sum = 0;
vector<int> reception, repair;
struct man {
	int num;
	int time;

	bool operator<(const man &other) const {
		if(time != other.time)
			return time < other.time;
		return num < other.num;
	}
	bool operator>(const man& other) const {
		return other < *this;
	}
};
priority_queue<man, vector<man>, greater<man>> pq;
queue<int> q;
vector<man> human;
vector<int> finished; // 언제 여기서 사라지는지
vector<int> who;     // 누가 들어가있는지.
vector<int> finished2;
vector<int> who2;
vector<int> res;

int Go(int &time, int idx) { // 해당 시간에 대기열에 들어가야 될사람들 전부 push하는 함수.
	int res = idx;
	bool Flag = false;
	for (int i = idx; i <= K; ++i) {
		if (human[i].time == time) {
			pq.push(human[i]);
			res = i;
			Flag = true;
		}
		else
			break;
	}
	if (Flag)
		return res + 1;
	return idx;
}

void Receipt(int time) {
	for (int i = 1; i <= N; ++i) {
		if (pq.empty())
			break;
		if (!finished[i] && !pq.empty()) {
			auto it = pq.top();
			pq.pop();
			finished[i] = time + reception[i]; // 현재시간 + 경과시간 => 내가 사라질 시간.
			who[i] = it.num;					// i번째 창구 이용하는 사람.
			if (i == A) {
				res[it.num]++;
			}
		}
	}
}

void ReceiptOut(int time) {
	for (int i = 1; i <= N; ++i) {
		if (finished[i] >= 1 && finished[i] == time) {
			q.push(who[i]);
			who[i] = 0;
			finished[i] = 0;
		}
	}
}

void RepairIn(int time) {
	for (int i = 1; i <= M; ++i) {
		if (q.empty())
			break;
		if (!finished2[i] && !q.empty()) {
			auto it = q.front();
			q.pop();
			finished2[i] = time + repair[i];
			who2[i] = it;
			if (i == B)
				res[it]++;
		}
	}
}

void RepairOut(int time) {
	for (int i = 1; i <= M; ++i) {
		if (finished2[i] >= 1 && finished2[i] == time) {
			finished2[i] = who2[i] = 0;
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K >> A >> B;
		reception = vector<int>(N + 1);
		finished = who = vector<int>(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> reception[i];

		repair = finished2 = who2 = vector<int>(M + 1);
		for (int i = 1; i <= M; ++i)
			cin >> repair[i];

		human = vector<man>(K + 1);
		res = vector<int>(K + 1);
		for (int i = 1; i <= K; ++i) {
			int tk;
			cin >> tk;
			human[i] = { i,tk };
		}
		sort(human.begin(), human.end());

		int time = 0;
		int idx = 1;
		while (time <= 3000) {
			idx = Go(time, idx);
			ReceiptOut(time);
			Receipt(time);
			RepairOut(time);
			RepairIn(time);
			++time;
		}

		for (int i = 1; i <= K; ++i) {
			if (res[i] == 2)
				sum += i;
		}
		if (sum == 0)
			sum = -1;
		cout << "#" << tc << " " << sum << "\n";
		sum = 0;
	}
}
