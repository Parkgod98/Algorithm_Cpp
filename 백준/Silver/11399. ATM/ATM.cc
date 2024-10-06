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

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i + 1];
	}
	sort(v.begin(), v.end());

	vector<int> pfix_sum(n + 1);
	
	for (int i = 0; i < n; ++i) {
		pfix_sum[i + 1] = v[i + 1] + pfix_sum[i];
	}

	int sum = 0;
	for (int i : pfix_sum)
		sum += i;
	cout << sum;
}
