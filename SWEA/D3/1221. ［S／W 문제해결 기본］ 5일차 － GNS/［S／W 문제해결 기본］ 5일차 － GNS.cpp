#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
string arr[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		string a, b;
		cin >> a >> b;

		int n = stoi(b);
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			
			if (s == "ZRO") {
				v[i] = 0;
			}
			else if (s == "ONE") {
				v[i] = 1;
			}
			else if (s == "TWO") {
				v[i] = 2;
			}
			else if (s == "THR") {
				v[i] = 3;
			}
			else if (s == "FOR") {
				v[i] = 4;
			}
			else if (s == "FIV") {
				v[i] = 5;
			}
			else if (s == "SIX") {
				v[i] = 6;
			}
			else if (s == "SVN") {
				v[i] = 7;
			}
			else if (s == "EGT") {
				v[i] = 8;
			}
			else if (s == "NIN") {
				v[i] = 9;
			}
		}
		sort(v.begin(), v.end());

		cout << "#" << tc << " " << "\n";
		for (int i = 0; i < n; ++i) {
			switch (v[i]) {
			case 0:
				cout << "ZRO" << " ";
				break;
			case 1:
				cout << "ONE" << " ";
				break;
			case 2:
				cout << "TWO" << " ";
				break;
			case 3:
				cout << "THR" << " ";
				break;
			case 4:
				cout << "FOR" << " ";
				break;
			case 5:
				cout << "FIV" << " ";
				break;
			case 6:
				cout << "SIX" << " ";
				break;
			case 7:
				cout << "SVN" << " ";
				break;
			case 8:
				cout << "EGT" << " ";
				break;
			case 9:
				cout << "NIN" << " ";
				break;
			}
		}
		cout << "\n";

	}
}