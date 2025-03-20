#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		list<char> ll = {};

		auto cur = ll.begin();
		for(int j = 0; j < s.size(); ++j) {
			
			if(s[j] == '<') {

				if(cur != ll.begin())
					--cur;
			}
			else if(s[j] == '>') {
				if(cur != ll.end())
					++cur;
			}
			else if(s[j] == '-') {
				if(cur != ll.begin()) {
					--cur;
					cur = ll.erase(cur);
				}
			}
			else {
				ll.insert(cur, s[j]);
			}
			
		}
		for(auto& c : ll)
			cout << c;
		cout << "\n";
	}
}