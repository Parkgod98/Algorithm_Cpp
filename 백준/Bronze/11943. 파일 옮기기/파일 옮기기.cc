#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int c, d;
	cin >> c >> d;

	cout << min(a + d, b + c);
}