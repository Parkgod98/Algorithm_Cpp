#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int s, k, h;
	cin >> s >> k >> h;

	int sum = s + k + h;

	if (sum >= 100)
		cout << "OK";
	else {
		int mn = min(min(s, k), h);
		if (mn == s) {
			cout << "Soongsil";
		}
		else if (mn == k)
			cout << "Korea";
		else
			cout << "Hanyang";
	}
}