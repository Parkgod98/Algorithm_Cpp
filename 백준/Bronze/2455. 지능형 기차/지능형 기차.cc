#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int sum = 0;
	int mx = 0;
	for (int i = 0; i < 4; ++i) {
		int out, in;
		cin >> out >> in;

		sum -= out;
		sum += in;

		if (sum > mx)
			mx = sum;
	}
	cout << mx << "\n";
}