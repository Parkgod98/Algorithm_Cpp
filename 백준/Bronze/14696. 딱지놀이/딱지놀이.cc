#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		vector<int> a(5);
		vector<int> b(5);
		int tmp;
		string a1, b1;
		cin >> tmp;
		getline(cin, a1);
		cin >> tmp;

		getline(cin, b1);

		for (int j = 0; j < a1.size(); ++j) {
			if (isdigit(a1[j])) {
				a[a1[j] - '0']++;
			}
		}
		for (int j = 0; j < b1.size(); ++j) {
			if (isdigit(b1[j])) {
				b[b1[j] - '0']++;
			}
		}

		char res = 'D';
		bool flag = false;
		for (int i = 4; i >= 1; --i) {
			if (a[i] < b[i]) {
				res = 'B';
				break;
			}
			else if (a[i] > b[i]) {
				res = 'A';
				break;
			}
		}
		cout << res << "\n";
	}

}