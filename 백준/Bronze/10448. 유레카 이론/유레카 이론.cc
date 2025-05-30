#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	vector<int> tri;

	int s = 1;
	while (1) {
		int k = (s)*(s + 1) / 2;
		if (k <= 1000) {
			tri.push_back(k);
		}
		else
			break;
		++s;
	}

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		int n;
		cin >> n;

		bool Exit = false;
		for (int i = 0; i < tri.size(); ++i) {
			for (int j = 0; j < tri.size(); ++j) {
				for (int k = 0; k < tri.size(); ++k) {
					if (tri[i] + tri[j] + tri[k] == n) {
						cout << 1 << "\n";
						Exit = true;
						break;
					}
				}
				if (Exit)
					break;
			}
			if (Exit)
				break;
		}
		if (!Exit) {
			cout << 0 << "\n";
		}
	}
	
}