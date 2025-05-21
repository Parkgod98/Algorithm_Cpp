#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (i % 2)
				sum += i;
			else
				sum -= i;
		}
		cout << "#" << tc << " " << sum << "\n";
	}
}