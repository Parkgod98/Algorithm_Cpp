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
	cout << fixed;
	cout.precision(3);

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		int n;
		cin >> n;
		vector<int> v;
		double avg = 0;
		for (int j = 0; j < n; ++j) {
			int k;
			cin >> k;
			v.push_back(k);
			avg += k;
		}
		avg /= n;
		int count = 0;
		for (int j = 0; j < n; ++j) {
			if (v[j] > avg)
				count++;
		}
		avg = ((double)count / n)*100;
		cout << avg << "%\n";
	}
	
}