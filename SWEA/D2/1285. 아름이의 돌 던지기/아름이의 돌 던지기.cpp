#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {

		int k;
		cin >> k;

		int mx = 100001;
		int cnt = 0;
		for(int i = 0; i < k; ++i) {
			int cur;
			cin >> cur;

			if(cur < 0)
				cur *= -1;
			if(mx > cur) {
				mx = cur;
				cnt = 1;
			}
			else if(mx == cur)
				++cnt;
		}

		cout << "#" << tc << " " << mx << " " << cnt << "\n";
	}

}