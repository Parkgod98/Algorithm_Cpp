#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int mode;
	for (int i = 1; i <= n; ++i) {
		sum += i;
		if (sum >= n) {
			mode = i;
			break;
		}
	}
	int top, bottom;
	if (mode % 2 == 0) {
		int start = sum - mode + 1;
		bottom = mode;
		top = 1;
		while (start != n) {
			bottom--;
			top++;
			start++;
		}
	}
	else {
		int start = sum - mode + 1;
		bottom = 1;
		top = mode;
		while (start != n) {
			bottom++;
			top--;
			start++;
		}
	}
	cout << top << "/" << bottom;

}
