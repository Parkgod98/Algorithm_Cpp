#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int a, int b, int c, int d) {
	int answer = 0;
	vector<int> v = { a,b,c,d };
	sort(v.begin(), v.end());
	map<int,int> mp;
	for (int i = 0; i < 4; ++i) {
		if (mp[v[i]])
			mp[v[i]] += 1;
		else
			mp[v[i]] = 1;
	}
	if (mp.size() == 1)
		return 1111 * a;
	else if (mp.size() == 2) {
		int p, q;
		p = q = -1;
		for (auto& it : mp) {
			if (it.second == 3)
				p = it.first;
			else if (it.second == 1)
				q = it.first;
		}
		if (p == -1) {
			v.erase(unique(v.begin(), v.end()), v.end());
			return (v[0] + v[1]) * abs(v[0] - v[1]);;
		}
		return pow((10*p + q),2);
	}
	else if (mp.size() == 3) {
		int ans = 1;
		for (auto& it : mp) {
			if (it.second == 1)
				ans *= it.first;
		}
		return ans;
	}
	else {
		return min(min(a, b), min(c, d));
	}
}