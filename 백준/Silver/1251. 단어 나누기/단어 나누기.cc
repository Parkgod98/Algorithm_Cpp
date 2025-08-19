#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;

int main() {
	cin >> s;
	int sz = s.size();

	string res = "";
	for (int i = 1; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j);
				reverse(a.begin(), a.end());
				reverse(b.begin(), b.end());
				reverse(c.begin(), c.end());
				string ns = a + b + c;
				if (res.empty()) {
					res = ns;
				}
				else {
					//cout << res << "\n";
					for (int d = 0; d < sz; ++d) {
						if (res[d] == ns[d])
							continue;
						if (res[d] > ns[d]) {
							res = ns;
							break;
						}
						else
							break;
					}
				}
		}
	}

	cout << res << "\n";

}