#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int PartSum(int n)
{
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int main()
{
	vector<bool> v(10001, true);

	int size = v.size();

	for (int i = 1; i < size; ++i) {
		int k = PartSum(i) +i;
		if (k <= 10000)
			v[k] = false;
	}
	for (int i = 1; i < size; ++i) {
		if (v[i] == true)
			cout << i << "\n";
	}
}
