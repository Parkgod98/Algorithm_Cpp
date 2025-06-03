#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int K;
	cin >> K;

	int a, b;
	a = 1;
	b = 0;
	for (int i = 0; i < K; ++i) {
		int n_a = b;
		int n_b = b + a;
		a = n_a;
		b = n_b;
	}
	cout << a << " " << b << "\n";


}