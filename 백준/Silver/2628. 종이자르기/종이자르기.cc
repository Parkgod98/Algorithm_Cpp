#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;

int main() {
	cin >> N >> M;

	int num;
	cin >> num;

	vector<int> g, s;
	for (int i = 0; i < num; ++i) {
		int sign,k;
		cin >> sign >> k;

		if (sign)
			s.push_back(k);
		else 
			g.push_back(k);
	}
	g.push_back(0);
	g.push_back(M);
	s.push_back(0);
	s.push_back(N);
	sort(s.begin(), s.end());
	sort(g.begin(), g.end());

	int mx_g, mx_s;
	mx_g = mx_s = 0;
	for (int i = 1; i < g.size(); ++i) {
		mx_g = max(g[i] - g[i - 1], mx_g);
	}
	for (int i = 1; i < s.size(); ++i)
		mx_s = max(s[i] - s[i - 1], mx_s);

	cout << mx_g * mx_s << "\n";
}