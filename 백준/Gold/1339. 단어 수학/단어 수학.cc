#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
int N;
map<char, int> mp,mp2;
vector<string> v;


bool compare(pair<char, int> &a, pair<char, int> &b){
	return a.second > b.second;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		int start = pow(10, s.size()-1);
		v.push_back(s);
		for (int j = 0; j < s.size(); ++j) {
			mp[s[j]] += start;
			start /= 10;
		}
	}

	vector<pair<char, int>> alpha;
	for (auto &it : mp)
		alpha.push_back({ it.first,it.second });
	sort(alpha.begin(), alpha.end(),compare);

	int num = 9;
	for (auto &it : alpha) {
		mp2[it.first] = num;
		num--;
	}

	int sum = 0;

	for (int i = 0; i < N; ++i) {
		
		for (char &c : v[i]) {
			c = mp2[c] +'0';
		}
		sum += stoi(v[i]);
	}

	cout << sum << "\n";
}
