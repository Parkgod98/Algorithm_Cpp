#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N;
int cnt[10] = { 0 };
vector<int> v;

map<int, int> mp;

int sz = 0;
int main() {
	cin >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}



	int i, j;
	i = 0;
	j = 0;
	cnt[v[i]]++;

	int sz = 1;
	int mx = 1;
	while (i <= j && j < N) {

		if (sz <= 2) {
			mx = max(mx, j - i + 1);
			++j;
			if (j < N && !cnt[v[j]])
				++sz;
			if(j < N)
				cnt[v[j]]++;
		}
		else {
			cnt[v[i]]--;
			if (!cnt[v[i]])
				--sz;
			++i;
		}
	}

	cout << mx << "\n";

}