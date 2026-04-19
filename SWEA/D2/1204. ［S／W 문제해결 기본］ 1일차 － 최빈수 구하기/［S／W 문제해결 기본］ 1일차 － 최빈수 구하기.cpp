#include<iostream>
using namespace std;

int sc[101];
int T;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int t;
		cin >> t;

		for (int i = 0; i <= 100; ++i)
			sc[i] = 0;
		for (int i = 0; i < 1000; ++i) {
			int n;
			cin >> n;
			sc[n]++;
		}

		int mx = -1;
		int res = -1;
		for (int i = 0; i <= 100; ++i) {
			if (mx <= sc[i]) {
				mx = sc[i];
				res = i;
			}
		}

		cout << "#" << tc << " " << res << "\n";
	}

}