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


int main()
{
	vector<int> coin = { 500,100,50,10,5,1 };

	int n;
	cin >> n;
	n = 1000 - n;

	int res = 0;
	for (int i = 0; i < coin.size(); ++i) {
		res += n / coin[i];
		n %= coin[i];
	}

	cout << res;
}