#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int main() {
	list<pair<int,int>> li;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		li.push_back({ i + 1,n });
	}


	auto it = li.begin();
	while (!li.empty()) {
		cout << it->first << " ";
		int n = it->second;
		it = li.erase(it);
		if (li.empty())
			break;
		if (n > 0) {
			if (it == li.end())
				it = li.begin();
			for (int i = 0; i < n-1; ++i) {
				it++;
				if (it == li.end())
					it = li.begin();
			}
		}
		else {
			for (int i = 0; i < -n; ++i) {
				if (it == li.begin()) {
					it = li.end();
					it--;
				}
				else
					it--;
			}
		}
	}

}  