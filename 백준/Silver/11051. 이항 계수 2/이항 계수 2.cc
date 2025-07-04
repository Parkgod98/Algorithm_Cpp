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
int N, K;

vector<vector<string>> v;

string Add(string &a, string &b) {
	string s1, s2;
	if (a.size() <= b.size()) {
		s1 = a;
		s2 = b;
	}
	else {
		s1 = b;
		s2 = a;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	string res = "";
	int carry = 0;
	for (int i = 0; i < s1.size(); ++i) {
		int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
		carry = sum / 10;
		sum %= 10;

		res.push_back((sum+'0'));
	}
	for (int i = s1.size(); i < s2.size(); ++i) {
		int sum = (s2[i] - '0') + carry;
		carry = sum / 10;
		sum %= 10;
		res.push_back((sum+'0'));
	}
	if (carry)
		res.push_back('1');
	reverse(res.begin(), res.end());

	res = to_string(stoi(res) % 10007);

	return res;
}

int main() {
	cin >> N >> K;

	v = vector<vector<string>>(N + 1, vector<string>(N + 1));
	v[0][0] = v[1][0] = v[1][1] = "1";

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i)
				v[i][j] = "1";
			else {
				v[i][j] = Add(v[i - 1][j - 1], v[i - 1][j]);
			}
		}
	}

	cout << v[N][K] << "\n";
}