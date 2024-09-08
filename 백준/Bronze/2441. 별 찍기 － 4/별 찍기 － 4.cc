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

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < i; ++k)
			cout << " ";
		for (int j = 0; j < n - i; ++j) {
			cout << "*";
		}
		cout << endl;
	}
}
	
