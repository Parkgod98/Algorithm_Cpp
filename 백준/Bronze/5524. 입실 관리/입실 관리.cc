#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		for (char &c : s) {
			c = tolower(c);
			cout << c;
		}
		cout << "\n";
	}
}