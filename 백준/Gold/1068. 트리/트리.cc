#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

void Remove(vector<int>& v, int parent)
{
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == parent) {
			Remove(v, i);
			v[i] = -2;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v[i] = k;
	}

	int tar;
	cin >> tar;
	v[tar] = -2;
	Remove(v, tar);

	int count = 0;
	int flag = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == -2)
			continue;
		for (int j = 0; j < v.size(); ++j) {
			if (i == v[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			count++;
		}
		flag = 0;
	}
	cout << count;
}
