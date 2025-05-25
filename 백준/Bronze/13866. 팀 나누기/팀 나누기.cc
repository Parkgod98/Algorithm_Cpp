#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << abs(a+d-b-c) << "\n";
}