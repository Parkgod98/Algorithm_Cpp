//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	int n;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < 5; ++i) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	
	int sum = 0;
	for (int i : v) {
		if (n == i)
			sum += 1;
	}

	cout << sum << "\n";
}
