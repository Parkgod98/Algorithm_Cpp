#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;

	deque<int> dq;

	for (int i = 1; i <= N; ++i)
		dq.push_back(i);

	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();

		if (!dq.empty()) {
			int n = dq.front();
			dq.pop_front();
			dq.push_back(n);
		}
	}
}