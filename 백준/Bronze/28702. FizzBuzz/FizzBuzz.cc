#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {

	int idx = 0;
	int n = 0;
	for (int i = 0; i < 3; ++i) {
		string s;
		cin >> s;

		if (isdigit(s[0])) {
			idx = i;
			n = stoi(s);
		}
	}
	n += 3 - idx;

	if (n % 3 == 0 && n % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (n % 3 == 0 && n % 5 != 0) {
		cout << "Fizz";
	}
	else if (n % 3 != 0 && n % 5 == 0) {
		cout << "Buzz";
	}
	else
		cout << n;
}