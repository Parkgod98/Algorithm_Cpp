#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int mn_cnt = b.size();

	for (int i = 0; i <= b.size() - a.size(); ++i) {
		int cnt = 0;
		for (int j = i; j < i+a.size(); ++j) {
			if (a[j - i] != b[j]) {
				++cnt;
			}
		}
		if (mn_cnt > cnt)
			mn_cnt = cnt;
	}

	cout << mn_cnt << "\n";
}