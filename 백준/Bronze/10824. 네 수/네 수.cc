#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string a, b, c, d;

	cin >> a >> b >> c >> d;

	long long res = stoll(a + b) + stoll(c + d);
	cout << res << "\n";

}