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


int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	sort(v.begin(), v.end());

	double sum = 0;
	int standard = (n * 0.15) + 0.5; // 15퍼센트하고 반올림.
	for (int i = standard; i < n - standard; ++i)
		sum += v[i];

	int avg = (sum / (n - 2 * standard)) + 0.5;
	if (n != 0)
		cout << avg << "\n";
	else
		cout << 0 << "\n";
}		