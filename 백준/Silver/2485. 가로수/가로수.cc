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

	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	vector<int> p_minus;
	for (int i = 1; i < N; ++i) {
		p_minus.push_back(v[i]-v[i-1]);
	}

	int gcd = p_minus[0];
	for (int i = 1; i < p_minus.size(); ++i) {
		gcd = GetGCD(gcd, p_minus[i]);
	}

	int res = 0;
	for (int i = 0; i < p_minus.size(); ++i) {
		res += p_minus[i] / gcd  -1;
	}

	cout << res << "\n";
}