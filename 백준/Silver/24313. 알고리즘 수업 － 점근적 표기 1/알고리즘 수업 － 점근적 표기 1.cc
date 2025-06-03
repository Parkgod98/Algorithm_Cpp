#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int a1, a0;
	cin >> a1 >> a0;

	int c, n0;
	cin >> c >> n0;


	if (c*n0 >= a1 * n0 + a0 && a1 <= c) {
		cout << 1;
	}
	else
		cout << 0;
}