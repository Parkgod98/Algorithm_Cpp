#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int T;
	cin >> T;

	int mx = 0;
	string s_mx = "";
	for (int tc = 0; tc < T; ++tc) {
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			string s;
			int n;
			cin >> s >> n;

			if (n > mx) {
				mx = n;
				s_mx = s;
			}
		}
		cout << s_mx << "\n";
	}
}