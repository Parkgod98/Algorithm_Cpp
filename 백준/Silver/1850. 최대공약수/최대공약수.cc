#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long GetGCD(long long A, long long B) {
	while (A%B != 0) {
		long long tmp = A % B;
		A = B;
		B = tmp;
	}
	return B;
}
int main(void) {

	long long A, B;
	cin >> A >> B;

	long long gcd = GetGCD(A, B);
	for (int i = 0; i < gcd; ++i)
		cout << 1;
}
