#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; ++i) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
}