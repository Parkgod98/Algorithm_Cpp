#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;
long long S;

int main() {
	cin >> S;

	long long n = 1;
	while (1) {
		long long sum = ((n*n) + n) / 2;
		if (sum > S) {
			break;
		}
		n++;
	}

	cout << n-1 << "\n";
}