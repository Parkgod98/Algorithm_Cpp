#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;

	if (N == 1)
		cout << "*";
	else {
		for (int i = 1; i <= N * 2; ++i) {
			if (i % 2 == 1) {
				for (int j = 0; j < N; ++j) {
					if (j % 2 == 0)
						cout << "*";
					else
						cout << " ";
				}
			}
			else {
				for (int j = 0; j < N; ++j) {
					if (j % 2 == 0)
						cout << " ";
					else
						cout << "*";
				}
			}
			cout << "\n";
		}
	}
}