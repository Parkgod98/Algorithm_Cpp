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
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;


	priority_queue<int> pq;
	for (int i = 0; i < N * N; ++i) {
		int n;
		cin >> n;
		n += 1000000001;
		pq.push(-n);

		if (pq.size() > N)
			pq.pop();
	}

	int res = -pq.top() - 1000000001;
	cout << res << "\n";

}  