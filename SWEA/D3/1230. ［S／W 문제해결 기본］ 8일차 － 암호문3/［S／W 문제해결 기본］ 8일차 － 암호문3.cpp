#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; ++tc) {
		int N;
		cin >> N;

		list<int> v;
		for (int i = 0; i < N; ++i) {
			int k;
			cin >> k;
			v.push_back(k);
		}

		int c_num;
		cin >> c_num;
		for (int i = 0; i < c_num; ++i) {
			char com;
			cin >> com;
			
			if (com == 'I') {
				int x, y;
				cin >> x >> y;
				auto it = v.begin();
				advance(it, x);
				for (int j = 0; j < y; ++j) {
					int k;
					cin >> k;
					it = v.insert(it, k);
					it++;
				}
			}
			else if (com == 'D') {
				int x, y;
				cin >> x >> y;

				auto it = v.begin();
				advance(it, x);
				for (int j = 0; j < y; ++j) {
					it = v.erase(it);
				}
			}
			else if (com == 'A') {
				int n;
				cin >> n;
				for (int j = 0; j < n; ++j) {
					int k;
					cin >> k;
					v.push_back(k);
				}
			}
		}

		auto it = v.begin();
		cout << "#" << tc << " ";
		for (int i = 0; i < 10; ++i) {
			cout << *it << " ";
			it++;
		}
		cout << "\n";
	}
}