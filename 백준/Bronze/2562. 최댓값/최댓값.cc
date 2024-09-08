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
	int max = -1;
	int rec;
	for (int i = 1; i <= 9; ++i) {
		int k;
		cin >> k;
		if (k > max) {
			max = k;
			rec = i;
		}
	}
	cout << max << "\n" << rec;
}
