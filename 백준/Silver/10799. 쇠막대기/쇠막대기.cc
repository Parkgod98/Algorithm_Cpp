#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
string s;

int main() {
	cin >> s;

	vector<pair<int, int>> laser;
	set<int> pass_idx;
	for (int i = 0; i < s.size()-1; ++i) {
		if (s[i] == '(' && s[i + 1] == ')') {
			laser.push_back({ i,i + 1 });
			pass_idx.insert(i);
			pass_idx.insert(i + 1);
		}
	}

	//for (auto &it : laser) {
	//	cout << it.first << " " << it.second << "\n";
	//}
	//cout << "\n";


	vector<pair<int, int>> iron;
	stack<int> st;
	int i = 0;
	while (i < s.size()) {
		if (pass_idx.find(i) != pass_idx.end()) {
			i++;
			continue;
		}
		else {
			if (s[i] == '(') {
				st.push(i);
				i++;
			}
			else {
				iron.push_back({ st.top(),i });
				st.pop();
				i++;
			}
		}
	}

	//for (auto &it : iron) {
	//	cout << it.first << " " << it.second << "\n";
	//}
	//cout << "\n";

	int cnt = 0;

	for (int i = 0; i < iron.size(); ++i) {
		int i_s, i_e;
		i_s = iron[i].first;
		i_e = iron[i].second;

		int pipe = 0;
		for (int j = 0; j < laser.size(); ++j) {
			if (i_s < laser[j].first && laser[j].second < i_e)
				pipe++;
		}
		cnt += (pipe + 1);
	}
	cout << cnt << "\n";
}