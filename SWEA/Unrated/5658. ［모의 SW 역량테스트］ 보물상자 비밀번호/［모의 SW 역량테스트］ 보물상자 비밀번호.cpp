#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N, K;
string s;

long long Cut(int start, int end) {

	long long w = 1;
	long long sum = 0;
	for (int i = end-1; i >= start; --i) {
		if (s[i] >= '0' && s[i] <= '9')
			sum += (s[i] - '0')*w;
		else {
			long long num = s[i] - 'A' + 10;
			sum += (num * w);
		}
		w *= 16;
	}
	//cout << sum << "\n";
	return sum;
}

void Rotate() {
	char front = s.back();
	s.pop_back();
	s = front + s;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		cin >> s;

		set<long long> st;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; j += (N/4)) {
				st.insert(Cut(j, j + N / 4));
			}
			Rotate();
		}

		vector<long long> ans;
		for (int n : st)
			ans.push_back(n);
		sort(ans.begin(), ans.end(),greater<long long>());
		cout << "#" << tc << " " << ans[K - 1] << "\n";
	}
}