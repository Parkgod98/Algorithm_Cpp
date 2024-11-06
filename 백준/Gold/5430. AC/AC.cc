#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string func;
		cin >> func;

		int n;
		cin >> n;
		string num;
		cin >> num;

		int error_flag = 0;
		vector<int> v;
		int len = num.length();
		int s = 0,e = 0;
		while (n != 0 && s < len) {
			while (s < len && !isdigit(num[s]))
				s++;
			e = s;
			while (e < len && isdigit(num[e]))
				e++;
			v.push_back(stoi(num.substr(s, e - s)));
			s = e = e + 1;
		}
		int r_count = 0;
		int d_count = 0;
		for (char c : func) {
			if (c == 'D')
				d_count++;
		}
		if (d_count > n) {
			cout << "error" << "\n";
			continue;
		}
		for (char c : func) {
			if (c == 'R')
				r_count++;
			else if (c == 'D') {
				if (r_count % 2 == 0)
					v.erase(v.begin());
				else
					v.erase(v.end() - 1);
			}
		}
		if(r_count%2)
			reverse(v.begin(),v.end());
		cout << "[";
		for (int j = 0; j < v.size(); ++j) {
			if (j != v.size() - 1)
				cout << v[j] << ",";
			else
				cout << v[j];
		}
		cout << "]" << "\n";

	}
}
