#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> v(10);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '6')
			v[9]++;
		else
			v[s[i] - '0']++;
	}
	int mx = 0;
	v[9] = ((double)v[9] / 2) + 0.5;
	for(int i = 0; i < v.size(); ++i) {
		if(v[i] > mx)
			mx = v[i];
	}
	cout << mx;
}