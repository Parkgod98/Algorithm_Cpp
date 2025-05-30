#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

typedef long long ll;

int main() {
	ll N;
	cin >> N;

	ll sum = 0;

	for (int i = 1; i < N; ++i) {
		sum += N * i + i;
	}
	cout << sum << "\n";
}