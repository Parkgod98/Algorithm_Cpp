#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int test_case;
	int T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case) {
		int n;
		list<int> ll;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			int s;
			cin >> s;
			ll.push_back(s);
		}
		int com_n;
		cin >> com_n;

		for(int i = 0; i < com_n; ++i) {
			char c;
			cin >> c;
			if(c == 'I') {
				int x, y;
				cin >> x >> y;
				list<int> tmp;
				for(int k = 0; k < y; ++k) {
					int nn;
					cin >> nn;
					tmp.push_back(nn);
				}
				auto it = ll.begin();
				for(int j = 0; j < x; ++j)
					it++;
				ll.insert(it, tmp.begin(), tmp.end());
			}
			else if(c == 'D') {
				int x, y;
				cin >> x >> y;
				auto s = ll.begin();
				
				for(int j = 0; j < x; ++j)
					s++;
				for(int j = 0; j < y; ++j) {
					s = ll.erase(s);
				}
			}
			else if(c == 'A') {
				int y;
				cin >> y;
				for(int j = 0; j < y; ++j) {
					int nn;
					cin >> nn;
					ll.push_back(nn);
				}
			}
		}
		cout << "#" << test_case << " ";
		for(int i = 0; i < 10; ++i) {
			cout << ll.front() << " ";
			ll.pop_front();
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}