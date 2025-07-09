#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, x, y;

int GetGCD(int a, int b) {
	while (a%b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int GetLCM(int a, int b) {

	return (a*b) / GetGCD(a, b);
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> M >> N >> x >> y;

		int lcm = GetLCM(M, N);

		bool Find = false;
		int res = 0;
		for (int i = x; i <= lcm; i += M) {
			res = i;
			res %= N;
			if (res == 0)
				res = N;
			if (res == y) {
				res = i;
				Find = true;
				break;
			}
		}
		if (Find)
			cout << res << "\n";
		else
			cout << -1 << "\n";
	}

}