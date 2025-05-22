#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<char>> v;
int mx = 1;

bool IsPalindrome(string &s) {
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

void Find() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			string t = "";
			for (int s = j; s < 100; ++s) {
				t += v[i][s];
				if (t.size() > mx && IsPalindrome(t)) {
					mx = t.size();
				}
			}

			t = "";
			for (int s = i; s < 100; ++s) {
				t += v[s][j];
				if (t.size() > mx && IsPalindrome(t))
					mx = t.size();
			}
		}
	}
}

int main()
{
	for (int tc = 1; tc <= 10; ++tc) {
		v = vector<vector<char>>(100, vector<char>(100));
		int tmp;
		cin >> tmp;

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> v[i][j];
			}
		}
		Find();
		cout << "#" << tmp << " " << mx << "\n";
		mx = 0;
	}
}