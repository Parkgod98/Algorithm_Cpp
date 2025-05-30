#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> fibo(41);
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i <= 40; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n] << " " << n - 2 << "\n";
}