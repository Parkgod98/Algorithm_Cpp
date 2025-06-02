#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int one, zero,total;
	one = zero = total = 0;

	string S;
	cin >> S;

	char pc = S[0];
	for (int i = 0; i < S.size(); ++i) {
		if (pc != S[i]) {
			total++;
		}
		if (pc == '0' && S[i] == '1') {
			zero++;
		}
		pc = S[i];
	}
	if (S[S.size() - 1] == '0') {
		zero++;
	}
	one = total + 1 - zero;
	cout << min(one, zero) << "\n";
}