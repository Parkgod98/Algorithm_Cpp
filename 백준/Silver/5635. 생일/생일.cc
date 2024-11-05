#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	if (get<3>(a) < get<3>(b))
		return true;
	else if (get<3>(a) > get<3>(b))
		return false;
	else {
		if (get<2>(a) < get<2>(b))
			return true;
		else if (get<2>(a) > get<2>(b))
			return false;
		else {
			return get<1>(a) < get<1>(b);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	
	vector<tuple<string, int, int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		string s;
		int d, m, y;
		cin >> s >> d >> m >> y;
		v[i] = make_tuple(s, d, m, y);
	}
	sort(v.begin(), v.end(),compare);

	cout << get<0>(v[v.size() - 1])  << "\n" << get<0>(v[0]);
}
