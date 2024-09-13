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
#define N 9
int main()
{
	vector<int> v;
	int total = 0;
	for (int i = 0; i < 9; ++i) {
		int n;
		cin >> n;
		v.push_back(n);
		total += n;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j) {
			if (total - v[i] - v[j] == 100) {
				for (int k = 0; k < N; ++k)
					if (k != i && k != j)
						cout << v[k] << "\n";
				return 0;
			}
		}
}