#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	unordered_map<int, int> mp;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mp[n]++;
	}

	int M;
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		int n;
		cin >> n;
		cout << mp[n] << " ";
	}
}