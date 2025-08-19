#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, M, J;

int main() {
	cin >> N >> M;
	int s = 1;
	int e = s + M; // e는 포함을 못함.

	cin >> J;
	int res = 0;
	for (int i = 0; i < J; ++i) {
		int apple;
		cin >> apple;
		if (s <= apple && apple < e)
			continue;
		else if (apple < s) {
			res += (s - apple);
			e -= (s - apple);
			s = apple;
		}
		else if (apple >= e) {
			res += (apple - e + 1);
			s += (apple - e + 1);
			e = apple + 1;
		}
	}
	cout << res << "\n";
}