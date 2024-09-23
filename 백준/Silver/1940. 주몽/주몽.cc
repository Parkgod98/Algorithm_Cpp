//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()



int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k <m)
			v.push_back(k);
	}
	sort(v.begin(), v.end());

	int count = 0;
	int i, j;
	i = 0;
	j = v.size() - 1;

	while (i < j) {
		int sum = v[i] + v[j];
		if (sum == m) {
			count++;
			i++;
			j--;
		}
		else if (sum < m) {
			i++;
		}
		else
			j--;
	}
	cout << count;

}