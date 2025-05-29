#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;

	long long res = (long long)(n - 2)*(n - 1)*n / 6;
	cout << res << "\n" << 3 << "\n";

}