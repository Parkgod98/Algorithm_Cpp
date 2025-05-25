#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

	for (int i = 0; i < 3; ++i) {
		int h1, m1, s1, h2, m2, s2;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		int t_sec = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);

		int h, m, s;
		h = t_sec / 3600;
		t_sec %= 3600;
		m = t_sec / 60;
		t_sec %= 60;
		s = t_sec;

		cout << h << " " << m << " " << s << "\n";
	}
}