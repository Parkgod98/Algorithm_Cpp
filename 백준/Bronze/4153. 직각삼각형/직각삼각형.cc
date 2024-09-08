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
	while (1) {
		vector<int> v;
		for (int i = 0; i < 3; ++i) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		if (v[0] == v[1] && v[1] == v[2] && v[0] == 0)
			break;
		sort(v.begin(), v.end());
		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}
	
