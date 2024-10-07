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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int Get(int k)
{
	if (k == 0) {
		return 1;
	}
	if (k < 0)
		return 0;
	
	return Get(k - 3) +Get(k - 2) + Get(k - 1);
}


int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		cout << Get(k) << "\n";
	}
}
