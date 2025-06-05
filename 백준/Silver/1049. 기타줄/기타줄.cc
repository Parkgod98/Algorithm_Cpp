#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int six, one;
	six = one = 1001;
	for (int i = 0; i < M; ++i) {
		int s, o;
		cin >> s >> o;
		if (six > s)
			six = s;
		if (one > o)
			one = o;
	}

	int res;
	if (one * 6 <= six) {
		res = N * one;
	}
	else {
		int res1 = (N / 6 + 1)*six;
		int res2 = (N / 6)*six + (N % 6)*one;
		res = min(res1, res2);
	}

	cout << res << "\n";
}