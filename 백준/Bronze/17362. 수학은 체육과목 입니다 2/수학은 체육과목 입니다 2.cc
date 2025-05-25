#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int res = n % 8;
	if (res >0 && res <= 5)
		cout << res;
	else {
		if (res == 6)
			cout << 4;
		else if (res == 7)
			cout << 3;
		else if (res == 0)
			cout << 2;

	}
}