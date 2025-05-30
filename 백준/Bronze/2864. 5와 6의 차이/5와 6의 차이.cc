#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	string a, b;
	cin >> a >> b;

	bool a1, b1;
	a1 = b1 = false;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '5' || a[i] == '6') {
			a1 = true;
			break;
		}
	}

	for (int i = 0; i < b.size(); ++i) {
		if (b[i] == '5' || b[i] == '6') {
			b1 = true;
			break;
		}
	}

	int a_min, a_max, b_min, b_max;
	a_min = a_max = stoi(a);
	b_min = b_max = stoi(b);

	if (a1) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '6')
				a[i] = '5';
		}
		a_min = stoi(a);

		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '5') {
				a[i] = '6';
			}
		}
		a_max = stoi(a);
	}
	if (b1) {
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == '6')
				b[i] = '5';
		}
		b_min = stoi(b);

		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == '5') {
				b[i] = '6';
			}
		}
		b_max = stoi(b);
	}

	int mx = a_max + b_max;
	int mn = a_min + b_min;
	cout << mn << " " << mx << "\n";
}