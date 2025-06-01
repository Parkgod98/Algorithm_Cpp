#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;

	int e, s, m;
	e = s = m = 1;
	int year = 1;
	while (e != E || s != S || m != M) {
		++e;
		++s;
		++m;
		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
		++year;
	}
	cout << year << "\n";
}