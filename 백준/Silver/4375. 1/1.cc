#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

typedef long long ll;
int main()
{
	int n;
	while (!(cin >> n).eof()) {
		ll tmp = 1;
		int ret = 1;
		while (1) {
			if (tmp % n == 0) {
				cout << ret << "\n";
				break;
			}
			else {
				ret++;
				tmp = ((tmp % n * 10 % n) % n + 1 % n) % n;
			}
		}

	}
}
