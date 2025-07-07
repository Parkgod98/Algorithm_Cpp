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

int main(void) {
	cin >> N;

	priority_queue<pair<long long,long long>,vector<pair<long long, long long>>, greater<>> pq;
	for (int i = 0; i < N; ++i) {
		long long x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				auto it = pq.top();
				pq.pop();
				cout << it.second << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else {
			if (x < 0) {
				pq.push({ -x,x });
			}
			else {
				pq.push({ x,x });
			}
		}
	}
}