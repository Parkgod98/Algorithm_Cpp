#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {

	for(int tc = 1; tc <= 10; ++tc) {
		int tmp;
		cin >> tmp;

		deque<int> q;
		for(int i = 0; i < 8; ++i) {
			int n;
			cin >> n;
			q.push_back(n);
		}

		int init = 1;
		while(1) {
			int n = q.front();
			n = n - init;
			if(n <= 0) {
				n = 0;
				q.pop_front();
				q.push_back(n);
				break;
			}
			init++;
			if(init == 6)
				init = 1;
			q.pop_front();
			q.push_back(n);
		}
		cout << "#" << tc << " ";
		while(!q.empty()) {
			cout << q.front() << " ";
			q.pop_front();
		}
		cout << "\n";
	}
}