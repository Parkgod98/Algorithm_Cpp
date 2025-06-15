#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int GetGCD(int a, int b) {

	while (a%b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return b;
}
int main() {
	int a, b,c,d;
	cin >> a >> b >> c >> d;

	int A = d * a + b * c;
	int B = b * d;

	int gcd = GetGCD(A, B);
	cout << A / gcd << " " << B / gcd << "\n";

}  