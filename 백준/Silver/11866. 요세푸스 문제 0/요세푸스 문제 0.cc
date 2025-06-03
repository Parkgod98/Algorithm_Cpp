#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	list<int> li;
	for (int i = 1; i <= N; ++i)
		li.push_back(i);

	cout << "<";
	auto it = li.begin();
	while (!li.empty()) {
		for (int i = 0; i < K - 1; ++i) {
			++it;
			if (it == li.end())
				it = li.begin();
		}
		if (!(li.size() == 1)) {
			cout << *it << ", ";
		}
		else
			cout << *it << ">";
		it = li.erase(it);
		if (it == li.end())
			it = li.begin();
	}
}