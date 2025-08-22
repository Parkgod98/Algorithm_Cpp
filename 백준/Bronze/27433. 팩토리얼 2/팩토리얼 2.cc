#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long n = 1;
int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		n *= i;
	}
	cout << n << "\n";
} 