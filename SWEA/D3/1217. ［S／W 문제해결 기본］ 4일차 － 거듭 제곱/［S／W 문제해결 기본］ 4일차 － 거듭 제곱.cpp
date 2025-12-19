#include <iostream>
using namespace std;

int Power(int a, int b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		return Power(a*a, b / 2);
	}
	return a * Power(a*a, b/2);
}

int main(){


	for (int tc = 1; tc <= 10; ++tc) {
		int k;
		cin >> k;
		int a, b;
		cin >> a >> b;
		cout << "#" << tc << " " << Power(a, b) << "\n";
	}
}
