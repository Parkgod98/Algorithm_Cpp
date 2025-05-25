#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int start = 2;
	for (int i = 0; i < N; ++i) {
		start = start + (start - 1);
	}

	cout << start * start << "\n";
}