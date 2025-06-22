#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> st;
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		q.push(n);
	}

	int target = 1;

	bool success = true;
	while (target <= N) {
		if (!q.empty() && q.front() == target) {
			q.pop();
			target++;
		}
		else if (!st.empty() && st.top() == target) {
			st.pop();
			target++;
		}
		else {
			if (!q.empty()) {
				st.push(q.front());
				q.pop();
			}
			else {
				success = false;
				break;
			}
		}
	}
	if (success)
		cout << "Nice" << "\n";
	else
		cout << "Sad" << "\n";
	
}  