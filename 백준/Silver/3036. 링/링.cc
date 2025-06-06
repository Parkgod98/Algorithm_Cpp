#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
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
	int N;
	cin >> N;

	int standard;
	cin >> standard;
	for (int i = 0; i < N - 1; ++i) {
		int n;
		cin >> n;

		int gcd = GetGCD(standard, n);
		cout << standard / gcd << "/" << n / gcd << "\n";
	}
}