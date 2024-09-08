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
	int r, w;
	cin >> r >> w;
	vector<vector<int>> a;
	vector<vector<int>> b;

	for (int i = 0; i < r; ++i) {
		vector<int> tmp;
		for (int j = 0; j < w; ++j) {
			int n;
			cin >> n;
			tmp.push_back(n);
		}
		a.push_back(tmp);
	}
	for (int i = 0; i < r; ++i) {
		vector<int> tmp;
		for (int j = 0; j < w; ++j) {
			int n;
			cin >> n;
			tmp.push_back(n);
		}
		b.push_back(tmp);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < w; ++j) {
			a[i][j] += b[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}
	
