#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
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
	while (1) {
		int n;
		cin >> n;
		if (n == -1)
			break;

		int sum = 1;
		vector<int> v(1,1);
		for (int i = 2; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				sum += i;
				sum += (n / i);
				v.push_back(i);
				v.push_back(n / i);
			}
		}
		if (sum == n) {
			sort(v.begin(), v.end());
			cout << n << " = ";
			for (int i = 0; i < v.size(); ++i) {
				cout << v[i];
				if (i != v.size() - 1)
					cout << " + ";
			}
			cout << "\n";
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
	}
}
