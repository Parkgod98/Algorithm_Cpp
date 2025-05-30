#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;

	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'L')
			++cnt;
	}
	if (cnt >= 4) {
		N -= (cnt / 2 - 1);
	}
	cout << N << "\n";

}