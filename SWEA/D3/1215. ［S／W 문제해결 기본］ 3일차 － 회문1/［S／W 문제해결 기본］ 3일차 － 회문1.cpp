#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
vector<vector<char>> v;
bool IsPalindrom(string& s) {

	int len = s.size();
	for(int i = 0; i < len / 2; ++i) {
		if(s[i] != s[len - i - 1])
			return false;
	}
	return true;
}
int Find(int k) {
	int res = 0;
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8 - k + 1; ++j) {
			string tmp = "";
			for(int s = j; s < j + k; ++s)
				tmp += v[i][s];
			if(IsPalindrom(tmp))
				++res;
		}
		for(int j = 0; j < 8 - k + 1; ++j) {
			string tmp = "";
			for(int s = j; s < j + k; ++s)
				tmp += v[s][i];
			if(IsPalindrom(tmp))
				++res;
		}
	}
	return res;
}

int main() {

	for(int tc = 1; tc <= 10; ++tc) {
		int n;
		cin >> n;

		v = vector<vector<char>>(8, vector<char>(8));
		for(int i = 0; i < 8; ++i) {
			for(int j = 0; j < 8; ++j) {
				cin >> v[i][j];
			}
		}
		cout << "#" << tc << " " << Find(n) << "\n";

	}
}