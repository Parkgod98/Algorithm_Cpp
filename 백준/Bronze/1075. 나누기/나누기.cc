#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	string N;
	int F;
	cin >> N >> F;

	for (char c1 = '0'; c1 <= '9'; ++c1) {
		for (char c2 = '0'; c2 <= '9'; ++c2) {
			string temp = to_string(c1-'0') + to_string(c2-'0');
			N.pop_back();
			N.pop_back();
			N += temp;

			if (stoi(N) % F == 0) {
				cout << temp << "\n";
				return 0;
			}

		}
	}
}