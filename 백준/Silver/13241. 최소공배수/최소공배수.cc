#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
typedef long long ll;
long long GetGCD(long long a, long long b) {

	while (a%b != 0) {
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

ll GetLCM(ll a, ll b) {

	return a * b / GetGCD(a, b);
}

int main() {
	ll a, b;
	cin >> a >> b;

	cout << GetLCM(a, b) << "\n";
}