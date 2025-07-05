#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int n, m;
typedef long long ll;
int count_k(int n, int k) {

	int cnt = 0;
	for (ll i = k; i <= n; i *= k) {
		cnt += n / i;
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	int two, five;
	two = five = 0;

	two = count_k(n, 2) - count_k(n - m, 2) - count_k(m,2);
	five = count_k(n, 5) - count_k(n - m, 5) - count_k(m, 5);

	cout << min(two, five) << "\n";
}