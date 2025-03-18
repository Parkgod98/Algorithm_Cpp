#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		vector<int> v(26,0);
		if(a.size() != b.size()) {
			cout << "Impossible" << "\n";
			continue;
		}
		for(int j = 0; j < a.size(); ++j) {
			v[a[j] - 'a']++;
			v[b[j] - 'a']--;
		}
		bool flag = true;
		for(int j = 0; j < 26; ++j) {
			if(v[j] != 0) {
				cout << "Impossible" << "\n";
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "Possible" << "\n";
	}
}