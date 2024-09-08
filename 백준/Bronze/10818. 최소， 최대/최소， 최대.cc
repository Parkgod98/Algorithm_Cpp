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
	
	int max = -1000000;
	int min = 1000000;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k > max)
			max = k;
		if (k < min)
			min = k;
	}
	cout << min << " " << max;
}
