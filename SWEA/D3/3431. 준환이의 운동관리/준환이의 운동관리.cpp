#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int L, U, X;
		cin >> L >> U >> X;
		
		int res = 0;
		if (X >= L && X <= U)
			res = 0;
		else if (X < L)
			res = L - X;
		else if (X > U)
			res = -1;

		cout << "#" << tc << " " << res << "\n";
	}
}