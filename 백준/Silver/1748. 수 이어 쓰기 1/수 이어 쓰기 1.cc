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

	int mask = 9;
	int weight = 1;

	int i;
	for (i = 10; i <= N; i *= 10) {
		res += (mask*weight);
		mask *= 10;
		++weight;
	}

	i /= 10;
	int remain = N - i + 1;
	res += remain * weight;

	cout << res;
}
