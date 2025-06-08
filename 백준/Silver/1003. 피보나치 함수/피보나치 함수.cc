#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	vector<long long> fibo(41);
	fibo[0] = 0;
	fibo[1] = fibo[2] = 1;

	for (int i = 3; i <= 40; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		if (N >= 3)
			cout << fibo[N - 2] + fibo[N - 3] << " " << fibo[N] << "\n";
		else if (N == 0)
			cout << "1 0\n";
		else if (N == 1)
			cout << "0 1\n";
		else if (N == 2)
			cout << "1 1\n";
		else
			cout << "1 2\n";
	}
}