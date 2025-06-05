#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	int N, kim, lim;
	cin >> N >> kim >> lim;

	int cnt = 0;
	while (N != 0) {
		++cnt;
		N /= 2;
		kim = (double)kim / 2.0 + 0.5;
		lim = (double)lim / 2.0 + 0.5;
		if (kim == lim) {
			cout << cnt << "\n";
			break;
		}
	}
}