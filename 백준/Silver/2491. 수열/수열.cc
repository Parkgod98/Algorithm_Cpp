#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int main() {
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int shortest_len = 1;
	int longest_len = 1;
	int start = v[0];

	int s_cur, l_cur;
	s_cur = l_cur = 1;
	for (int i = 1; i < N; ++i) {
		if (v[i] >= v[i - 1]) {
			l_cur++;
			longest_len = max(longest_len, l_cur);
		}
		else
			l_cur = 1;
		if (v[i] <= v[i - 1]) {
			s_cur++;
			shortest_len = max(shortest_len, s_cur);
		}
		else
			s_cur = 1;
	}

	cout << max(shortest_len,longest_len) << "\n";
}