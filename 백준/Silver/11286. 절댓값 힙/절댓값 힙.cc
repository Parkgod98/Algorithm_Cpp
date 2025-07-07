#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < N; ++i) {
		long long x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				auto it = pq.top();
				pq.pop();
				cout << it << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else {
				pq.push(x);
		}
	}
}