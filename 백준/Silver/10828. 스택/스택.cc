#define _crt_secure_no_warnings
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

//ios_base::sync_with_stdio(false);
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

typedef long long ll;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		string t;
		getline(cin, t);
		string a = t.substr(0, 4);
		if (t.substr(0, 4) == "push")
			v.push_back(stoi(t.substr(5)));
		else if (t == "top") {
			if (v.size() == 0)
				cout << -1 << "\n";
			else
				cout << v[v.size() - 1] << "\n";
		}
		else if (t == "pop") {
			if (v.size()) {
				int k = v[v.size() - 1];
				v.pop_back();
				cout << k << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (t == "size")
			cout << v.size() << "\n";
		else if (t == "empty") {
			if (v.size())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
	}
}
