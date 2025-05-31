#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;

	int arr[21] = { 0 };
	for (int i = 0; i < M; ++i) {
		string com;
		cin >> com;
		int x;
		if (com == "add") {
			cin >> x;
			arr[x] = 1;
		}
		else if (com == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		else if (com == "check") {
			cin >> x;
			if (arr[x] == 1) {
				cout << 1 << "\n";
			}
			else
				cout << "0\n";
		}
		else if (com == "toggle") {
			cin >> x;
			if (arr[x] == 1) {
				arr[x] = 0;
			}
			else
				arr[x] = 1;
		}
		else if (com == "all") {
			for (int i = 1; i <= 20; ++i)
				arr[i] = 1;
		}
		else if (com == "empty") {
			for (int i = 1; i <= 20; ++i)
				arr[i] = 0;
		}

	}
}