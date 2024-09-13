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

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	long long max = 0;
	for (int i = 0; i < k; ++i)
		max += v[i];

	int i, j;
	i = 0;
	j = k-1;
	int sum = max;
	while (j < n-1) {
 		i++;
		j++;
		sum = sum - v[i - 1] + v[j];
		if (sum > max)
			max = sum;
	}
	cout << max;

}