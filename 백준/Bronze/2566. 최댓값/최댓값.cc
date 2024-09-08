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
	vector<vector<int>> v;
	int max = -1;
	int x, y;
	for (int i =1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			int n;
			cin >> n;
			if (max < n) {
				max = n;
				x = i;
				y = j;
			}
		}
	}
	cout << max << "\n" << x << " " << y << endl;
}
	
