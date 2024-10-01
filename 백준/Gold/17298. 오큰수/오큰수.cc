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

int a[10000001] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> v(n+1);
	stack<int> s;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		while (!s.empty() && a[s.top()] < a[i]) {
			a[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		a[s.top()] = -1;
		s.pop();
	}
	for (int i : a) {
		if (i != 0)
			cout << i << " ";
	}
	
}
