#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	for (int tc = 1; tc <= 10; ++tc) {
		int n;
		cin >> n;
		vector<vector<int>> v(100, vector<int>(100, 0));

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j)
				cin >> v[i][j];
		}

		int res = 0;
		for (int j = 0; j < 100; ++j) {
			bool f1;
			f1 = false;
			for (int i = 0; i < 100; ++i) {
				if (v[i][j] == 1)
					f1 = true;
				else if (f1 && v[i][j] == 2) {
					f1 = false;
					++res;
				}
			}
		}
		cout << "#" << tc << " " << res << "\n";
	}
}