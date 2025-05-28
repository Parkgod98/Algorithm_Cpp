#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	int res = 0;
	int w = 1;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] >= 'A' && s[i] <= 'F') {
			res += (s[i] - 'A' + 10)*w;
		}
		else {
			res += (s[i] - '0')*w;
		}
		w *= 16;
	}
	cout << res << "\n";
}