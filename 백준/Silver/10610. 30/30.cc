#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
	string N;
	cin >> N;
	sort(N.begin(), N.end(),greater<int>());

	int sum = 0;
	for (int i = 0; i < N.size(); ++i) {
		sum += (N[i] - '0');
	}
	if (sum % 3 == 0 && N[N.size() - 1] == '0') {
		cout << N << "\n";
	}
	else
		cout << -1 << "\n";
}
