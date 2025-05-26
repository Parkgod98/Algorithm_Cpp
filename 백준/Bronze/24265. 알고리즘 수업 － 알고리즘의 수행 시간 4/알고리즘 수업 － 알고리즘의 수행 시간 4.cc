#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long sum = (long long)(n - 1 + 1) *(n - 1) / 2;
	
	cout << sum << "\n" << 2 << "\n";
}