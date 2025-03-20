#include <bits/stdc++.h>
using namespace std;

void PrintV(deque<int>& v, bool f) {
	cout << "[";

	if(!f) {
		for(auto it = v.rbegin(); it != v.rend(); ++it) {
			if(it != v.rend() - 1) {
				cout << *it << ",";
			}
			else
				cout << *it;
		}
	}
	else {
		for(auto it = v.begin(); it != v.end(); ++it) {
			if(it != v.end() - 1) {
				cout << *it << ",";
			}
			else
				cout << *it;
		}
	}
	cout << "]\n";
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		string com;
		cin >> com;

		int n;
		cin >> n;
		string s;
		cin >> s;

		int sum = 0;
		deque<int> v;
		int cnt = 0;
		for(int j = 1; j < s.size(); ++j) {
			if(isdigit(s[j])) {
				sum = sum * 10 + s[j] - '0';
			}
			else {
				if(cnt < n) {
					v.push_back(sum);
					sum = 0;
					++cnt;
				}
			}
		}

		bool IsFront = true;
		bool err = false;
		for(int j = 0; j < com.size(); ++j) {
			if(com[j] == 'R')
				IsFront = !IsFront;
			else if(com[j] == 'D' && v.empty()) {
				err = true;
				break;
			}
			else if(com[j] == 'D' && IsFront) {
				v.pop_front();
			}
			else if(com[j] == 'D' && !IsFront) {
				v.pop_back();
			}
		}
		if(err)
			cout << "error" << "\n";
		else
			PrintV(v,IsFront);
		/*for(int& n : v)
			cout << n << " ";
		cout << "\n";*/
	}
}