#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<bool> v(N+1,true);
	v[0] = v[1] = false;

	for (int i = 2; i*i <= N; ++i) {
		if (v[i]) {
			for (int j = i*2; j <= N; j+=i) {
				v[j] = false;
			}
		}
	}

	for (int i = M; i <= N; ++i) {
		if (v[i])
			cout << i << "\n";
	}

}