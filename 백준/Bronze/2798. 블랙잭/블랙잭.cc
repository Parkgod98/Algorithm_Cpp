//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{	
	int n, m;
	cin >> n >> m;

	vector<int> c;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		c.push_back(k);
	}
	sort(c.begin(), c.end());
	int min_sum = c[0] + c[1] + c[2];
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				int sum = c[i] + c[j] + c[k];
				if (sum <= m) {
					if (abs(min_sum - m) >= abs(sum - m))
						min_sum = sum;
				}
				else
					break;
			}
		}
	}

	cout << min_sum;
}