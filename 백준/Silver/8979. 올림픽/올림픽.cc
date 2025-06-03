#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <set>
using namespace std;

struct Nation {
	int gold, silver, bronze;
};

int main() {
	int N, K;
	cin >> N >> K;

	vector<Nation> v(N);
	for (int i = 0; i < N; ++i) {
		int n, g, s, b;
		cin >> n >> g >> s >> b;
		v[n - 1] = { g,s,b };
	}

	int rank = 1;
	for (int i = 0; i < N; ++i) {
		if (i != K - 1) {
			if (v[K - 1].gold < v[i].gold) {
				rank++;
			}
			else if (v[K - 1].gold > v[i].gold)
				continue;
			else if (v[K - 1].silver < v[i].silver) {
				rank++;
			}
			else if (v[K - 1].silver > v[i].silver)
				continue;
			else if (v[K - 1].bronze < v[i].bronze) {
				rank++;
			}
			else if (v[K - 1].bronze > v[i].bronze)
				continue;
		}
	}
	cout << rank << "\n";
}