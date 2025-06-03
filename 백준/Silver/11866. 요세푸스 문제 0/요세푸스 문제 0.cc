#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; ++i)
		q.push(i);

	vector<int> res;
	while (!q.empty()) {
		int cnt = 0;

		while (!q.empty() && cnt < K -1) {
			int n = q.front();
			q.pop();
			q.push(n);
			cnt++;
		}
		res.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < res.size(); ++i) {
		if (i == res.size() - 1)
			cout << res[i] << ">";
		else
			cout << res[i] << ", ";
	}
}