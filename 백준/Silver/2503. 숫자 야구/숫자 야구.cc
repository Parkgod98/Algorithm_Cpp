#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<bool> is_answer(1000, true);
	for (int i = 0; i < 1000; ++i) {
		string tmp = to_string(i);
		if (i < 100 || tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2] || tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			is_answer[i] = false;
	}


	for (int i = 0; i < n; ++i) {
		int a, s, b;
		cin >> a >> s >> b;
		for (int j = 0; j < 1000; ++j) {
			if (is_answer[j]) {
				string ans = to_string(j);
				string num = to_string(a);
				int strike, ball;
				strike = ball = 0;
				for (int r = 0; r < 3; ++r) {
					for (int c = 0; c < 3; ++c) {
						if (r == c && ans[r] == num[c])
							strike++;
						else if (r != c && ans[r] == num[c])
							ball++;
					}
				}
				if (strike != s || ball != b)
					is_answer[j] = false;
			}
		}
	}

	int count = 0;
	for (bool b : is_answer)
		if (b)
			count++;
	cout << count;
}
