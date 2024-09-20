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
	int n;
	cin >> n;
	int k = 2;
	while (n != 1) {
		while (n % k == 0) {
			cout << k << "\n";
			n /= k;
		}
		k++;
	}
}