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
	int arr[31] = { 0 };
	for (int i = 0; i < 28; ++i) {
		int n;
		cin >> n;
		arr[n] = 1;
	}
	for (int i = 1; i <= 30; ++i) {
		if (arr[i] == 0)
			cout << i << "\n";
	}
}
