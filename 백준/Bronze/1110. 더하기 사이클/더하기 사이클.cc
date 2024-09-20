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

int part_sum(int n)
{
	if (n < 10)
		return n;

	int sum = n / 10 + n % 10;
	return sum;
}

int main()
{
	int n;
	cin >> n;

	int target = n;
	int count = 0;
	while (1) {
		int k = n;
		if (n < 10)
			n *= 10;
		int sum = part_sum(n);
		int num = (k % 10) * 10 + sum % 10;
		count++;
		if (target == num)
			break;
		n = num;
	}
	cout << count;

}