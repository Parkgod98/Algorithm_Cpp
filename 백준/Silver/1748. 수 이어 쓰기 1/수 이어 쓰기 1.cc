#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	int res = 0;

	for (int i = 1; i <= N; i *= 10) {
		res += N - i + 1;
	}

	cout << res;
}
