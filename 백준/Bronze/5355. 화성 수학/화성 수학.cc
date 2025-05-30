#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int T;

	cin >> T;

	cout.precision(2);
	cout << fixed;

	for (int i = 0; i < T; ++i) {
		double n;
		cin >> n;

		string s;
		getline(cin, s);

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ')
				continue;
			else if (s[i] == '@') {
				n *= 3;
			}
			else if (s[i] == '%') {
				n += 5;
			}
			else if (s[i] == '#')
				n -= 7;
		}
		cout << n << "\n";
	}
}