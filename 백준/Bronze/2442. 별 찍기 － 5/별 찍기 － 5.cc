//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int s = 0; s < n - i - 1; ++s)
			cout << " ";
		for (int k = 0; k < 2*i + 1; ++k)
			cout << "*";
		cout << endl;
	}
}
	
