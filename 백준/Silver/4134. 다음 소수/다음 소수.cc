#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;

bool IsPrime(long long n) {
	
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n%i == 0)
			return false;
	}
	return true;
}

long long GetPrime(long long n) {

	while (!IsPrime(n)) {
		n++;
	}
	return n;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		ll n;
		cin >> n;

		cout << GetPrime(n) << "\n";
	}
}